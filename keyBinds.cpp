/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       keyBinds.cpp                                              */
/*    Author:       Paul Rodriguez                                            */
/*    Created:      12 Nov 2019                                               */
/*    Description:  November 2 Tournament (Tower Takedown)                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include header files
#include "robot-config.h"
#include "keyBinds.h"

// Buttons pressed

void KeyBind_Handler::ButtonL1Pressed()
{
  // Lift the arm up
  _motors[ M_IDX::LM ].startRotateFor( FORWARD, 500, DEG );
}

void KeyBind_Handler::ButtonL2Pressed()
{
  // Move the arms backward - to pickup cubes
  _motor_groups[ MG_IDX::AM ].spin( BACKWARD, _SPEED * 5, PCT );
}

void KeyBind_Handler::ButtonR1Pressed()
{
  // Lift the arm down
  _motors[ M_IDX::LM ].startRotateFor( BACKWARD, 500, DEG ); 
}

void KeyBind_Handler::ButtonR2Pressed()
{
  // Move the arms forward - to spit out cubes
  _motor_groups[ MG_IDX::AM ].spin( FORWARD, _SPEED * 5, PCT );
}

// Buttons released

void KeyBind_Handler::ButtonL2Released()
{
  // Stop the motor
  _motor_groups[ MG_IDX::AM ].stop();
}

void KeyBind_Handler::ButtonR2Released()
{
  // Stop the motor
  _motor_groups[ MG_IDX::AM ].stop();
}
