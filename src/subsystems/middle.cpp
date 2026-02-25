#include "main.h"

static bool mid_goal_toggle_bool;

void mid_goal_toggle() {
    mid_goal_toggle_bool = !mid_goal_toggle_bool;
    ez::screen_print(mid_goal_toggle_bool ? "Matchloader Extended" : "Matchloader Retracted", 2);
}

void mid_goal_opcontrol() {
    if (mid_goal_toggle_bool) {
      mid_Goal.extend(); 
    }
    else {
      mid_Goal.retract();
    }
}