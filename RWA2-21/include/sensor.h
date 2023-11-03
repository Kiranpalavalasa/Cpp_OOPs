#include <iostream>
#include <array>

namespace RWA2 {
  class Sensor{
    private:
    std::string model_;
    std::array<double, 50> data_;

    public:
    void read_data(unsigned int duration);
  }; // class Sensor
} // namespace RWA2