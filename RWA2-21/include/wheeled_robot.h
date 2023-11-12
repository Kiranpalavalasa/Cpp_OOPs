#pragma once
#include "mobile_robot.h"

namespace RWA2{
class WheeledRobot: public MobileRobot
{
    private:
        int number_of_wheels_{2};
        double wheel_diameter_;
        double desired_speed_;

        /**
         * @brief This method is used to accelerate the robot to the mentioned amount.
         * 
         * @param amount The param amount is used to decide how much the robot has to accelerate.
         */
        void accelerate(double amount);

        /**
         * @brief This method is used to decelerate the robot to the mentioned amount.
         * 
         * @param amount The param amount is used to decide how much the robot has to decelerate.
         */
        void decelerate(double amount);

        /**
         * @brief @brief This method is used to stop the robot, i.e. to make the robot reach an speed of 0.
         * 
         */
        void brake();    
    public:
        /**
         * @brief Construct a new Wheeled Robot object
         * 
         * @param x x coordinate value of the position.
         * @param y y coordinate value of the position.
         * @param orientation orientation of the robot.
         * @param wheel_diameter Diameter of the wheels.
         * @param battery_model battery model attached to the robot.
         * @param current_charge current charge of the battery.
         * @param sensor_model sensor model attached to the robot
         * @param desired_speed speed desired of the robot.
         * @param number_of_wheels number of wheels the robot has.
         * @param speed speed with which the robot is moving.
         */
        WheeledRobot(double x, double y, double orientation, double wheel_diameter,
        std::string battery_model, int current_charge,
        std::string sensor_model,  double desired_speed, int number_of_wheels = 2 , double speed = 0.0): 
        number_of_wheels_{number_of_wheels},
        wheel_diameter_{wheel_diameter}, 
        desired_speed_{desired_speed},
        MobileRobot(x, y, orientation, battery_model, current_charge, sensor_model, speed){

        }

        /**
         * @brief The overridden method to move the Wheeled robot.
         * 
         * @param distance The param distance by which the robot moves.
         * @param angle The param angle by which the robot rotates.
         */
        virtual void move(double distance, double angle) override;

        /**
         * @brief The overridden method to print the status of the Wheeled robot.
         * 
         */
        virtual void print_status() override;
        

};

}