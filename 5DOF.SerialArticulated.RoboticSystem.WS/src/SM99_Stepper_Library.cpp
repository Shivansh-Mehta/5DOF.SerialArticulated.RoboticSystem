#include "SM99_Stepper_Library.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

StepperMotor_NEMA_17_23::StepperMotor_NEMA_17_23(uint8_t motorID, uint8_t* pin_array_ptr) :
//initiliazation for motor variables
m_motorID(motorID),
m_pin(pin_array_ptr)
{
    for(uint8_t i=0; i<3; ++i)
    {
        pinMode((uint8_t)*(m_pin+i), OUTPUT);
    }
    StepperMotor_NEMA_17_23::SetState(OFF);
}
    
void StepperMotor_NEMA_17_23::GetDirection(Direction &dr)
{
    dr = m_dr;
} 

void StepperMotor_NEMA_17_23::SetDirection(Direction dr)
{
    m_dr = dr;
    if(dr==CW) 
    {
        digitalWrite((uint8_t)*(m_pin+2), HIGH);
    }
    else
    {
        digitalWrite((uint8_t)*(m_pin+2), LOW);
    }
    Serial.print("Motor "); Serial.print(m_motorID); Serial.print(" : ");
    Serial.print("Direction : "); PrintDirectionEnum(dr);
    Serial.println();
}

void StepperMotor_NEMA_17_23::GetState(MotorSwitch &status)
{
    status = m_status;
} 

void StepperMotor_NEMA_17_23::SetState(MotorSwitch status)
{        
    m_status = status;
    if(status==OFF) 
    {
        digitalWrite((uint8_t)*(m_pin), HIGH);
    }
    else
    {
        digitalWrite((uint8_t)*(m_pin), LOW);
    }
    Serial.print("Motor "); Serial.print(m_motorID); Serial.print(" : ");
    Serial.print("State : "); PrintStatusEnum(status);
    Serial.println();
}

void StepperMotor_NEMA_17_23::Drive(double degrees)
{        
    if(degrees<0) 
    {
        this->SetDirection(CW); degrees*=-1;
    }
    else this->SetDirection(CCW); 
    double unitPulses = 1.8/32;
    uint8_t steps = degrees/unitPulses;
    for(uint8_t i=0; i<steps; ++i)
    {
        digitalWrite((uint8_t)*(m_pin+1), HIGH);
        delayMicroseconds(500);
        digitalWrite((uint8_t)*(m_pin+1), LOW);
        delayMicroseconds(500);
    }
    Serial.print("Motor "); Serial.print(m_motorID); Serial.print(" : ");
    Serial.print("Degrees moved : "); 
    Serial.print(degrees);
    Serial.println();
}

void StepperMotor_NEMA_17_23::PrintDirectionEnum(Direction printenum)
{
    if(printenum == CW) Serial.print("Clockwise");
    else Serial.print("Counter-Clockwise");
}

void StepperMotor_NEMA_17_23::PrintStatusEnum(MotorSwitch printenum)
{
    if(printenum == ON) Serial.print("Enabled");
    else Serial.print("Disabled"); 
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

StepperMotor_28BYJ_48::StepperMotor_28BYJ_48(uint8_t motorID, uint8_t* pin_array_ptr) :
//initiliazation for motor variables
m_motorID(motorID),
m_pin(pin_array_ptr)
{
    for(uint8_t i=0; i<4; ++i)
    {
        pinMode((uint8_t)*(m_pin+i), OUTPUT);
    }
    StepperMotor_28BYJ_48::SetState(OFF);
}
    
void StepperMotor_28BYJ_48::GetDirection(Direction &dr)
{
    dr = m_dr;
} 

void StepperMotor_28BYJ_48::SetDirection(Direction dr)
{
    m_dr = dr;
    Serial.print("Motor "); Serial.print(m_motorID); Serial.print(" : ");
    Serial.print("Direction : "); PrintDirectionEnum(dr);
    Serial.println();
}

void StepperMotor_28BYJ_48::GetState(MotorSwitch &status)
{
    status = m_status;
} 

void StepperMotor_28BYJ_48::SetState(MotorSwitch status)
{     
    m_status = status;   
    if(status==OFF) 
    {
        for(uint8_t i=0; i<4; ++i) digitalWrite((uint8_t)*(m_pin), LOW);
    }
    Serial.print("Motor "); Serial.print(m_motorID); Serial.print(" : ");
    Serial.print("State : "); PrintStatusEnum(status);
    Serial.println();
}

void StepperMotor_28BYJ_48::Drive(double degrees)
{      
    if(m_status==ON)  
    {
        if(degrees<0) 
        {
            this->SetDirection(CW); degrees*=-1;
        }
        else this->SetDirection(CCW); 
        double unitPulses = 5.625/8;
        int steps = (int) degrees/unitPulses;

        for(int i=0; i<steps; ++i) OneStep();
        
        Serial.print("Motor "); Serial.print(m_motorID); Serial.print(" : ");
        Serial.print("Degrees moved : "); 
        Serial.print(degrees);
        Serial.println();
    }
}

void StepperMotor_28BYJ_48::PrintDirectionEnum(Direction printenum)
{
    if(printenum == CW) Serial.print("Clockwise");
    else Serial.print("Counter-Clockwise");
}

void StepperMotor_28BYJ_48::PrintStatusEnum(MotorSwitch printenum)
{
    if(printenum == ON) Serial.print("Enabled");
    else Serial.print("Disabled"); 
}

void StepperMotor_28BYJ_48::OneStep()
{
    if(m_dr==CCW)
    {
        ActivateDriverPins(1,0,0,0); delay(5);
        ActivateDriverPins(1,1,0,0); delay(5);
        ActivateDriverPins(0,1,0,0); delay(5);
        ActivateDriverPins(0,1,1,0); delay(5);
        ActivateDriverPins(0,0,1,0); delay(5);
        ActivateDriverPins(0,0,1,1); delay(5);
        ActivateDriverPins(0,0,0,1); delay(5);
        ActivateDriverPins(1,0,0,1); delay(5);
    }
    else if(m_dr==CW)
    {
        ActivateDriverPins(1,0,0,0); delay(5);
        ActivateDriverPins(1,0,0,1); delay(5);
        ActivateDriverPins(0,0,0,1); delay(5);
        ActivateDriverPins(0,0,1,1); delay(5);
        ActivateDriverPins(0,0,1,0); delay(5);
        ActivateDriverPins(0,1,1,0); delay(5);
        ActivateDriverPins(0,1,0,0); delay(5);
        ActivateDriverPins(1,1,0,0); delay(5);
    }
}

void StepperMotor_28BYJ_48::ActivateDriverPins(uint8_t coil1, uint8_t coil2, uint8_t coil3, uint8_t coil4)
{
    if(coil1) digitalWrite((uint8_t)*(m_pin+0), HIGH); else digitalWrite((uint8_t)*(m_pin+0), LOW);
    if(coil2) digitalWrite((uint8_t)*(m_pin+1), HIGH); else digitalWrite((uint8_t)*(m_pin+1), LOW);
    if(coil3) digitalWrite((uint8_t)*(m_pin+2), HIGH); else digitalWrite((uint8_t)*(m_pin+2), LOW);
    if(coil4) digitalWrite((uint8_t)*(m_pin+3), HIGH); else digitalWrite((uint8_t)*(m_pin+3), LOW);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
