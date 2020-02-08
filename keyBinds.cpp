#include "robot-config.h"
#include "keyBinds.h"

void KeyBind_Handler::ButtonL1Pressed()
{
  // Set the velocity
  liftmotor1.setMaxTorque( 200, vex::percentUnits::pct );
  liftmotor2.setMaxTorque( 200, vex::percentUnits::pct );
  /* liftmotor1.setVelocity( 100, vex::velocityUnits::pct );
  liftmotor2.setVelocity( 100, vex::velocityUnits::pct ); */
  // Lift the casket up
  liftmotor1.rotateFor( vex::directionType::fwd, 620, vex::rotationUnits::deg );
  liftmotor2.rotateFor( vex::directionType::fwd, 620, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonR1Pressed()
{
  // Set the velocity
  liftmotor1.setMaxTorque( 200, vex::percentUnits::pct );
  liftmotor2.setMaxTorque( 200, vex::percentUnits::pct );
  /* liftmotor1.setVelocity( 100, vex::velocityUnits::pct );
  liftmotor2.setVelocity( 100, vex::velocityUnits::pct ); */
  // Lift the casket down
  liftmotor1.rotateFor( vex::directionType::rev, 620, vex::rotationUnits::deg );
  liftmotor2.rotateFor( vex::directionType::rev, 620, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonL2Pressed()
{
  // Set the velocity
  clawtiltmotor.setVelocity( 20, vex::percentUnits::pct );
  // Close the claw
  clawtiltmotor.rotateTo( 255, vex::rotationUnits::deg );
  if( clawtiltmotor.isDone() ) clawtiltmotor.stop();
}

void KeyBind_Handler::ButtonR2Pressed()
{
  // Set the velocity
  clawtiltmotor.setVelocity( 20, vex::percentUnits::pct );
  // Open the claw
  // clawtiltmotor.rotateFor( vex::directionType::rev, 255, vex::rotationUnits::deg );
  clawtiltmotor.rotateTo( 0, vex::rotationUnits::deg );
  if( clawtiltmotor.isDone() ) clawtiltmotor.stop();
}

void KeyBind_Handler::ButtonXPressed()
{
  // Set velocity
  clawmotor.setVelocity( 30, vex::percentUnits::pct );
  // Rotate claw down
  clawmotor.rotateTo( -260, vex::rotationUnits::deg, false );
}

void KeyBind_Handler::ButtonYPressed()
{
  // Set velocity
  clawmotor.setVelocity( 50, vex::percentUnits::pct );
  // Rotate claw up
  clawmotor.rotateTo( 0, vex::rotationUnits::deg, false );
}

// Buttons released

/* void KeyBind_Handler::ButtonL2Released()
{
  // Stop the motor
  clawtiltmotor.stop();
}

void KeyBind_Handler::ButtonR2Released()
{
  // Stop the motor
  clawtiltmotor.stop();
} */
