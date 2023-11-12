#pragma once
#include "mobile_robot.h"

namespace RWA2{
class LeggedRobot: public MobileRobot
{
    private:
        double height_;
        int leg_strength_;
        int number_of_legs_{2};

        /**
         * @brief @brief This method is make the robot kick with leg strength.
         * 
         */
        void kick();  

        /**
         * @brief The robot jumps using this method
         * 
         * @param amount the number of leg strengths which the robot can jump.
         */
        void jump(double amount);    
    public:
        /**
         * @brief Construct a new Legged Robot object
         * 
         * @param x x coordinate value of the position.
         * @param y y coordinate value of the position.
         * @param orientation orientation of the robot.
         * @param height Height the robot can jump.
         * @param battery_model battery model attached to the robot.
         * @param current_charge current charge of the battery.
         * @param sensor_model sensor model attached to the robot
         * @param leg_strength leg strength of the robot.
         * @param number_of_legs number of legs the robot has.
         * @param speed speed with which the robot is moving.
         */
        LeggedRobot(double x, double y, double orientation, double height,
        std::string battery_model, int current_charge,
        std::string sensor_model,  int leg_strength, int number_of_legs = 2 , double speed = 0.0): 
        height_{height},
        leg_strength_{leg_strength}, 
        number_of_legs_{number_of_legs},
        MobileRobot(x, y, orientation, battery_model, current_charge, sensor_model, speed){

        }

        /**
         * @brief The overridden method to move the Legged robot.
         * 
         * @param distance The param distance by which the robot moves.
         * @param angle The param angle by which the robot rotates.
         */
        virtual void move(double distance, double angle) override;

        /**
         * @brief The overridden method to print the status of the Legged robot.
         * 
         */
        virtual void print_status() override;
        

};

}