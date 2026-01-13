#include "main.h"
#include "subsystems.hpp"

static bool matchloader_toggle_bool;

void matchloader_toggle() {
    matchloader_toggle_bool = !matchloader_toggle_bool;
    ez::screen_print(matchloader_toggle_bool ? "Matchloader Extended" : "Matchloader Retracted", 2);
}

void matchloader_opcontrol() {
    if (matchloader_toggle_bool) {
      Match_loader.extend(); 
    }
    else {
      Match_loader.retract();
    }
}