#include <iostream>
#include <chrono>
#include <thread>

#include "aquatic_robot.h"

// Method to dive.
void RWA2::AquaticRobot::dive(double depth){
    //Setting the flag to true.
    is_diving_ = true;
    // declaring the duration variable to use it to sleep.
    int duration{0};
    // Checking if the robot has fins.
    if(has_fins_){
        // Setting the depth based on the robot having fins.
        duration = depth*1000/2;
    }
    else {
        // Setting the depth based on the robot having fins.
        duration = depth *1000;
    }
    // Making the robot sleep for the calculated duration.
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    // Setting depth to the new depth.
    depth_ = depth;
}

// Method to surface.
void RWA2::AquaticRobot::surface(){
    // declaring the duration variable to use it to sleep.
    int duration{0};
    // Checking if the robot has fins.
    if(has_fins_){
        // Setting the depth based on the robot having fins.
        duration = depth_*1000/4;
    }
    else {
        // Setting the depth based on the robot having fins.
        duration = depth_ *1000/2;
    }
    // Making the robot sleep for the calculated distance.
    std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    // Setting the depth to zero as Robot has surfaced.
    depth_ = 0;
    //Setting the flag to false.
    is_diving_ = false;
}

// Method to print the robot status.
void RWA2::AquaticRobot::print_status(){
    // Printing the position and orientation from the MobileRobot. 
    RWA2::MobileRobot::print_status();
    // Printing the rest of the attributes from the Aquatic Robot.
    std::cout
      << "depth_: " << depth_ << ", is_diving: " << std::boolalpha 
      << is_diving_ <<", has fins: "<< std::boolalpha << has_fins_ <<"\n";
}

// Method to move the robot to a specified distance and angle.
void RWA2::AquaticRobot::move(double distance, double angle){
    // checking if the distance is greater than 50 as it exceeds the battery capacity.
    if(distance > 100){
        // Printing a user friendly method to let them know that they are asking too much with the current battery capacity.
        std::cout<<"Distance is greater than the amount robot can move with its max battery capacity.\n";
    }
    else{
        // Discharging the battery by the specified distance as 1% charge is consumed.
        battery_.discharge(distance);
        // Getting the sensor data.
        sensors_->read_data(5);
        // Checking if the robot is already diving. as it doesn't make sense to dive.
        if(!is_diving_){
            // Calling the dive method.
            dive(5);
        }
        else {
            // Printing a user diving message that the robot is already diving.
            std::cout<< "The AquaticRobot "<<model_ <<" is already flying.\n";
        }
        // Rotating the robot by the mentioned angle.1
        rotate(angle);
        // Checking if the robot is diving. as it doesn't make sense to surface when it's not diving.
        if(is_diving_){
            // LCalling the surface method.
            surface();
        }
        else {
            // Pring a user friendly message that the robot has already surfaceed.
            std::cout<< "The AquaticRobot "<<model_ <<" is already on surface.\n";
        }
        // Printing a message that the robot has reached the mentioned depth.
        std::cout<< model_ <<"Reached an depth of "<<distance<<" meters and then surfaceed.\n";
        // Printing the status.
        print_status();
    }

}