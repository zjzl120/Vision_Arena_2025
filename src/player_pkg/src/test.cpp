#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.hpp>
#include <rclcpp/rclcpp.hpp>
#include "sensor_msgs/msg/image.hpp"
#include <referee_pkg/msg/multi_object.hpp>
#include <referee_pkg/msg/object.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <std_msgs/msg/header.hpp>
#include <rclcpp/timer.hpp> 
#include <memory>

using namespace std;
using namespace rclcpp;
using namespace cv;

class TestNode : public rclcpp::Node
{
public:
    TestNode(string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Initializing TestNode");
        
        Image_sub = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera/image_raw", 10,
            bind(&TestNode::callback_camera, this, std::placeholders::_1));
            
        Target_pub = this->create_publisher<referee_pkg::msg::MultiObject>("/vision/target", 10);
        
        RCLCPP_INFO(this->get_logger(), "TestNode initialized successfully");
    }

private:
    void callback_camera(sensor_msgs::msg::Image::SharedPtr msg);
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr Image_sub;
    rclcpp::Publisher<referee_pkg::msg::MultiObject>::SharedPtr Target_pub;
    vector<Point2f> Point_V;  // 使用 Point2f 而不是 Point2d
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TestNode>("TestNode");
    RCLCPP_INFO(node->get_logger(), "Starting TestNode");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

void TestNode::callback_camera(sensor_msgs::msg::Image::SharedPtr msg)
{
    // RCLCPP_INFO(this->get_logger(), "Received image with encoding: %s", msg->encoding.c_str());
    
    try
    {
        // 更安全的图像转换方式
        cv_bridge::CvImagePtr cv_ptr;
        
        if (msg->encoding == "rgb8" || msg->encoding == "R8G8B8") {
            // 手动处理 RGB 格式
            cv::Mat image(msg->height, msg->width, CV_8UC3, 
                         const_cast<unsigned char*>(msg->data.data()));
            cv::Mat bgr_image;
            cv::cvtColor(image, bgr_image, cv::COLOR_RGB2BGR);
            cv_ptr = std::make_shared<cv_bridge::CvImage>();
            cv_ptr->header = msg->header;
            cv_ptr->encoding = "bgr8";
            cv_ptr->image = bgr_image;
        } else {
            // 使用标准转换
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }

        cv::Mat image = cv_ptr->image;
        imshow("Image",image);
        waitKey(1);
        // 检查图像是否有效
        if (image.empty()) {
            RCLCPP_WARN(this->get_logger(), "Received empty image");
            return;
        }

        // 转换到 HSV 空间
        cv::Mat hsv;
        cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);

        // 红色在 HSV 空间有两个区间
        cv::Mat mask1, mask2, mask;
        cv::inRange(hsv, cv::Scalar(0, 120, 70), cv::Scalar(10, 255, 255), mask1);
        cv::inRange(hsv, cv::Scalar(170, 120, 70), cv::Scalar(180, 255, 255), mask2);
        mask = mask1 | mask2;

        // 形态学操作去噪
        cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
        cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, kernel);
        cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);

        // 找轮廓
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        Point_V.clear(); // 清空上一帧的点

        for (size_t i = 0; i < contours.size(); i++)
        {
            double area = cv::contourArea(contours[i]);
            if (area < 500) // 忽略小噪点
                continue;

            // 计算最小外接矩形（边界框）
            cv::RotatedRect rotated_rect = cv::minAreaRect(contours[i]);
            cv::Point2f vertices[4];
            rotated_rect.points(vertices);

            // 简化处理：直接使用旋转矩形的四个点
            // 避免复杂的排序逻辑可能导致的问题
            for (int j = 0; j < 4; j++) {
                Point_V.push_back(vertices[j]);
            }
        }

        // 创建多目标消息
        referee_pkg::msg::MultiObject msg_object;
        msg_object.header = msg->header;
        msg_object.num_objects = Point_V.size() / 4;

        vector<string> types = {"sphere_sin"};

        // 为每个检测到的目标创建Object消息
        for (int k = 0; k < msg_object.num_objects; k++)
        {
            referee_pkg::msg::Object obj;
            obj.target_type = (k < types.size()) ? types[k] : "unknown";

            // 设置四个角点 - 使用更安全的方式
            for (int j = 0; j < 4; j++)
            {
                int index = 4 * k + j;
                if (index < Point_V.size()) {
                    geometry_msgs::msg::Point corner;
                    corner.x = Point_V[index].x;
                    corner.y = Point_V[index].y;
                    corner.z = 0.0;
                    
                    // 使用 push_back 而不是数组索引
                    obj.corners.push_back(corner);
                }
            }

            msg_object.objects.push_back(obj);
        }

        // 发布消息
        Target_pub->publish(msg_object);
        RCLCPP_INFO(this->get_logger(), "Published %d targets", msg_object.num_objects);
        
        // 安全的时间戳输出
        if (msg->header.stamp.sec > 0) {
            rclcpp::Time timestamp(msg->header.stamp);
            RCLCPP_INFO(this->get_logger(), "Timestamp: %.6f", timestamp.seconds());
        }
    }
    catch (const cv_bridge::Exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "Exception: %s", e.what());
    }
}