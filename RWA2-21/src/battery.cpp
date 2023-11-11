#include <iostream>
#include <chrono>
#include <thread>

#include "battery.h"

// Stop charging method.
void RWA2::Battery::stop_charging(){
    // Setting the is_charging_ flag to false.
    RWA2::Battery::is_charging_ = false;
    // Printing the battery status.
    std::cout << "Battery " << RWA2::Battery::model_ << " is fully charged.\n";
}

// method to start charging.
void RWA2::Battery::start_charging(){
    // Setting the is_charging_ flag to true.
    RWA2::Battery::is_charging_ = true;
    // Printing the battery status.
    std::cout << "Battery " << RWA2::Battery::model_ << " is charging.\n";
    // Defining a duration variable to store time to charge.
    int duration{0};
    // Checking the model of the battery.
    if(RWA2::Battery::model_  == "Li-ion"){
        // setting the duration based on the model in milliseconds.
        duration = (100 - current_charge_)*500 ;
    }
    // Checking the model of the battery.
    else if(RWA2::Battery::model_  == "LiFePO4"){
        // Setting the duration based on the model in milliseconds.
        duration = (100 - current_charge_)*250;
    }
    // Making the thread sleep for the duration.
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    // Setting the current_charge_ to 100% as charing is complete.
    RWA2::Battery::current_charge_ = 100;
    // Calling the stop charing as the current_charge_ is set to 100%.
    RWA2::Battery::stop_charging();
}

void RWA2::Battery::discharge(double amount){
    // Checking if the amount is out of range.
    if(amount > 100 || amount < 0){
        std::cout << "Battery's discharge amount cannot be greater than 100 or less than 0.\n";
    }
    // Checking if the amount is greater than the current_charge_.
    if(amount > RWA2::Battery::current_charge_){
        std::cout << "Battery doesn't have enough charge.\n";
        RWA2::Battery::start_charging();
    }
    // If the current_charge_ is greater than the amount, decreasing the current_charge_ by amount value.
    else{
        RWA2::Battery::current_charge_ -= amount;
    }
}
