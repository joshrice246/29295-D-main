#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor topRoller(-11);
extern void set_topRoller(int power);
extern void topRoller_opcontrol();