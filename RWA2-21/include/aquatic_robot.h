#pragma once
#include "mobile_robot.h"

namespace RWA2{
class AquaticRobot: public MobileRobot
{
    private:
        bool has_fins_;
        double depth_;
        bool is_diving_;

        /**
         * @brief This method is used to move the robot to the mentioned depth.
         * 
         * @param depth The param depth is used to decide how much the robot has to move.
         */
        void dive(double depth);

        /**
         * @brief @brief This method is used to surface the robot, i.e. to make the robot reach an depth of 0.
         * 
         */
        void surface();    
    public:
        /**
         * @brief Construct a new Aquatic Robot object
         * 
         * @param x x coordinate value of the position.
         * @param y y coordinate value of the position.
         * @param orientation orientation of the robot.
         * @param has_fins flag to decide if the robot has fins.
         * @param depth depth of the robot.
         * @param battery_model battery model attached to the robot.
         * @param current_charge current charge of the battery.
         * @param sensor_model sensor model attached to the robot
         * @param speed speed with which the robot moves.
         * @param is_diving flag to decide if the robot is diving.
         */
        AquaticRobot(double x, double y, double orientation, bool has_fins,
        double depth = 0.0, std::string battery_model, int current_charge,
        std::string sensor_model, bool is_diving = false, double speed = 0.0): 
        MobileRobot(x, y, orientation, battery_model, current_charge, sensor_model, speed), 
        has_fins_{has_fins}, 
        depth_{depth},
        is_diving_{is_diving}{

        }

        /**
         * @brief The overridden method to move the aquatic robot.
         * 
         * @param distance The param distance by which the robot moves.
         * @param angle The param angle by which the robot rotates.
         */
        virtual void move(double distance, double angle) override;

        /**
         * @brief The overridden method to print the status of the aquatic robot.
         * 
         */
        virtual void print_status() override;
        

};

}