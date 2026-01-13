#include "main.h"
#include "subsystems.hpp"

static bool descore_toggle_bool;

void descore_toggle() {
    descore_toggle_bool = !descore_toggle_bool;
    ez::screen_print(descore_toggle_bool ? "Matchloader Extended" : "Matchloader Retracted", 2);
}

void descore_opcontrol() {
    if (descore_toggle_bool) {
      Match_loader.extend(); 
    }
    else {
      Match_loader.retract();
    }
}