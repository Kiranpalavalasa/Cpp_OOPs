#include <iostream>

namespace RWA2 {
  class Battery{
    private:
    std::string model_;
    int current_charge_;
    bool is_charging_;

    /**
     * @brief This is a method used to stop the charging of battery and set the flag is_charging to false.
     * 
     * This method also prints that the battery is fully charged.
     * 
     */
    void stop_charging();

    public:
    /**
     * @brief Construct a new Battery object
     * 
     * @param model values are limited to Liion or LiFePO4
     * @param current_charge value is limited to a min value of 0 and a max value of 100.
     */
    Battery(std::string model, int current_charge): model_{model}, current_charge_{current_charge}{

    }

    /**
     * @brief The method should calculate the remaining charge time based on the current_charge_ attribute
     * 
     */
    void start_charging();
    
    /**
     * @brief Each time this method is called, the battery’s current_charge_ decrements by amount
     * 
     * @param amount values are limited to a min value of 0 and a max value of 100.
     */
    void discharge(double amount);
  }; // class Battery
} // namespace RWA2