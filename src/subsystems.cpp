#include "subsystems.hpp"
#include "api.h"

ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-20, -18, -19},    // Left Chassis Ports (negative port will reverse it!)
    {8, 9, 10},  // Right Chassis Ports (negative port will reverse it!)

    11,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM = cartridge * (motor gear / wheel gear)

// Extra motors
pros::Motor intake(4);
pros::Motor scorer(7);

// Pneumatics
   