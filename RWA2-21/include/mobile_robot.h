#pragma once

#include <iostream>
#include <utility>
#include <memory>

#include "battery.h"
#include "sensor.h"

namespace RWA2 {
class MobileRobot {
 
 protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};
  Battery battery_;
  std::unique_ptr<RWA2::Sensor> sensors_;
  std::string model_;

  /**
   * @brief This method is used to rotate the robot by the specified angle.
   * 
   * @param angle The param angle by which the robot moves.
   */
  void rotate(double angle);

 public:
 /**
  * @brief Construct a new Mobile Robot object
  * This method is used to initalize the values for the mobile robot.
  * @param x x coordinate value of the position.
  * @param y y coordinate value of the position.
  * @param orientation orientation of the robot.
  * @param battery_model battery model attached to the robot.
  * @param current_charge current charge of the battery.
  * @param sensor_model sensor model attached to the robot.
  * @param speed speed with which the robot moves.
  */
  MobileRobot(double x, double y, double orientation, std::string battery_model, int current_charge, std::string sensor_model, double speed = 0.0)
      : position_{x, y}, orientation_{orientation}, battery_(battery_model, current_charge), speed_{speed} {
    sensors_ = std::make_unique<RWA2::Sensor>(sensor_model);
  }

  /**
   * @brief This virtual method is used to move the robot by a specified distance and angle.
   * 
   * @param distance The param to move the robot
   * @param angle The param angle to which the robot moves
   */
  virtual void move(double distance, double angle) = 0;

  /**
   * @brief This method is used to print the status i.e. the orientation and position of the robot.
   * 
   */
  virtual void print_status();

};  // class MobileRobot
}  // namespace RWA2
