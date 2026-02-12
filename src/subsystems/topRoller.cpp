#include "main.h"
#include "subsystems.hpp"

void set_topRoller(int power) {
  topRoller.move(power);
}

void topRoller_opcontrol() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      set_topRoller(127);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      set_topRoller(-127);
    }
    else {
      double speed = topRoller.get_actual_velocity();
      if (speed > 5 || speed < -5){
        set_topRoller(-speed * 0.1);
      }
      else {
        set_topRoller(0);
      }
    }
}