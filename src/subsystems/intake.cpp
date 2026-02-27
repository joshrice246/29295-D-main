#include "main.h"

void set_intake(int power) {
  intake.move(power);
}

void intake_opcontrol() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      set_intake(-127);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      set_intake(127);
    }
    else {
      double speed = intake.get_actual_velocity();
      if (speed > 5 || speed < -5){
        set_intake(-speed * 0.1);
      }
      else {
        set_intake(0);
      }
    }
}