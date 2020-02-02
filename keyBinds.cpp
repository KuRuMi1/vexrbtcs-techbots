#include "robot-config.h"
#include "keyBinds.h"

void KeyBind_Handler::ButtonL1Pressed()
{
  // Lift the casket up
  liftmotor1.rotateFor( vex::directionType::rev, 720, vex::rotationUnits::deg );
  liftmotor2.rotateFor( vex::directionType::rev, 720, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonR1Pressed()
{
  // Lift the casket down
  liftmotor1.rotateFor( vex::directionType::fwd, 720, vex::rotationUnits::deg );
  liftmotor2.rotateFor( vex::directionType::fwd, 720, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonL2Pressed()
{
  // Set the velocity
  clawmotor.setVelocity( 50, vex::percentUnits::pct );
  // Close the claw
  clawmotor.rotateTo( -120, vex::rotationUnits::deg, false );
}

void KeyBind_Handler::ButtonR2Pressed()
{
  // Set the velocity
  clawmotor.setVelocity( 50, vex::percentUnits::pct );
  // Open the claw
  clawmotor.rotateTo( 0, vex::rotationUnits::deg, false );
}

void KeyBind_Handler::ButtonXPressed()
{
  // Set velocity
  clawtiltmotor.setVelocity( 20, vex::percentUnits::pct );
  // Rotate claw down
  clawtiltmotor.rotateTo( -260, vex::rotationUnits::deg, false );
}

void KeyBind_Handler::ButtonYPressed()
{
  // Set velocity
  // clawtiltmotor.setVelocity( 50, vex::percentUnits::pct );
  // Rotate claw up
  clawtiltmotor.rotateTo( 0, vex::rotationUnits::deg, false );
}
