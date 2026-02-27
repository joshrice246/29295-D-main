#include "main.h"

static bool mid_goal_toggle_bool;

void matchloader_toggle() {
    mid_goal_toggle_bool = !mid_goal_toggle_bool;
    ez::screen_print(mid_goal_toggle_bool ? "Matchloader Extended" : "Matchloader Retracted", 2);
}

void mid_goal_opcontrol() {
    if (mid_goal_toggle_bool) {
      Matchloader.extend(); 
    }
    else {
      Matchloader.retract();
    }
}