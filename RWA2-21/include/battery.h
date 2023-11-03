#include <iostream>

namespace RWA2 {
  class Battery{
    private:
    std::string model_;
    int current_charge_;
    bool is_charging_;

    public:
    void start_charging();
    void stop_charging();
    void discharge(double amount);
  }; // class Battery
} // namespace RWA2