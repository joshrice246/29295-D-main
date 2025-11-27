#include "subsystems.hpp"
#include "api.h"

ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {1, 2, 3},    // Left Chassis Ports (negative port will reverse it!)
    {-4, -5, -6},  // Right Chassis Ports (negative port will reverse it!)

    7,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    343);   // Wheel RPM = cartridge * (motor gear / wheel gear)


pros::Motor intake(7);

pros::Motor belt(8);

void SetDrive(int driveDistance, int driveSpeed, int turnDegrees, int turnSpeed, char driveMeasurment)
{   
    #pragma region setup
    int basicMeasurment = 1; // 1 = inches change later if needed for different measurments
    int leftPID;
    int rightPID; 
    int distance;
    int turnDistance;
    int wheelDiamiter = 3.25; // Wheel diameter of robot
    int botWidth = 24; // Wheel to wheel width of robot
    #pragma endregion

    distance = driveDistance * basicMeasurment;
    turnDistance = turnDegrees * botWidth / (2 * wheelDiamiter);

    if (turnDegrees != 0)
    {
        leftPID = turnDistance;
        rightPID = -turnDistance;
    }
    else
    {
        leftPID = distance;
        rightPID = distance;
    }

    for (int i = 10; i > 0; i--)
    {
        chassis.drive_set(leftPID * i, rightPID * i);
    }
}
extern ez::PID drivePID;
void DriveWait();
void DriveTask();