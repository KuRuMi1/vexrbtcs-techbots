#include "v5.h"
#include "v5_vcs.h"
#include "robot-config.h"
#include "stdlib.h"
#include "math.h"
#include "keyBinds.h"

vex::brain brian = vex::brain();
vex::competition Competition = vex::competition();
vex::controller Controller = vex::controller();

vex::motor leftmotor( vex::PORT1, vex::gearSetting::ratio18_1, false );
vex::motor rightmotor( vex::PORT2, vex::gearSetting::ratio18_1, true );
vex::motor liftmotor1( vex::PORT3, vex::gearSetting::ratio18_1, false );
vex::motor liftmotor2( vex::PORT4, vex::gearSetting::ratio18_1, false );
vex::motor clawmotor( vex::PORT5, vex::gearSetting::ratio18_1, false );
vex::motor clawtiltmotor( vex::PORT6, vex::gearSetting::ratio18_1, false );

int main() {
 Competition.autonomous( atonomous );
 Competition.drivercontrol( usercontrol );
 KeyBind_Handler key;
 Controller.ButtonL1.pressed( key.ButtonL1Pressed );
 Controller.ButtonR1.pressed( key.ButtonR1Pressed );
 Controller.ButtonL2.pressed( key.ButtonL2Pressed );
 Controller.ButtonR2.pressed( key.ButtonR2Pressed );
 Controller.ButtonX.pressed( key.ButtonXPressed );
 Controller.ButtonY.pressed( key.ButtonYPressed );
//  clawtiltmotor.rotateTo( -27, vex::rotationUnits::deg, false );
//  usercontrol();
}

void atonomous() {
  leftmotor.rotateFor( vex::directionType::rev, 1000, vex::rotationUnits::deg );
  rightmotor.rotateFor( vex::directionType::rev, 1000, vex::rotationUnits::deg );

  leftmotor.rotateFor( vex::directionType::fwd, 1000, vex::rotationUnits::deg );
  rightmotor.rotateFor( vex::directionType::fwd, 1000, vex::rotationUnits::deg );
}

void usercontrol() {
  while( true )
  {
    drive();
    // lift();
    vex::task::sleep( 100 );
  }
}

void drive() {
  // Declare variables
  int LJSspeed = Controller.Axis3.value(), RJSspeed = Controller.Axis2.value();
  // Create a offset from -10 to 10 to accurately move the robot
  if( abs( LJSspeed ) < 10 ) LJSspeed = 0;
  if( abs( RJSspeed ) < 10 ) RJSspeed = 0;
   // Clear the controller's screen
  Controller.Screen.clearScreen();
  // Set the controller's screen cursor to 1rd line
  Controller.Screen.setCursor( 1, 1 );
  // Print the rotation value
  Controller.Screen.print( "B. Battery: %d%%", brian.Battery.capacity( vex::percentUnits::pct ) );
  // If the driver moves the joysticks
  if( LJSspeed != 0 || RJSspeed != 0 )
  {
    // Create a constraint for the maximum speed
    if( LJSspeed > 45 )
    {
      int temp = LJSspeed - 45;
      LJSspeed = LJSspeed - temp;
    }
    else if( LJSspeed < -45 )
    {
      int temp = LJSspeed + 45;
      LJSspeed = LJSspeed - temp;
    }
    if( RJSspeed > 45 )
    {
      int temp = RJSspeed - 45;
      RJSspeed = RJSspeed - temp;
    }
    else if( RJSspeed < -45 )
    {
      int temp = RJSspeed + 45;
      RJSspeed = RJSspeed - temp;
    }
    // If the driver moves forward
    if( LJSspeed > 0 ) leftmotor.spin( vex::directionType::fwd, LJSspeed, vex::velocityUnits::pct );
    else if( LJSspeed < 0 ) leftmotor.spin( vex::directionType::rev, abs( LJSspeed ), vex::velocityUnits::pct ); // Use the absolute value function to use a positive value in order to spin the correct direction
    // If the driver moves backward
    if( RJSspeed > 0 ) rightmotor.spin( vex::directionType::fwd, RJSspeed, vex::velocityUnits::pct );
    else if( RJSspeed < 0 ) rightmotor.spin( vex::directionType::rev, abs( RJSspeed ), vex::velocityUnits::pct ); // Use the absolute value function to use a positive value in order to spin the correct direction
  }
  else
  {
    // Stop the wheels if they're spinning
    leftmotor.stop();
    rightmotor.stop();
  }
}

/* void lift()
{
  if( Controller.ButtonL1.pressing() )
  {
    liftmotor1.spin( vex::directionType::fwd, 30, vex::velocityUnits::pct );
    liftmotor2.spin( vex::directionType::fwd, 30, vex::velocityUnits::pct );
  }
  else if( Controller.ButtonR1.pressing() )
  {
    liftmotor1.spin( vex::directionType::rev, 30, vex::velocityUnits::pct );
    liftmotor2.spin( vex::directionType::rev, 30, vex::velocityUnits::pct );
  }
} */
