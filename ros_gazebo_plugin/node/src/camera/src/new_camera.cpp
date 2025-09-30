#include "new_camera.hpp"
#include "gazebo/sensors/DepthCameraSensor.hh"
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/World.hh>
#include "gazebo/physics/PhysicsEngine.hh"
#include "gazebo/physics/PhysicsIface.hh"
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <rclcpp/rclcpp.hpp>
#include <pose_msg/msg/model_pose_array.hpp>

using namespace gazebo;
GZ_REGISTER_SENSOR_PLUGIN(NewCamera)

// 加密配置
const int AES_KEY_SIZE = 32;
const int AES_IV_SIZE = 16;

NewCamera::NewCamera() : initialized(false)
{
    // 初始化加密密钥和IV
    unsigned char key[AES_KEY_SIZE] = "Vision-Arena-2025-referee_Code1";
    unsigned char iv[AES_IV_SIZE] = "initial_vector1";
    memcpy(encryption_key, key, AES_KEY_SIZE);
    memcpy(encryption_iv, iv, AES_IV_SIZE);
}

void NewCamera::Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf)
{
    if (!_sensor)
        gzerr << "Invalid sensor pointer.\n";
    
    world = physics::get_world(_sensor->WorldName());
    this->parentSensor = std::dynamic_pointer_cast<sensors::CameraSensor>(_sensor);

    if (!this->parentSensor)
    {
        gzerr << "NewCamera requires a CameraSensor.\n";
        if (std::dynamic_pointer_cast<sensors::DepthCameraSensor>(_sensor))
            gzmsg << "It is a depth camera sensor\n";
        return;
    }

    this->camera = this->parentSensor->Camera();
    this->camera->UpdateCameraIntrinsics(476.0, 476.0, 400.0, 400.0, 0.0);
    
    if (!this->parentSensor)
    {
        gzerr << "NewCamera not attached to a camera sensor\n";
        return;
    }
    
    // 初始化ROS 2
    if (!rclcpp::ok())
        rclcpp::init(0, nullptr);
    
    this->node_pose = rclcpp::Node::make_shared("camera_pose");
    this->executor_.add_node(node_pose);
    
    // 保持原有的图像发布者不变
    this->pub_pose_ = node_pose->create_publisher<sensor_msgs::msg::Image>(
        "/camera/image_raw", 10);
    
    // 发布加密的模型状态
    this->pub_img = node_pose->create_publisher<pose_msg::msg::ModelPoseArray>(
        "/gazebo/model_states", 10);
    
    // 参数设置
    this->height = 640;
    this->width = 480;
    this->depth = 3;
    this->format = "R8G8B8";
    this->fps = 90.0;
    
    if(_sdf->HasElement("height")){
        this->height = _sdf->Get<int>("height");
    }
    if(_sdf->HasElement("width")){
        this->width = _sdf->Get<int>("width");
    }
    if(_sdf->HasElement("depth")){
        this->depth = _sdf->Get<int>("depth");
    }
    if(_sdf->HasElement("format")){
        this->format = _sdf->Get<std::string>("format");
    }
    if(_sdf->HasElement("fps")){
        this->fps = _sdf->Get<double>("fps");
    }
    
    this->camera->SetImageWidth(this->width);
    this->camera->SetImageHeight(this->height);
    this->camera->SetRenderRate(this->fps);

    this->newFrameConnection = this->camera->ConnectNewImageFrame(
        std::bind(&NewCamera::OnNewFrame, this,
            std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
            std::placeholders::_4, std::placeholders::_5));

    this->parentSensor->SetActive(true);
}

// 加密函数
std::vector<unsigned char> NewCamera::EncryptData(const std::vector<unsigned char>& plaintext)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create cipher context");
    }

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, encryption_key, encryption_iv)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to initialize encryption");
    }

    std::vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
    int len;
    int ciphertext_len;

    if (1 != EVP_EncryptUpdate(ctx, ciphertext.data(), &len, plaintext.data(), plaintext.size())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Encryption update failed");
    }
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Encryption finalization failed");
    }
    ciphertext_len += len;

    ciphertext.resize(ciphertext_len);
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext;
}

// 序列化函数
std::vector<unsigned char> NewCamera::SerializeModelStates(const pose_msg::msg::ModelPoseArray& msg)
{
    std::vector<unsigned char> data;
    
    // 序列化时间戳
    int64_t sec = msg.header.stamp.sec;
    int64_t nanosec = msg.header.stamp.nanosec;
    data.insert(data.end(), reinterpret_cast<unsigned char*>(&sec), 
                reinterpret_cast<unsigned char*>(&sec) + sizeof(sec));
    data.insert(data.end(), reinterpret_cast<unsigned char*>(&nanosec), 
                reinterpret_cast<unsigned char*>(&nanosec) + sizeof(nanosec));
    
    // 序列化帧ID长度和内容
    size_t frame_id_length = msg.header.frame_id.size();
    data.insert(data.end(), reinterpret_cast<unsigned char*>(&frame_id_length), 
                reinterpret_cast<unsigned char*>(&frame_id_length) + sizeof(frame_id_length));
    data.insert(data.end(), msg.header.frame_id.begin(), msg.header.frame_id.end());
    
    // 序列化模型数量
    size_t model_count = msg.models.size();
    data.insert(data.end(), reinterpret_cast<unsigned char*>(&model_count), 
                reinterpret_cast<unsigned char*>(&model_count) + sizeof(model_count));
    
    // 序列化每个模型数据
    for (const auto& model : msg.models) {
        // 序列化模型名称
        size_t name_length = model.name.size();
        data.insert(data.end(), reinterpret_cast<unsigned char*>(&name_length), 
                    reinterpret_cast<unsigned char*>(&name_length) + sizeof(name_length));
        data.insert(data.end(), model.name.begin(), model.name.end());
        
        // 序列化位置
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.position.x), 
                    reinterpret_cast<const unsigned char*>(&model.pose.position.x) + sizeof(double));
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.position.y), 
                    reinterpret_cast<const unsigned char*>(&model.pose.position.y) + sizeof(double));
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.position.z), 
                    reinterpret_cast<const unsigned char*>(&model.pose.position.z) + sizeof(double));
        
        // 序列化姿态
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.orientation.x), 
                    reinterpret_cast<const unsigned char*>(&model.pose.orientation.x) + sizeof(double));
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.orientation.y), 
                    reinterpret_cast<const unsigned char*>(&model.pose.orientation.y) + sizeof(double));
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.orientation.z), 
                    reinterpret_cast<const unsigned char*>(&model.pose.orientation.z) + sizeof(double));
        data.insert(data.end(), reinterpret_cast<const unsigned char*>(&model.pose.orientation.w), 
                    reinterpret_cast<const unsigned char*>(&model.pose.orientation.w) + sizeof(double));
    }
    
    return data;
}

void NewCamera::OnNewFrame(const unsigned char * _image,
                           unsigned int _width,
                           unsigned int _height,
                           unsigned int _depth,
                           const std::string &_format)
{
    // 发布原始图像（保持不变）
    auto msg = sensor_msgs::msg::Image();
    msg.header.stamp = node_pose->now();
    msg.header.frame_id = "camera_link";
    msg.height = _height;
    msg.width = _width;
    msg.encoding = "rgb8";
    msg.is_bigendian = false;
    msg.step = _width * _depth;
    size_t size = msg.step * msg.height;
    msg.data.resize(size);
    memcpy(&msg.data[0], _image, size);
    this->pub_pose_->publish(msg);
    
    // 处理模型状态（加密后发布）
    try {
        auto msgooo = pose_msg::msg::ModelPoseArray();
        msgooo.header.stamp = msg.header.stamp;
        msgooo.header.frame_id = "world";
        
        // 获取所有模型
        physics::Model_V models = world->Models();
        
        // 遍历所有模型并获取位姿
        for (auto &model : models) {
            if(model->GetName() == "ground_plane" || model->GetName() == "camera_robot")
                continue;
            
            pose_msg::msg::ModelPose model_pose;
            ignition::math::Pose3d pose = model->WorldPose();
            
            model_pose.name = model->GetName();
            model_pose.pose.position.x = pose.Pos().X();
            model_pose.pose.position.y = pose.Pos().Y();
            model_pose.pose.position.z = pose.Pos().Z();
            
            // 添加姿态信息
            model_pose.pose.orientation.x = pose.Rot().X();
            model_pose.pose.orientation.y = pose.Rot().Y();
            model_pose.pose.orientation.z = pose.Rot().Z();
            model_pose.pose.orientation.w = pose.Rot().W();
            
            msgooo.models.push_back(model_pose);
        }
        
        // 序列化模型状态
        std::vector<unsigned char> serialized_data = SerializeModelStates(msgooo);
        
        // 加密数据
        std::vector<unsigned char> encrypted_data = EncryptData(serialized_data);
        
        // 创建加密消息
        auto encrypted_msg = pose_msg::msg::ModelPoseArray();
        encrypted_msg.header = msgooo.header;
        encrypted_msg.is_encrypted = true;
        encrypted_msg.encrypted_data = encrypted_data;
        
        // 发布加密消息
        pub_img->publish(encrypted_msg);
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_pose->get_logger(), "Encryption error: %s", e.what());
    }
}