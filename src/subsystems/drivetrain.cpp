#include "main.h"
#include "subsystems.hpp"

void drivetrain(float pCurve, float tCoefficient, float tCurve, double power, double powerC, double turn, double turnC, 
    double leftDrv, double rightDrv) {
    // Setting power and turn variables
    power = master.get_analog(ANALOG_LEFT_Y);  // Left stick vertical
    turn = master.get_analog(ANALOG_RIGHT_X);  // Right stick horizontal

    // Calculating velocity
    powerC = ((1 - pCurve) * power) + ((pCurve * pow(power, 3)) / 16129); // don't change 16129
    //https://www.desmos.com/calculator/asjs86sdpy

    // Calculating turn curve
    turnC = tCoefficient * ((1 - tCurve) * turn) + ((tCurve * pow(turn, 3)) / 16129); // don't change 16129

    leftDrv = powerC + turnC;
    rightDrv = powerC - turnC;

    // Arcade Drive, setting the motor velocity
    chassis.drive_set(leftDrv, rightDrv);
}