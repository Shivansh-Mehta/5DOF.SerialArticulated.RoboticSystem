#ifndef SM99_STEPPER_LIBRARY_H
#define SM99_STEPPER_LIBRARY_H

#include <Arduino.h>

enum Direction 
{
    CW, CCW
};

enum MotorSwitch 
{
    ON, OFF
};

class StepperMotor_NEMA_17_23
{
    public:
    const uint8_t m_motorID;
    uint8_t* m_pin; // require array of uint8_t values with enable, step, direction pins respectively
    Direction m_dr;
    MotorSwitch m_status;

    StepperMotor_NEMA_17_23(uint8_t motorID, uint8_t* pin_array_ptr);

    void GetDirection(Direction &dr);
    void SetDirection(Direction dr);
    
    void GetState(MotorSwitch &status);
    void SetState(MotorSwitch status);

    void Drive(double degrees);
    void PrintDirectionEnum(Direction printenum);
    void PrintStatusEnum(MotorSwitch printenum);
};

class StepperMotor_28BYJ_48
{
    public:
    const uint8_t m_motorID;
    uint8_t* m_pin; // require array of uint8_t values with enable, pin1, pin2, pin3, pin4 respectively
    Direction m_dr;
    MotorSwitch m_status;

    StepperMotor_28BYJ_48(uint8_t motorID, uint8_t* pin_array_ptr);

    void GetDirection(Direction &dr);
    void SetDirection(Direction dr);
    
    void GetState(MotorSwitch &status);
    void SetState(MotorSwitch status);

    void Drive(double degrees);
    void OneStep();
    void ActivateDriverPins(uint8_t coil1, uint8_t coil2, uint8_t coil3, uint8_t coil4);
    void PrintDirectionEnum(Direction printenum);
    void PrintStatusEnum(MotorSwitch printenum);
};

#endif