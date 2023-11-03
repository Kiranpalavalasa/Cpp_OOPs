#pragma once

#include <iostream>
#include <utility>
#include <memory>
#include "battery.h"
#include "sensor.h"

namespace RWA2 {
class MobileRobot{
 public:
  MobileRobot(double x, double y, double orientation)
      : position_{x, y}, orientation_{orientation} {
    /*empty body*/
  }

  virtual void move(double distance, double angle);
  virtual void print_status();

 protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};
  Battery battery_;
  std::unique_ptr<RWA2::Sensor> sensors_;
  
  virtual void rotate(double angle);
};  // class MobileRobot
}  // namespace RWA2