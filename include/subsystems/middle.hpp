#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::adi::Pneumatics Matchloader('D', false);
extern void matchloader_toggle();
extern void mid_goal_opcontrol();