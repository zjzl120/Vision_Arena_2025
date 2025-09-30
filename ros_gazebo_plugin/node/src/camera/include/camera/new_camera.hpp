#ifndef NEW_CAMERA_HPP
#define NEW_CAMERA_HPP

#include <gazebo/common/Plugin.hh>
#include <gazebo/sensors/CameraSensor.hh>
#include <gazebo/rendering/Camera.hh>
#include <gazebo/physics/physics.hh>
#include <rclcpp/rclcpp.hpp>
#include <pose_msg/msg/model_pose_array.hpp>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <vector>
#include <memory>
#include "gazebo/common/Plugin.hh"
#include "gazebo/sensors/CameraSensor.hh"
#include "gazebo/rendering/Camera.hh"
#include "gazebo/util/system.hh"
#include"sensor_msgs/msg/image.hpp"
#include <rclcpp/rclcpp.hpp>
#include <pose_msg/msg/model_pose.hpp>
#include "pose_msg/msg/model_pose_array.hpp"

namespace gazebo
{

class NewCamera : public SensorPlugin
{
public:
    NewCamera();
    virtual ~NewCamera() = default;

    void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf) override;

private:
    void OnNewFrame(const unsigned char *_image,
                    unsigned int _width,
                    unsigned int _height,
                    unsigned int _depth,
                    const std::string &_format);
    
    std::vector<unsigned char> EncryptData(const std::vector<unsigned char>& plaintext);
    std::vector<unsigned char> SerializeModelStates(const pose_msg::msg::ModelPoseArray& msg);
    pose_msg::msg::ModelPoseArray GetModelStatesMessage();

    sensors::CameraSensorPtr parentSensor;
    rendering::CameraPtr camera;
    physics::WorldPtr world;
    
    event::ConnectionPtr newFrameConnection;
    
    rclcpp::Node::SharedPtr node_pose;
    rclcpp::executors::SingleThreadedExecutor executor_;
    std::thread executor_thread;
    private:rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr pub_pose_;
    private:rclcpp::Publisher<pose_msg::msg::ModelPoseArray>::SharedPtr pub_img;

    unsigned char encryption_key[32];
    unsigned char encryption_iv[16];
    
    int height, width, depth;
    double fps;
    std::string format;
    bool initialized;
};

} // namespace gazebo

#endif // NEW_CAMERA_HPP