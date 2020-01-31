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
  // Open the claw
  clawmotor.rotateFor( vex::directionType::rev, 180, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonR2Pressed()
{
  // Close the calw
  clawmotor.rotateFor( vex::directionType::fwd, 180, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonXPressed()
{
  // Rotate claw up
  clawtiltmotor.rotateFor( vex::directionType::fwd, 720, vex::rotationUnits::deg );
}

void KeyBind_Handler::ButtonYPressed()
{
  // Rotate claw down
  clawtiltmotor.rotateFor( vex::directionType::rev, 720, vex::rotationUnits::deg );
}
