#pragma once
#include "mobile_robot.h"

namespace RWA2{
class LeggedRobot: public MobileRobot
{
    private:
        double height_;
        int leg_strength_;
        int number_of_legs_;

        void kick();
        void jump(double amount);
    public:
        LeggedRobot(double x, double y, double orientation,double height, int leg_strength, int num_legs = 2): 
        MobileRobot(x, y, orientation), 
        height_{height},
        leg_strength_{leg_strength}, 
        number_of_legs_{num_legs}{

        }
        
        virtual void move(double distance, double angle) override;
        virtual void print_status() override;
    protected:
        virtual void rotate(double angle) override;
        

};
}