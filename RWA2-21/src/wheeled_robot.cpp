#include <iostream>
#include <chrono>
#include <thread>

#include "wheeled_robot.h"

// Method to accelerate
void RWA2::WheeledRobot::accelerate(double amount){
    // While loop to reach the desired speed.
    while(speed_ <= desired_speed_){
        // incrementing the speed by amount.
        speed_ += amount;
        // Making the thread sleep for 0.5 sec.
        std::this_thread::sleep_for(std::chrono::milliseconds(500))
    }
    // Printing the speed status of the robot.
    std::cout<< model_ << " has reached the desired speed of "<< desired_speed_ << "m/s.\n";
}

// Method to decelerate
void RWA2::WheeledRobot::decelerate(double amount){
    // While loop to reach the a halt.
    while(speed_ >= 0){
        // decrementing the speed by amount.
        speed_ -= amount;
        // Making the thread sleep for 0.5 sec.
        std::this_thread::sleep_for(std::chrono::milliseconds(500))
    }
    // Printing the speed status of the robot.
    std::cout<< model_ << " has reached stopped.\n";
}

void RWA2::WheeledRobot::brake(){
    //setting the speed to zero as the robot has to stop moving.
    speed_ = 0.0;
}

// Method to print the robot status
void RWA2::WheeledRobot::print_status(){
    // Printing the position and orientation from the MobileRobot. 
    RWA2::MobileRobot::print_status();
    // Printing the rest of the attributes from the Wheeled Robot.
    std::cout
      << "number of wheels: " << number_of_wheels_ << ", wheel diameter: " 
      << wheel_diameter_ <<", desired speed: "<< desired_speed_ <<"\n";
}

// Method to move the robot to a specified distance and angle.
void RWA2::WheeledRobot::move(double distance, double angle){
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
        // Calling the accelerate to accelerate the robot.
        accelerate(2);
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(distance-2)*1000));
        // Rotating the robot by the mentioned angle.1
        rotate(angle);
        // Calling the decelerate to decelerate the robot.
        decelerate(2);
        // Calling brake to stop the robot.
        brake();
        // Printing a message that the robot has reached the mentioned distance.
        std::cout<< model_ <<" drove "<<distance<<" m\n";
        // Printing the status.
        print_status();
    }

}