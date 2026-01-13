#include "main.h"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 150;
const int TURN_SPEED = 40;
const int SWING_SPEED = 35;
const int ODOM_SPEED = 40;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(4.5, 0.07, 50.0);         // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(4.0, 0.07, 20.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(3.0, 0.05, 25.0, 15.0);     // Turn in place constants
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
  // First Matchloader
  chassis.pid_drive_set(32.8f, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  Match_loader.extend();
  intake.move(-127);
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(17, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_turn_set(92, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(88, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(2, DRIVE_SPEED);
  chassis.pid_wait_quick();
  pros::delay(500);
  
  // Traveling to score
  chassis.pid_drive_set(-4, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-15, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  Match_loader.retract();
  intake.move(0);
  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick_chain(); 
  chassis.pid_drive_set(76, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(0, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(12.7f, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  
  // Scoring First Matchloader
  chassis.pid_drive_set(-18, DRIVE_SPEED);
  chassis.pid_wait();
  intake.move(-127);
  scorer.move(-127);
  pros::delay(3000);
  scorer.move(0);
  
  // Second Matchloader + Scoring
  Match_loader.extend();
  pros::delay(250);
  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
 // chassis.pid_turn_set(-100, TURN_SPEED);
 // chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(9, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-95, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(700);
  chassis.pid_turn_set(-94, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_turn_set(-86, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_turn_set(-92, TURN_SPEED);
  chassis.pid_wait_quick();
  pros::delay(1300);
  chassis.pid_drive_set(-42, DRIVE_SPEED);
  chassis.pid_wait();
  scorer.move(-127);
  Match_loader.retract();
  pros::delay(2500);
  scorer.move(0);
  intake.move(0);
  
  // Travel #2
  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-180, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(94, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(74, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  
  // Matchloader #3 + scoring
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait();
  Match_loader.extend();
  pros::delay(300);
  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(2500);
  chassis.pid_turn_set(88, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(-42, DRIVE_SPEED);
  chassis.pid_wait();
  scorer.move(-127);
  chassis.pid_turn_set(94, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_turn_set(86, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick();
  Match_loader.retract();
  pros::delay(2500);
  scorer.move(0);
  intake.move(0);

  // Parking + zone clear
  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(45, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  scorer.move(-127);
  chassis.pid_turn_set(25, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(18, 100);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(4, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(35, DRIVE_SPEED);
  chassis.pid_wait_quick();
  pros::delay(1000);
  intake.move(0);
  scorer.move(0);
  
}

void comp_aut_right() {
  chassis.pid_drive_set(33, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  Match_loader.extend();
  intake.move(-127);
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait();
  
  pros::delay(300);
  
  chassis.pid_drive_set(-33, DRIVE_SPEED);
  chassis.pid_wait();
  Match_loader.retract();
  scorer.move(-127);
  pros::delay(2500);
  scorer.move(0);
  intake.move(0);  
  
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-145, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  chassis.pid_drive_set(49, DRIVE_SPEED);
  chassis.pid_wait_until(24);
  Match_loader.extend();
  chassis.pid_wait_until(32);
  Match_loader.retract();
  chassis.pid_speed_max_set(70);
  chassis.pid_wait();
  
  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(20, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(180, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(24, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(28, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  
}

void comp_aut_left() {
  chassis.pid_drive_set(33, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  Match_loader.extend();
  chassis.pid_turn_set(270, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait();
  
  pros::delay(300);
  
  chassis.pid_drive_set(-33, DRIVE_SPEED);
  chassis.pid_wait();
  Match_loader.retract();
  scorer.move(-127);
  pros::delay(2500);
  scorer.move(0);
  intake.move(0);  
  
  chassis.pid_drive_set(16, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(145, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  chassis.pid_drive_set(49, DRIVE_SPEED);
  chassis.pid_wait_until(24);
  Match_loader.extend();
  chassis.pid_wait_until(32);
  Match_loader.retract();
  
  chassis.pid_drive_set(-10, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-135, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(33, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-90, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(5, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  
}

void One_Forwards() {
  chassis.pid_drive_set(12, DRIVE_SPEED);
  chassis.pid_wait();
}




void Drive_Slewdiff_Test() {
  for (int i = 1; i <= 4; ++i) {
    chassis.pid_drive_set(24, DRIVE_SPEED);
    chassis.pid_wait();

    chassis.pid_drive_set(-24, DRIVE_SPEED, true);
    chassis.pid_wait();
  }
}

void Turn_Slewdiff_Test() {
  for (int i = 1; i <= 4; ++i) {
    chassis.pid_turn_set(90, TURN_SPEED);
    chassis.pid_wait();

    chassis.pid_turn_set(-90, TURN_SPEED, true);
    chassis.pid_wait();
  }
}

void Odom_Point_Distance_Test() {
  chassis.pid_odom_set({{0, 24}, fwd, ODOM_SPEED});
  chassis.pid_wait();

  chassis.pid_odom_set({{0, 0}, fwd, ODOM_SPEED});
  chassis.pid_wait();

  chassis.pid_odom_set({{0, 24}, rev, ODOM_SPEED});
  chassis.pid_wait();
  
  chassis.pid_odom_set({{0, 0}, rev, ODOM_SPEED});
  chassis.pid_wait();

}

void Odom_Slew_Test_And_Passpoints() {
  chassis.pid_odom_set({{{-8, 12}, fwd, ODOM_SPEED},
                        {{8, 24}, fwd, ODOM_SPEED},
                        {{0, 0, 0}, fwd, ODOM_SPEED}}
                        , true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0, 0}, rev, ODOM_SPEED});
  chassis.pid_wait();
}