#include "main.h"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 100;
const int TURN_SPEED = 80;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(5.0, 0.07, 50.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(5.0, 0.07, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(5.0, 0.05, 25.0, 15.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.05, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(6.5, 0.05, 52.5);    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(5.8, 0.03, 32.5);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
  chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

// . . .
// Make your own autonomous functions here!
// . . .

void skillz_aut()
{
  chassis.pid_wait();
}

void comp_aut_right() {
  chassis.pid_drive_set(41, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(87, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  Match_loader.extend();
  intake.move(-127);
  pros::delay(400);

  intake.move(-127);
  chassis.pid_drive_set(14, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  /*
  chassis.pid_drive_set(10, DRIVE_SPEED);
  pros::delay(200);
  chassis.pid_drive_set(-10, DRIVE_SPEED);
  pros::delay(200);
  chassis.pid_drive_set(10, DRIVE_SPEED);
  pros::delay(200);
  chassis.pid_drive_set(-10, DRIVE_SPEED);
  pros::delay(200);
  chassis.pid_drive_set(10, DRIVE_SPEED);
  pros::delay(200);
  chassis.pid_drive_set(-10, DRIVE_SPEED);
  pros::delay(200);
  */
  pros::delay(2000);

  chassis.pid_drive_set(-30, 60);
  chassis.pid_wait();
  scorer.move(-127);
  pros::delay(3000);
  scorer.move(0);
  intake.move(0);  
  Match_loader.retract();
  
  chassis.pid_drive_set(27, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(225, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  chassis.pid_drive_set(48, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move(127);
  scorer.move(127);
  pros::delay(250);
  scorer.move(0);
  pros::delay(2000);
  intake.move(0);
  
  chassis.pid_drive_set(-32, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait();
  
}

void comp_aut_left() {
                   
}