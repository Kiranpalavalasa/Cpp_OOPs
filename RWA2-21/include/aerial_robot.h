#pragma once
#include "mobile_robot.h"

namespace RWA2{
class AerialRobot: public MobileRobot
{
    private:
        bool has_wings_;
        double altitude_;
        bool is_flying_;

        void take_off();
        void land();    
    public:
        AerialRobot(double x, double y, double orientation, bool has_wings, double altitude = 0.0, bool is_flying = false): 
        MobileRobot(x, y, orientation), 
        has_wings_{has_wings}, 
        altitude_{altitude},
        is_flying_{is_flying}{

        }
        
        virtual void move(double distance, double angle) override;
        virtual void print_status() override;
    protected:
        virtual void rotate(double angle) override;
        

};

}