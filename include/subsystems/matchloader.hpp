#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::adi::Pneumatics Match_loader('A', false);
extern void matchloader_toggle();
extern void matchloader_opcontrol();