#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "v5.h"
#include "v5_vcs.h"

extern vex::brain brian;
extern vex::competition Competition;
extern vex::controller Controller;

extern vex::motor leftmotor;

extern vex::motor rightmotor;

extern vex::motor liftmotor;

extern vex::motor clawmotor;

extern vex::motor clawtiltmotor;

void atonomous();

void usercontrol();

void drive();

#endif // ROBOT_CONFIG_H
