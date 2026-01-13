#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;
extern void drivetrain(float pCurve, float tCoefficient, float tCurve, double power, double powerC, double turn, double turnC, 
    double leftDrv, double rightDrv);