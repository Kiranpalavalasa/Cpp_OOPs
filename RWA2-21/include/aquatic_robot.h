#pragma once
#include "mobile_robot.h"

namespace RWA2{
class AquaticRobot: public MobileRobot
{
    private:
        bool has_fins_;
        double depth_;
        bool is_diving_;

        void dive();
        void surface();
    public:
        AquaticRobot(double x, double y, double orientation, bool has_fins, double depth = 0.0, bool is_diving): 
        MobileRobot(x, y, orientation), 
        has_fins_{has_fins}, 
        depth_{depth},
        is_diving_{is_diving}{

        }

        virtual void move(double distance, double angle) override;
        virtual void print_status() override;
    protected:
        virtual void rotate(double angle) override;

};

}