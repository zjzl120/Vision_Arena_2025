#include "referee_pkg/utils.hpp"

void JsonGenerator::JsonGenerate(double score, string team_name,
                                 RaceStage stage, int hitarror_successcount,
                                 double average_precionlevel) {
  j_["run_id"] = generate_run_id();       // 运行id
  j_["timestamp"] = generate_timestamp(); // 时间戳
  j["team_name"] = team_name;
  j_["score"] = score;
  j_["hitarror_successcount"] = hitarror_successcount;
  j_["average_precionlevel"] = roundToThreeDecimals(average_precionlevel);
  std::string temp = "RaceStage";
  j[temp + stage] += j_;
  string filename = "results/" + team_name + "_results.json";
  remove(filename.c_str()); // 保证 json 不输出的奇奇怪怪
  // remove((filename + ".sha256").c_str()); // string 的 c_str() 函数 将
  // string 转换为 char*

  ofstream json_(filename, std::ios::app); // 打开json

  json_ << j.dump(4) << "\n"; // 写入 并在最后加个回车

  json_.close();             // 关闭文件
  culculateSHA256(filename); // 计算并输出 sha256 文件
}
void JsonGenerator::JsonGenerate(
    double score, string team_name, string target_type, RaceStage stage,
    int targets_found, double average_positionerror,
    double average_orientationerror, double average_ringcenter_error,
    double max_positionerror, double max_orientationerror) {
  j_["run_id"] = generate_run_id();       // 运行id
  j_["timestamp"] = generate_timestamp(); // 时间戳
  j["team_name"] = team_name;
  j_["score"] = score;
  j_["targets_found"] = targets_found;
  j_["average_positionerror"] = roundToThreeDecimals(average_positionerror);
  j_["average_orientationerror"] =
      roundToThreeDecimals(average_orientationerror);
  j_["average_ringcentererror"] =
      roundToThreeDecimals(average_ringcenter_error);
  j_["max_positionerror"] = roundToThreeDecimals(max_positionerror);
  j_["max_orientationerror"] = roundToThreeDecimals(max_orientationerror);
  j_["target_type"] = target_type;
  std::string temp = "RaceStage";
  j[temp + stage] += j_;
  string filename = "results/" + team_name + "_results.json";
  remove(filename.c_str()); // 保证 json 不输出的奇奇怪怪
  // remove((filename + ".sha256").c_str()); // string 的 c_str() 函数 将
  // string 转换为 char*

  ofstream json_(filename, std::ios::app); // 打开json

  json_ << j.dump(4) << "\n"; // 写入 并在最后加个回车

  json_.close();             // 关闭文件
  culculateSHA256(filename); // 计算并输出 sha256 文件
}
void JsonGenerator::JsonGenerate(double score, string team_name,
                                 string target_type, RaceStage stage,
                                 int targets_found,
                                 double average_positionerror,
                                 double average_orientationerror,
                                 double max_positionerror,
                                 double max_orientationerror) {
  j_["run_id"] = generate_run_id();       // 运行id
  j_["timestamp"] = generate_timestamp(); // 时间戳
  j["team_name"] = team_name;
  j_["score"] = score;
  j_["targets_found"] = targets_found;
  j_["average_positionerror"] = roundToThreeDecimals(average_positionerror);
  j_["average_orientationerror"] =
      roundToThreeDecimals(average_orientationerror);
  j_["max_positionerror"] = roundToThreeDecimals(max_positionerror);
  j_["max_orientationerror"] = roundToThreeDecimals(max_orientationerror);
  j_["target_type"] = target_type;
  std::string temp = "RaceStage";
  j[temp + stage] += j_;
  string filename = "results/" + team_name + "_results.json";
  remove(filename.c_str()); // 保证 json 不输出的奇奇怪怪
  // remove((filename + ".sha256").c_str()); // string 的 c_str() 函数 将
  // string 转换为 char*

  ofstream json_(filename, std::ios::app); // 打开json

  json_ << j.dump(4) << "\n"; // 写入 并在最后加个回车

  json_.close();             // 关闭文件
  culculateSHA256(filename); // 计算并输出 sha256 文件
}
std::string JsonGenerator::generate_run_id() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 15);
  std::uniform_int_distribution<> dis2(8, 11);

  std::stringstream ss;
  const char *hex_chars = "0123456789abcdef";

  for (int i = 0; i < 36; i++) {
    if (i == 8 || i == 13 || i == 18 || i == 23) {
      ss << "-";
      continue;
    }

    if (i == 14) {
      ss << "4";
    } else if (i == 19) {
      ss << hex_chars[dis2(gen)];
    } else {
      ss << hex_chars[dis(gen)];
    }
  }

  return ss.str();
}
std::string JsonGenerator::generate_timestamp() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%dT%H:%M:%SZ");
  return ss.str();
}
void JsonGenerator::culculateSHA256(string filename) {
  ifstream inputfile(filename);
  ofstream outputfile(filename + ".sha256");
  if (!inputfile) {
    cout << "json open error! " << endl;
    return;
  }
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  std::vector<char> buffer(4096);
  // 通过全部内容计算 sha256
  while (inputfile.read(buffer.data(), buffer.size()) ||
         inputfile.gcount() > 0) {
    SHA256_Update(&sha256, buffer.data(), inputfile.gcount());
  }
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_Final(hash, &sha256);

  std::stringstream ss;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0')
       << static_cast<int>(hash[i]);
  }

  outputfile << ss.str() << "\n";
  outputfile.close();
}
double calculatePositionError(const geometry_msgs::msg::Point &actual,
                              const geometry_msgs::msg::Point &desired) {
  double dx = actual.x - desired.x;
  double dy = actual.y - desired.z;
  double dz = actual.z + desired.y;

  return std::sqrt(dx * dx + dy * dy + dz * dz);
}
double calculateRingError(const geometry_msgs::msg::Point &actual,
                          const geometry_msgs::msg::Point &desired) {
  double dx = actual.x - desired.x;
  double dy = actual.y - desired.y;
  double dz = actual.z - desired.z;

  return std::sqrt(dx * dx + dy * dy + dz * dz);
}
double
calculateOrientationError(const geometry_msgs::msg::Quaternion &actual,
                          const geometry_msgs::msg::Quaternion &desired) {

  double dot_product =
      std::abs(actual.x * desired.x + actual.y * desired.y +
               actual.z * desired.z + actual.w * desired.w); // -1 , 1

  dot_product = std::min(std::max(dot_product, -1.0), 1.0); // -1 ,1

  return 2.0 * std::acos(dot_product); // 0-pi  ( 弧度 )
}
double calculateOrientationError(const tf2::Quaternion &actual,
                                 const tf2::Quaternion &desired) {
  double dot_product =
      std::abs(actual.getX() * desired.getX() + actual.getY() * desired.getY() +
               actual.getZ() * desired.getZ() + actual.getW() * desired.getW()); // -1 , 1

  dot_product = std::min(std::max(dot_product, -1.0), 1.0); // -1 ,1

  return 2.0 * std::acos(dot_product); // 0-pi  ( 弧度 )
}
bool time_stamp::DataMatcher::findMatchingData(
    referee_pkg::ObjectPoseInfo &object_info,
    gazebo_msgs::msg::ModelStates &model_states) {

  if (object_data_map_.empty() || model_data_map_.empty()) {
    return false;
  }
  // 获取最新的物体数据
  auto object = object_data_map_.begin();

  auto model = model_data_map_.find(object->first);
  // std::cout << rclcpp::Time(object->first).nanoseconds() << endl;
  if (model == model_data_map_.end()) {
    return false;
  }
  object_info = object->second;
  model_states = model->second;
  object_data_map_.erase(object);

  RCLCPP_INFO(logger_, "Sruccss");
  return true;
}
bool time_stamp::DataMatcher::findMatchingData(
    std::vector<referee_pkg::ObjectPoseInfo> &object_info,
    gazebo_msgs::msg::ModelStates &model_states) {

  if (object_dataarray_map_.empty() || model_data_map_.empty()) {
    return false;
  }
  // 获取最新的物体数据
  auto object = object_dataarray_map_.begin();

  auto model = model_data_map_.find(object->first);
  // std::cout << rclcpp::Time(object->first).nanoseconds() << endl;
  if (model == model_data_map_.end()) {
    return false;
  }
  object_info = object->second;
  model_states = model->second;
  object_dataarray_map_.erase(object);

  RCLCPP_INFO(logger_, "Sruccss");
  return true;
}