#pragma once
#include "mobile_robot.h"

namespace RWA2{
class AerialRobot: public MobileRobot
{
    private:
        bool has_wings_;
        double altitude_;
        bool is_flying_;

        /**
         * @brief This method is used to move the robot to the mentioned altitude.
         * 
         * @param altitude The param altitude is used to decide how much the robot has to move.
         */
        void take_off(double altitude);

        /**
         * @brief @brief This method is used to land the robot, i.e. to make the robot reach an altitude of 0.
         * 
         */
        void land();    
    public:
        /**
         * @brief Construct a new Aerial Robot object
         * 
         * @param x x coordinate value of the position.
         * @param y y coordinate value of the position.
         * @param orientation orientation of the robot.
         * @param has_wings flag to decide if the robot has wings.
         * @param altitude altitude of the robot.
         * @param battery_model battery model attached to the robot.
         * @param current_charge current charge of the battery.
         * @param sensor_model sensor model attached to the robot
         * @param speed speed with which the robot moves.
         * @param is_flying flag to decide if the robot is flying.
         */
        AerialRobot(double x, double y, double orientation, bool has_wings,
        std::string battery_model, int current_charge,
        std::string sensor_model, double altitude = 0.0, bool is_flying = false, double speed = 0.0): 
        MobileRobot(x, y, orientation, battery_model, current_charge, sensor_model, speed), 
        has_wings_{has_wings}, 
        altitude_{altitude},
        is_flying_{is_flying}{

        }

        /**
         * @brief The overridden method to move the aerial robot.
         * 
         * @param distance The param distance by which the robot moves.
         * @param angle The param angle by which the robot rotates.
         */
        virtual void move(double distance, double angle) override;

        /**
         * @brief The overridden method to print the status of the aerial robot.
         * 
         */
        virtual void print_status() override;
        

};

}