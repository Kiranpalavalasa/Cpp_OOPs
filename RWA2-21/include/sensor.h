#include <iostream>
#include <array>

namespace RWA2 {
  class Sensor{
    private:
    std::string model_;
    std::array<double, 50> data_;

    public:
    /**
     * @brief Construct a new Sensor object
     * Takes in model parameter to set the model of the sensor.
     * @param model values are OSDome, OS0, OS1, OS2, multiScan100, LMS5xx, LD-MRS
     */
    Sensor(std::string model): model_{model}{
    }
    /**
     * @brief 
     * This method takes duration as input and then generates 50 random values for the sensor data
     * after sleeping for the set duration of time, as we don't have any physical sensors.
     * 
     * The sensor data values are in a range of 0 to 30 as the max distance measure was 30m.
     * @param duration 
     * @return ** void 
     */
    void read_data(unsigned int duration);
  }; // class Sensor
} // namespace RWA2