#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;
extern pros::Motor intake;

void SetDrive(int drivePower);
extern ez::PID drivePID;
void DriveWait();
void DriveTask();