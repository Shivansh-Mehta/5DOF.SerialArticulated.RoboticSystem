#ifndef SM99_PINDEFINITIONS_LIBRARY_H
#define SM99_PINDEFINITIONS_LIBRARY_H

#include <Arduino.h>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//stepper 1 is NEMA17 driven by TB6600 driver
#define stepper1_enable 1
#define stepper1_step 2
#define stepper1_direction 3
//stepper 2 is NEMA23 driven by TB6600 driver
#define stepper2_enable 4
#define stepper2_step 5
#define stepper2_direction 6
//stepper 3 is NEMA17 driven by TB6600 driver
#define stepper3_enable 7
#define stepper3_step 8
#define stepper3_direction 9
//stepper 4 is 28BYJ_48 driven by ULN2003 driver
#define stepper4_pin1 10
#define stepper4_pin2 11
#define stepper4_pin3 12
#define stepper4_pin4 13
//stepper 5 is 28BYJ_48 driven by ULN2003 driver
#define stepper5_pin1 14
#define stepper5_pin2 15
#define stepper5_pin3 16
#define stepper5_pin4 17
//stepper 6 is 28BYJ_48 driven by ULN2003 driver
#define stepper6_pin1 18
#define stepper6_pin2 19
#define stepper6_pin3 20
#define stepper6_pin4 21
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
namespace Init
{
  void init()
  {
    pinMode(stepper1_enable, OUTPUT); pinMode(stepper1_step, OUTPUT); pinMode(stepper1_direction, OUTPUT);
    pinMode(stepper2_enable, OUTPUT); pinMode(stepper2_step, OUTPUT); pinMode(stepper2_direction, OUTPUT);
    pinMode(stepper3_enable, OUTPUT); pinMode(stepper3_step, OUTPUT); pinMode(stepper3_direction, OUTPUT);
    pinMode(stepper4_pin1, OUTPUT); pinMode(stepper4_pin2, OUTPUT); pinMode(stepper4_pin3, OUTPUT); pinMode(stepper4_pin4, OUTPUT);
    pinMode(stepper5_pin1, OUTPUT); pinMode(stepper5_pin2, OUTPUT); pinMode(stepper5_pin3, OUTPUT); pinMode(stepper5_pin4, OUTPUT);
    pinMode(stepper6_pin1, OUTPUT); pinMode(stepper6_pin2, OUTPUT); pinMode(stepper6_pin3, OUTPUT); pinMode(stepper6_pin4, OUTPUT);

    digitalWrite(stepper1_enable, LOW); digitalWrite(stepper1_step, LOW); digitalWrite(stepper1_direction, LOW);
    digitalWrite(stepper2_enable, LOW); digitalWrite(stepper2_step, LOW); digitalWrite(stepper2_direction, LOW);
    digitalWrite(stepper3_enable, LOW); digitalWrite(stepper3_step, LOW); digitalWrite(stepper3_direction, LOW);
    digitalWrite(stepper4_pin1, LOW); digitalWrite(stepper4_pin2, LOW); digitalWrite(stepper4_pin3, LOW); digitalWrite(stepper4_pin4, LOW);
    digitalWrite(stepper5_pin1, LOW); digitalWrite(stepper5_pin2, LOW); digitalWrite(stepper5_pin3, LOW); digitalWrite(stepper5_pin4, LOW);
    digitalWrite(stepper6_pin1, LOW); digitalWrite(stepper6_pin2, LOW); digitalWrite(stepper6_pin3, LOW); digitalWrite(stepper6_pin4, LOW);
  }
}

#endif