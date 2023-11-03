#pragma once
#include "mobile_robot.h"

namespace RWA2{
class WheeledRobot: public MobileRobot
{
    private:
        int number_of_wheels_;
        double wheel_diameter_;
        double desired_speed_;

        void accelerate(double amount);
        void decelerate(double amount);
        void brake();
    public:
        WheeledRobot(double x, double y, double orientation,int number_of_wheels = 2, double wheel_diameter, double desired_speed): 
        MobileRobot(x, y, orientation), 
        number_of_wheels_{number_of_wheels},
        wheel_diameter_{wheel_diameter}, 
        desired_speed_{desired_speed}{

        }
        
        virtual void move(double distance, double angle) override;
        virtual void print_status() override;
    protected:
        virtual void rotate(double angle) override;
        

};
}