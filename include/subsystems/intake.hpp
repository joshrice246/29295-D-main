#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor intake(7);
extern void set_intake(int power);
extern void intake_opcontrol();