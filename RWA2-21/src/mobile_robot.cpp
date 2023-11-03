#include "mobile_robot.h"

void RWA2::MobileRobot::rotate(double angle) {
  std::cout << "MobileRobot: Rotating " << angle << " degrees\n";
}

void RWA2::MobileRobot::move(double distance, double angle) {
  std::cout << "MobileRobot: Moving\n";
}

void RWA2::MobileRobot::print_status() {
  std::cout << "================\n";
  std::cout
      << "Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << "\n";
}