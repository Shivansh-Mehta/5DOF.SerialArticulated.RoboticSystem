//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <Arduino.h>
#include "SM99_PinDefinitions.h"
#include "SM99_Stepper_Library.h"
#include "SM99_Kinematics.h"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static uint8_t motorCount = 0;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void setup() {
  // put your setup code here, to run once:
  //++++++++++++++++++++++++++++++ beginning ++++++++++++++++++++++++++++++
  Init::init();
  Serial.begin(115200);
  Serial.println();
  //++++++++++++++++++++++++++++++ motor 1 setup ++++++++++++++++++++++++++++++
  uint8_t motor1_pin_array[] = 
  {
    stepper1_enable, stepper1_step, stepper1_direction
  };
  StepperMotor_NEMA_17_23* motor1 = new StepperMotor_NEMA_17_23(++motorCount, motor1_pin_array);
  //++++++++++++++++++++++++++++++ motor 2 setup ++++++++++++++++++++++++++++++
  uint8_t motor2_pin_array[] = 
  {
    stepper2_enable, stepper2_step, stepper2_direction
  };
  StepperMotor_NEMA_17_23* motor2 = new StepperMotor_NEMA_17_23(++motorCount, motor2_pin_array);
  //++++++++++++++++++++++++++++++ motor 3 setup ++++++++++++++++++++++++++++++
  uint8_t motor3_pin_array[] = 
  {
    stepper3_enable, stepper3_step, stepper3_direction
  };
  StepperMotor_NEMA_17_23* motor3 = new StepperMotor_NEMA_17_23(++motorCount, motor3_pin_array);
  //++++++++++++++++++++++++++++++ motor 4 setup ++++++++++++++++++++++++++++++
  uint8_t motor4_pin_array[] = 
  {
    stepper4_pin1, stepper4_pin2, stepper4_pin3, stepper4_pin4
  };
  StepperMotor_28BYJ_48* motor4 = new StepperMotor_28BYJ_48(++motorCount, motor4_pin_array);
  //++++++++++++++++++++++++++++++ motor 5 setup ++++++++++++++++++++++++++++++
  uint8_t motor5_pin_array[] = 
  {
    stepper5_pin1, stepper5_pin2, stepper5_pin3, stepper5_pin4
  };
  StepperMotor_28BYJ_48* motor5 = new StepperMotor_28BYJ_48(++motorCount, motor5_pin_array);
  //++++++++++++++++++++++++++++++ motor 6 setup ++++++++++++++++++++++++++++++
  uint8_t motor6_pin_array[] = 
  {
    stepper6_pin1, stepper6_pin2, stepper6_pin3, stepper6_pin4
  };
  StepperMotor_28BYJ_48* motor6 = new StepperMotor_28BYJ_48(++motorCount, motor6_pin_array);
  //++++++++++++++++++++++++++++++ kinematics ++++++++++++++++++++++++++++++
  Kinematics kinematics;

  double r12, r22, r23, xcoor, ycoor, zcoor;
  kinematics.GetUserInput(r12, r22, r23, xcoor, ycoor, zcoor);
  // kinematics.SetSpaceMatrix(0, -1, 0, 200, 20, 200);
  kinematics.SetSpaceMatrix(r12, r22, r23, xcoor, ycoor, zcoor);
  kinematics.CalculateJointAngles();

  motor1->SetState(ON);
  motor1->Drive(kinematics.m_angle1);
  motor1->SetState(OFF);

  motor2->SetState(ON);
  motor2->Drive(kinematics.m_angle2);
  motor2->SetState(OFF);

  motor3->SetState(ON);
  motor3->Drive(kinematics.m_angle3);
  motor3->SetState(OFF);

  motor4->SetState(ON);
  motor5->SetState(ON);
  motor4->Drive(kinematics.m_angle4);
  motor5->Drive(-kinematics.m_angle4);
  motor4->Drive(kinematics.m_angle5);
  motor5->Drive(kinematics.m_angle5);
  motor4->SetState(OFF);
  motor5->SetState(OFF);
  //++++++++++++++++++++++++++++++ finishing ++++++++++++++++++++++++++++++
  delete(motor1); motor1 = NULL;
  delete(motor2); motor2 = NULL;
  delete(motor3); motor3 = NULL;
  delete(motor4); motor4 = NULL;
  delete(motor5); motor5 = NULL;
  delete(motor6); motor6 = NULL;
  Serial.end();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loop() 
{
  // put your main code here, to run repeatedly:
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++