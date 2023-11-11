#include "mobile_robot.h"

void RWA2::MobileRobot::rotate(double angle) {
  // Printing the status of the Robot.
  std::cout << "Rotating by " << angle << " degrees\n";
  // Angle is added to orientation if it's positive and substracted if it's negative.
  RWA2::MobileRobot::orientation_ += angle;
}

void RWA2::MobileRobot::print_status() {
  // A seperation line.
  std::cout << "================\n";
  // Printing the position, orientation and speed of the robot.
  std::cout
      << "Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << "\n";
}