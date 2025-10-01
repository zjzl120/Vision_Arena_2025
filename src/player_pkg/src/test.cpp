#include <cv_bridge/cv_bridge.h>

#include <cmath>
#include <geometry_msgs/msg/point.hpp>
#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/timer.hpp>
#include <referee_pkg/msg/multi_object.hpp>
#include <referee_pkg/msg/object.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <std_msgs/msg/header.hpp>

#include "sensor_msgs/msg/image.hpp"

using namespace std;
using namespace rclcpp;
using namespace cv;

class TestNode : public rclcpp::Node {
 public:
  TestNode(string name) : Node(name) {
    RCLCPP_INFO(this->get_logger(), "Initializing TestNode");

    Image_sub = this->create_subscription<sensor_msgs::msg::Image>(
        "/camera/image_raw", 10,
        bind(&TestNode::callback_camera, this, std::placeholders::_1));

    Target_pub = this->create_publisher<referee_pkg::msg::MultiObject>(
        "/vision/target", 10);

    cv::namedWindow("Detection Result", cv::WINDOW_AUTOSIZE);

    RCLCPP_INFO(this->get_logger(), "TestNode initialized successfully");
  }

  ~TestNode() { cv::destroyWindow("Detection Result"); }

 private:
  void callback_camera(sensor_msgs::msg::Image::SharedPtr msg);

  // 稳定的球体点计算方法
  vector<Point2f> calculateStableSpherePoints(const Point2f &center,
                                              float radius);

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr Image_sub;
  rclcpp::Publisher<referee_pkg::msg::MultiObject>::SharedPtr Target_pub;
  vector<Point2f> Point_V;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<TestNode>("TestNode");
  RCLCPP_INFO(node->get_logger(), "Starting TestNode");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

vector<Point2f> TestNode::calculateStableSpherePoints(const Point2f &center,
                                                      float radius) {
  vector<Point2f> points;

  // 简单稳定的几何计算，避免漂移
  // 左、下、右、上
  points.push_back(Point2f(center.x - radius, center.y));  // 左点 (1)
  points.push_back(Point2f(center.x, center.y + radius));  // 下点 (2)
  points.push_back(Point2f(center.x + radius, center.y));  // 右点 (3)
  points.push_back(Point2f(center.x, center.y - radius));  // 上点 (4)

  return points;
}

void TestNode::callback_camera(sensor_msgs::msg::Image::SharedPtr msg) {
  try {
    // 图像转换
    cv_bridge::CvImagePtr cv_ptr;

    if (msg->encoding == "rgb8" || msg->encoding == "R8G8B8") {
      cv::Mat image(msg->height, msg->width, CV_8UC3,
                    const_cast<unsigned char *>(msg->data.data()));
      cv::Mat bgr_image;
      cv::cvtColor(image, bgr_image, cv::COLOR_RGB2BGR);
      cv_ptr = std::make_shared<cv_bridge::CvImage>();
      cv_ptr->header = msg->header;
      cv_ptr->encoding = "bgr8";
      cv_ptr->image = bgr_image;
    } else {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }

    cv::Mat image = cv_ptr->image;

    if (image.empty()) {
      RCLCPP_WARN(this->get_logger(), "Received empty image");
      return;
    }

    // 创建结果图像
    cv::Mat result_image = image.clone();

    // 转换到 HSV 空间
    cv::Mat hsv;
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);

    // 红色检测 - 使用稳定的范围
    cv::Mat mask1, mask2, mask;
    cv::inRange(hsv, cv::Scalar(0, 120, 70), cv::Scalar(10, 255, 255), mask1);
    cv::inRange(hsv, cv::Scalar(170, 120, 70), cv::Scalar(180, 255, 255),
                mask2);
    mask = mask1 | mask2;

    // 适度的形态学操作
    cv::Mat kernel =
        cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
    cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, kernel);
    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);

    // 找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL,
                     cv::CHAIN_APPROX_SIMPLE);

    Point_V.clear();
    int valid_spheres = 0;

    for (size_t i = 0; i < contours.size(); i++) {
      double area = cv::contourArea(contours[i]);
      if (area < 500) continue;

      // 计算最小外接圆
      Point2f center;
      float radius = 0;
      minEnclosingCircle(contours[i], center, radius);

      // 计算圆形度
      double perimeter = arcLength(contours[i], true);
      double circularity = 4 * CV_PI * area / (perimeter * perimeter);

      if (circularity > 0.7 && radius > 15 && radius < 200) {
        vector<Point2f> sphere_points =
            calculateStableSpherePoints(center, radius);

        // 绘制检测到的球体
        cv::circle(result_image, center, static_cast<int>(radius),
                   cv::Scalar(0, 255, 0), 2);  // 绿色圆圈
        cv::circle(result_image, center, 3, cv::Scalar(0, 0, 255),
                   -1);  // 红色圆心

        // 绘制球体上的四个点
        vector<string> point_names = {"左", "下", "右", "上"};
        vector<cv::Scalar> point_colors = {
            cv::Scalar(255, 0, 0),    // 蓝色 - 左
            cv::Scalar(0, 255, 0),    // 绿色 - 下
            cv::Scalar(0, 255, 255),  // 黄色 - 右
            cv::Scalar(255, 0, 255)   // 紫色 - 上
        };

        for (int j = 0; j < 4; j++) {
          cv::circle(result_image, sphere_points[j], 6, point_colors[j], -1);
          cv::circle(result_image, sphere_points[j], 6, cv::Scalar(0, 0, 0), 2);

          // 标注序号
          string point_text = to_string(j + 1);
          cv::putText(
              result_image, point_text,
              cv::Point(sphere_points[j].x + 10, sphere_points[j].y - 10),
              cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 3);
          cv::putText(
              result_image, point_text,
              cv::Point(sphere_points[j].x + 10, sphere_points[j].y - 10),
              cv::FONT_HERSHEY_SIMPLEX, 0.6, point_colors[j], 2);

          // 添加到发送列表
          Point_V.push_back(sphere_points[j]);

          RCLCPP_INFO(this->get_logger(),
                      "Sphere %d, Point %d (%s): (%.1f, %.1f)",
                      valid_spheres + 1, j + 1, point_names[j].c_str(),
                      sphere_points[j].x, sphere_points[j].y);
        }

        // 显示半径信息
        string info_text = "R:" + to_string((int)radius);
        cv::putText(
            result_image, info_text, cv::Point(center.x - 15, center.y + 5),
            cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 2);

        valid_spheres++;
        RCLCPP_INFO(this->get_logger(),
                    "Found sphere: (%.1f, %.1f) R=%.1f C=%.3f", center.x,
                    center.y, radius, circularity);
      }
    }

    // 显示结果图像
    cv::imshow("Detection Result", result_image);
    cv::waitKey(1);

    // 创建并发布消息
    referee_pkg::msg::MultiObject msg_object;
    msg_object.header = msg->header;
    msg_object.num_objects = Point_V.size() / 4;

    vector<string> types = {"sphere"};

    for (int k = 0; k < msg_object.num_objects; k++) {
      referee_pkg::msg::Object obj;
      obj.target_type = (k < types.size()) ? types[k] : "unknown";

      for (int j = 0; j < 4; j++) {
        int index = 4 * k + j;
        if (index < Point_V.size()) {
          geometry_msgs::msg::Point corner;
          corner.x = Point_V[index].x;
          corner.y = Point_V[index].y;
          corner.z = 0.0;
          obj.corners.push_back(corner);
        }
      }

      msg_object.objects.push_back(obj);
    }

    Target_pub->publish(msg_object);
    RCLCPP_INFO(this->get_logger(), "Published %d sphere targets",
                msg_object.num_objects);

  } catch (const cv_bridge::Exception &e) {
    RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
  } catch (const std::exception &e) {
    RCLCPP_ERROR(this->get_logger(), "Exception: %s", e.what());
  }
}