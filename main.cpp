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
vex::motor29 liftmotor1( brian.ThreeWirePort.G, false );
vex::motor29 liftmotor2( brian.ThreeWirePort.H, false );


int main() {
 Competition.autonomous( atonomous );
 Competition.drivercontrol( usercontrol );
 liftmotor1.spin( vex::directionType::fwd, 30, vex::velocityUnits::pct );
 liftmotor2.spin( vex::directionType::fwd, 30, vex::velocityUnits::pct );
 //usercontrol();
}

void atonomous() {
  
  
}

void usercontrol() {
  while( true )
  {
    drive();
    lift();
    vex::task::sleep( 100 );
  }
}

void drive() {
  // Declare variables
  int LJSspeed = Controller.Axis3.value(), RJSspeed = Controller.Axis2.value();
  // Create a offset from -10 to 10 to accurately move the robot
  if( abs( LJSspeed ) < 10 ) LJSspeed = 0;
  if( abs( RJSspeed ) < 10 ) RJSspeed = 0;
  Controller.Screen.clearScreen();
  Controller.Screen.setCursor( 1, 1 );
  // If the driver moves the joysticks
  if( LJSspeed != 0 || RJSspeed != 0 )
  {
    // Create a constraint for the maximum speed
    if( LJSspeed > 60 )
    {
      int temp = LJSspeed - 60;
      LJSspeed = LJSspeed - temp;
    }
    else if( LJSspeed < -60 )
    {
      int temp = LJSspeed + 60;
      LJSspeed = LJSspeed - temp;
    }
    if( RJSspeed > 60 )
    {
      int temp = RJSspeed - 60;
      RJSspeed = RJSspeed - temp;
    }
    else if( RJSspeed < -60 )
    {
      int temp = RJSspeed + 60;
      RJSspeed = RJSspeed - temp;
    }
    Controller.Screen.print( "LJ: %d RJ: %d", LJSspeed, RJSspeed );
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

void lift()
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
}
