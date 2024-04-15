#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <tuple>
#include <carla/client/ActorBlueprint.h>
#include <carla/client/BlueprintLibrary.h>
#include <carla/client/Client.h>
#include <carla/client/Map.h>
#include <carla/client/Sensor.h>
#include <carla/client/TimeoutException.h>
#include <carla/client/World.h>
#include <carla/geom/Transform.h>
#include <carla/image/ImageIO.h>
#include <carla/image/ImageView.h>
#include <carla/sensor/data/Image.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <carla/client/Vehicle.h>
#include <carla/rpc/VehicleControl.h>
namespace cc = carla::client;
namespace cg = carla::geom;
namespace csd = carla::sensor::data;
using namespace std::chrono_literals;
using namespace std::string_literals;



class CarlaIMUPublisher : public rclcpp::Node {

public:
    CarlaIMUPublisher(boost::shared_ptr<carla::client::Vehicle> vehicle_,std::string name_);

private:
    rclcpp::TimerBase::SharedPtr timer_1ms;
    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr IMUPublisher_;
    boost::shared_ptr<carla::client::Vehicle> Vehicle_;
    void CarlaIMUPublisher_callback();
    std::string role_name_;
};