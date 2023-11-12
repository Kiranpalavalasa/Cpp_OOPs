#include <iostream>
#include <chrono>
#include <thread>

#include "legged_robot.h"

// Method to kick
void RWA2::LeggedRobot::kick(){
    // Prints the kick strength og the robot.
    std::cout<< model_ << "Kicks with a strength of "<< leg_strength_<<".\n";
}

// Method to jump
void RWA2::LeggedRobot::jump(double amount){
    // Jumps amount times leg strength.
    height_ = leg_strength_ * amount;
    // Printing the jumped height of the robot.
    std::cout<< model_ <<"Jumps at a height of "<< height_<<"cm above the ground.\n";
}

// Method to print the robot status
void RWA2::LeggedRobot::print_status(){
    // Printing the position and orientation from the MobileRobot. 
    RWA2::MobileRobot::print_status();
    // Printing the rest of the attributes from the Legged Robot.
    std::cout
      << "height: " << height_ << ", leg strength: " 
      << leg_strength_ <<", number of legs: "<< number_of_legs_ <<"\n";
}

// Method to move the robot to a specified distance and angle.
void RWA2::LeggedRobot::move(double distance, double angle){
    // checking if the distance is greater than 50 as it exceeds the battery capacity.
    if(distance > 10){
        // Printing a user friendly method to let them know that they are asking too much with the current battery capacity.
        std::cout<<"Distance is greater than the amount robot can move with its max battery capacity.\n";
    }
    else{
        // Discharging the battery by the specified distance as 1% charge is consumed.

        battery_.discharge(distance * leg_strength_ * 100 + leg_strength_);
        // Getting the sensor data.
        sensors_->read_data(5);
        // Rotating the robot by the mentioned angle.1
        rotate(angle);
        // Calling the jump to make the robot jump.
        jump(distance);
        // Calling the kick to make the robot kick.
        kick();
        // Printing the status of the Legged Robot.
        print_status();
    }

}