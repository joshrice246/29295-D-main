#include "main.h"

static bool mid_goal_toggle_bool;

void matchloader_opcontrol() {
    if (mid_goal_toggle_bool) {
      temporaryremovalwithoutbreakingit.extend(); 
    }
    else {
      temporaryremovalwithoutbreakingit.retract();
    }
}