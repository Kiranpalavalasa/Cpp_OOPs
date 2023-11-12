#include <iostream>
#include <chrono>
#include <thread>

#include "aerial_robot.h"

// Method to take off
void RWA2::AerialRobot::take_off(double altitude){
    //Setting the flag is flying to true.
    is_flying_ = true;
    // declaring the duration variable to use it to sleep.
    int duration{0};
    // Checking if the robot has wings.
    if(has_wings_){
        // Setting the altitude based on the robot having wings.
        duration = altitude*1000/3;
    }
    else {
        // Setting the altitude based on the robot having wings.
        duration = altitude *1000/1.5;
    }
    // Making the robot sleep for the calculated duration.
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    // Setting altitude to the new altitude.
    altitude_ = altitude;
}

void RWA2::AerialRobot::land(){
    // declaring the duration variable to use it to sleep.
    int duration{0};
    // Checking if the robot has wings.
    if(has_wings_){
        // Setting the altitude based on the robot having wings.
        duration = altitude_*1000/4;
    }
    else {
        // Setting the altitude based on the robot having wings.
        duration = altitude_ *1000/2;
    }
    // Making the robot sleep for the calculated distance.
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    // Setting the altitude to zero as Robot has landed.
    altitude_ = 0;
    // Setting the is_flying flag to false.
    is_flying_ = false;
}

// Method to print the robot status
void RWA2::AerialRobot::print_status(){
    // Printing the position and orientation from the MobileRobot. 
    RWA2::MobileRobot::print_status();
    // Printing the rest of the attributes from the Aerial Robot.
    std::cout
      << "altitude_: " << altitude_ << ", is_flying: " << std::boolalpha 
      << is_flying_ <<", has wings: "<< std::boolalpha << has_wings_ <<"\n";
}

// Method to move the robot to a specified distance and angle.
void RWA2::AerialRobot::move(double distance, double angle){
    // checking if the distance is greater than 50 as it exceeds the battery capacity.
    if(distance > 50){
        // Printing a user friendly method to let them know that they are asking too much with the current battery capacity.
        std::cout<<"Distance is greater than the amount robot can move with its max battery capacity.\n";
    }
    else{
        // Discharging the battery by the specified distance * 2 as 2% charge is consumed.
        battery_.discharge(distance * 2);
        // Getting the sensor data.
        sensors_->read_data(5);
        // Checking if the robot is already flying. as it doesn't make sense to take off.
        if(!is_flying_){
            // Calling the take off method.
            take_off(5);
        }
        else {
            // Printing a user friendly message that the robot is already flying.
            std::cout<< "The AerialRobot "<<model_ <<" is already flying.\n";
        }
        // Rotating the robot by the mentioned angle.1
        rotate(angle);
        // Checking if the robot is flying. as it doesn't make sense to land when it's not flying.
        if(is_flying_){
            // LCalling the land method.
            land();
        }
        else {
            // Pring a user friendly message that the robot has already landed.
            std::cout<< "The AerialRobot "<<model_ <<" is already on land.\n";
        }
        // Printing a message that the robot has reached the mentioned altitude.
        std::cout<< model_ <<"Reached an altitude of "<<distance<<" meters and then landed.\n";
        // Printing the status.
        print_status();
    }

}