/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Paul Rodriguez                                            */
/*    Created:      Mon Oct 28 2019                                           */
/*    Description:  November 2 Tournament (Tower Takedown)                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include header files
#include "robot-config.h"
#include "ui.h"
#include "keyBinds.h"
// #include "visionSensor.h"
#include "stdlib.h"
#include "math.h"

// Define the stuff completely
vex::brain Brain = vex::brain();
vex::competition Competition = vex::competition();
vex::controller Controller1 = vex::controller();

const int _SPEED = 15;

vex::motor LFMotor( vex::PORT1, vex::gearSetting::ratio18_1, false );
vex::motor LRMotor( vex::PORT2, vex::gearSetting::ratio18_1, false );
vex::motor RFMotor( vex::PORT3, vex::gearSetting::ratio18_1, true );
vex::motor RRMotor( vex::PORT4, vex::gearSetting::ratio18_1, true );
vex::motor LiftMotor( vex::PORT5, vex::gearSetting::ratio18_1, true );
vex::motor LeftHandMotor( vex::PORT6, vex::gearSetting::ratio18_1, false );
vex::motor RightHandMotor( vex::PORT7, vex::gearSetting::ratio18_1, true );

vex::motor _motors[] = { LFMotor, LRMotor, RFMotor, RRMotor, LiftMotor, LeftHandMotor, RightHandMotor };

vex::motor_group LeftSideMotors( LFMotor, LRMotor );
vex::motor_group RightSideMotors( RFMotor, RRMotor );
vex::motor_group ArmMotors( LeftHandMotor, RightHandMotor );

vex::motor_group _motor_groups[] = { LeftSideMotors, RightSideMotors, ArmMotors };

vex::directionType FORWARD = vex::directionType::fwd;
vex::directionType BACKWARD = vex::directionType::rev;
vex::velocityUnits PCT = vex::velocityUnits::pct;
vex::rotationUnits DEG = vex::rotationUnits::deg;

// Button definitions
button buttons[] = {
  { "dcontrol_b", 60, 40, 150, 150, false },
  { "auto_b", 280, 40, 150, 150, false }
};

double getDoublePrec( double value, double precision ) {
  return( floor( ( value * pow( 10, precision ) + 0.5  ) ) / pow( 10, precision ) ); // Limit a float's precision (round it up)
}

int findButton( int16_t xpos, int16_t ypos ) 
{
    int nButtons = sizeof(buttons) / sizeof(button);
    for( int index=0;index < nButtons;index++) 
    {
      button *pButton = &buttons[ index ];
      if( xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width) )
        continue;
      if( ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height) )
        continue;
      return index;
    }
    return -1;
}

void ScreenHandler_Pressed()
{
  // Store index to determine button presses
  int index;
  // Check if the user presses any of the buttons
  int screenX = Brain.Screen.xPosition(), screenY = Brain.Screen.yPosition();
  index = findButton( screenX, screenY );
  // Check if he pressed "Driver Control"
  switch( index )
  {
    case 0:
      // If you press "D. Control"
      usercontrol();
    break;
    case 1:
      // If you press "Auto."
      autonomous();
    break;
  }
}

// Our main function
int main()
{
  // Set the autonomous and driver control functions from the Competition object
  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );
  preAuton();
  // Prevent the main function from exiting with an infinite loop
  while( true ) {
    vex::task::sleep( 100 );
  }
}

//=====================================================================================================
 
// Pre-Autonomous Mode - when the program executes, before autonomous mode starts
void preAuton( void )
{
  // Define a keybind handler object
  KeyBind_Handler KeyBinds;
  // Set the keybinds from the controller
  Controller1.ButtonL1.pressed( KeyBinds.ButtonL1Pressed );
  Controller1.ButtonL2.pressed( KeyBinds.ButtonL2Pressed );
  Controller1.ButtonL2.released( KeyBinds.ButtonL2Released );
  Controller1.ButtonR1.pressed( KeyBinds.ButtonR1Pressed );
  Controller1.ButtonR2.pressed( KeyBinds.ButtonR2Pressed );
  Controller1.ButtonR2.released( KeyBinds.ButtonR2Released );
   // Define our UI object
  //UI _GUI;
  // Set the pressing callbacks from the brain's screen
  //Brain.Screen.pressed( ScreenHandler_Pressed );
  // Display the field in the brain
  //_GUI.TowerTakeoverDisplay();
  // Display the start menu (for practice)
  //_GUI.StartMenu();
  autonomous(); // For practice purposes; remove it when competing!
}
 
// Autonomous Mode - when the robot can operate by itself
void autonomous( void )
{
  /* // Calibrate the brightness of the vision sensor - may vary the enviroment during competitions
  visionSensor.setBrightness( 50 );
  // Set the signature(s) to the vision sensor
  visionSensor.setSignature( ORANGE_CUBE );
  visionSensor.setSignature( GREEN_CUBE );
  visionSensor.setSignature( YOUR_MAMA_CUBE );
  // Calculate the center of the vision sensor
  int screenCenter = 316 / 2;
  bool isLinedUp = false;
  // A boolean to determine if one signature failed
  // Create a loop if the robot is not lined up
  while( isLinedUp == false )
  {
    // Snap a picture
    visionSensor.takeSnapshot( GREEN_CUBE );
    // Check if the picture has a green cube in it
    if( visionSensor.objectCount != 0 ) 
    {
      // Now, we determine where is it located in the image to determine where our robot will move
      if( visionSensor.objects[0].centerX < screenCenter - 5 )
      {
        // There's a cube on our left, thus we'll spin the right motors
        _motor_groups[ MG_IDX::RSM ].spin( FORWARD, 20, PCT );
      }
      else if( visionSensor.objects[0].centerX > screenCenter + 5 )
      {
        // In this case, we've a cube on our right, thus spining the left motors
        _motor_groups[ MG_IDX::LSM ].spin( FORWARD, 20, PCT );
      } 
      else
      {
        // This code runs if the robot is lined up with the target (cube)
        isLinedUp = true;
        _motor_groups[ MG_IDX::LSM ].stop();
        _motor_groups[ MG_IDX::RSM ].stop();
      }
    }
  } */
  
}
 
// Driving Control Mode - when the controller controls the robot
void usercontrol( void )
{
  while( true )
  {
    drive();
    vex::task::sleep( 100 );
  }
}
 
void drive()
{
  // Declare variables
  int LJSspeed = Controller1.Axis3.value(), RJSspeed = Controller1.Axis2.value();
  // Create a offset from -10 to 10 to accurately move the robot
  if( abs( LJSspeed ) < 10 ) LJSspeed = 0;
  if( abs( RJSspeed ) < 10 ) RJSspeed = 0;
  // Clear the controller's screen
  Controller1.Screen.clearScreen();
  // Set the controller's screen cursor to 1rd line
  Controller1.Screen.setCursor( 1, 1 );
  // Print the rotation value
  Controller1.Screen.print( "B. Battery: %d%%", Brain.Battery.capacity( vex::percentUnits::pct ) );
  // If the driver moves the joysticks
  if( LJSspeed != 0 || RJSspeed != 0 )
  {
    // If the driver moves forward
    if( LJSspeed > 0 ) _motor_groups[ MG_IDX::LSM ].spin( FORWARD, LJSspeed, PCT );
    else if( LJSspeed < 0 ) _motor_groups[ MG_IDX::LSM ].spin( BACKWARD, abs( LJSspeed ), PCT ); // Use the absolute value function to use a positive value in order to spin the correct direction
    // If the driver moves backward
    if( RJSspeed > 0 ) _motor_groups[ MG_IDX::RSM ].spin( FORWARD, RJSspeed, PCT );
    else if( RJSspeed < 0 ) _motor_groups[ MG_IDX::RSM ].spin( BACKWARD, abs( RJSspeed ), PCT ); // Use the absolute value function to use a positive value in order to spin the correct direction
  }
  else
  {
    // Stop the wheels if they're spinning
    LeftSideMotors.stop();
    RightSideMotors.stop();
  }
}
