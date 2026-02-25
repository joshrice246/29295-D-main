#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::adi::Pneumatics mid_Goal('C', false);
extern void mid_goal_toggle();
extern void mid_goal_opcontrol();