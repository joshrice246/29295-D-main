#pragma once
#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::adi::Pneumatics Descore('B', false);
extern void descore_toggle();
extern void descore_opcontrol();