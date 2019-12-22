/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       robot-config.h                                            */
/*    Author:       Paul Rodriguez                                            */
/*    Created:      1 Nov 2019                                                */
/*    Description:  November 2 Tournament (Tower Takedown)                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

// Include header files
#include "v5.h"
#include "v5_vcs.h"

// Prototype structures
typedef struct _button 
{
  std::string name;
  int xpos;
  int ypos;
  int width;
  int height;
  bool state;
} button;

// Prototype enumerations
enum M_IDX { LFM = 0, LRM, RFM, RRM, LM, LHM, RHM };
enum MG_IDX { LSM = 0, RSM, AM };

// Prototype the main objects
extern vex::brain Brain;
extern vex::competition Competition;
extern vex::controller Controller1;

// Prototype motor object(s)
extern vex::motor LFMotor;
extern vex::motor LRMotor;

extern vex::motor RFMotor;
extern vex::motor RRMotor;

extern vex::motor LiftMotor;

extern vex::motor LeftHandMotor;
extern vex::motor RightHandMotor;

// Prototype motor group(s)/drivertrain(s)
extern vex::motor_group LeftSideMotors;
extern vex::motor_group RightSideMotors;
extern vex::motor_group ArmMotors;

// Prototype variables related to the robot
extern const int _SPEED; // How fast the lift and arms can move

// Prototype an array to store our motors
extern vex::motor _motors[];
extern vex::motor_group _motor_groups[];

// Prototype enumeration objects
extern vex::directionType FORWARD;
extern vex::directionType BACKWARD;
extern vex::velocityUnits PCT;
extern vex::rotationUnits DEG;

// Function prototypes
void preAuton( void );
void autonomous( void );
void usercontrol( void );
void drive();
void lift();
double getFloatPrec( double value, double precision );
int findButton( int16_t xpos, int16_t ypos );
void ScreenHandler_Pressed();

#endif // ROBOT_CONFIG_H
