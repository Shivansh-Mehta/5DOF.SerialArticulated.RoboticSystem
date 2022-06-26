#include "SM99_Kinematics.h"

#define d1 155.2
#define a3 180.48
#define a4 119.0

#define pi 3.14
#define rad2deg 180/pi

void Kinematics::SetSpaceMatrix(double r12, double r22, double r23, double xcoor, double ycoor, double zcoor)
{
    m_r12 = r12;
    m_r22 = r22;
    m_r23 = r23;
    m_xcoor = xcoor;
    m_ycoor = ycoor;
    m_zcoor = zcoor;

    Serial.print("Space Matrix values inputted : "); Serial.println();
    Serial.print("r12 : "); Serial.print(m_r12); Serial.println();
    Serial.print("r22 : "); Serial.print(m_r22); Serial.println();
    Serial.print("r23 : "); Serial.print(m_r23); Serial.println();
    Serial.print("X-Coordinate : "); Serial.print(m_xcoor); Serial.println();
    Serial.print("Y-Coordinate : "); Serial.print(m_ycoor); Serial.println();
    Serial.print("Z-Coordinate : "); Serial.print(m_zcoor); Serial.println();
}

void Kinematics::CalculateJointAngles()
{
    m_angle1 = atan(m_ycoor/m_zcoor); 
    m_angle3 = acos(((d1-m_zcoor)*(d1-m_zcoor) + m_xcoor*m_xcoor + m_ycoor*m_ycoor - a3*a3 - a4*a4)/(2*a3*a4)); 
    double temp = acos(((d1-m_zcoor)*(d1-m_zcoor) + m_xcoor*m_xcoor + m_ycoor*m_ycoor - a3*a3 + a4*a4)/(2*a4*sqrt((d1-m_zcoor)*(d1-m_zcoor) + m_xcoor*m_xcoor + m_ycoor*m_ycoor)));
    m_angle2 = - m_angle3 + atan((d1-m_zcoor)/(sqrt(m_xcoor*m_xcoor + m_ycoor*m_ycoor))) + temp; 
    m_angle4 = - m_angle2 - m_angle3 + asin((-m_r23*sqrt(m_xcoor*m_xcoor + m_ycoor*m_ycoor))/(m_ycoor)); 
    m_angle5 = acos((m_ycoor*m_r12 - m_xcoor*m_r22)/(sqrt(m_xcoor*m_xcoor + m_ycoor*m_ycoor))); 

    m_angle1 *= rad2deg;
    m_angle2 *= rad2deg;
    m_angle3 *= rad2deg;
    m_angle4 *= rad2deg;
    m_angle5 *= rad2deg;

    Serial.print("Joint Angles calculated : "); Serial.println();
    Serial.print("Joint 1 angle : "); Serial.print(m_angle1); Serial.println();
    Serial.print("Joint 2 angle : "); Serial.print(m_angle2); Serial.println();
    Serial.print("Joint 3 angle : "); Serial.print(m_angle3); Serial.println();
    Serial.print("Joint 4 angle : "); Serial.print(m_angle4); Serial.println();
    Serial.print("Joint 5 angle : "); Serial.print(m_angle5); Serial.println();
}

void Kinematics::GetUserInput(double& r12, double& r22, double& r23, double& px, double& py, double& pz)
{
  Serial.print("Input the following values of the transformation matrix: (Wait for input value acceptance for each variable, don't press ENTER) "); Serial.println();
  Serial.print("r12, r22, r23, px, py, pz"); Serial.println();
  while(Serial.available()==0) {} r12 = Serial.parseFloat();
  Serial.print("Inputted value of r12 : "); Serial.print(r12); Serial.println();
  while(Serial.available()==0) {} r22 = Serial.parseFloat();
  Serial.print("Inputted value of r22 : "); Serial.print(r22); Serial.println();
  while(Serial.available()==0) {} r23 = Serial.parseFloat();
  Serial.print("Inputted value of r23 : "); Serial.print(r23); Serial.println();
  while(Serial.available()==0) {} px = Serial.parseFloat();
  Serial.print("Inputted value of px : "); Serial.print(px); Serial.println();
  while(Serial.available()==0) {} py = Serial.parseFloat();
  Serial.print("Inputted value of py : "); Serial.print(py); Serial.println();
  while(Serial.available()==0) {} pz = Serial.parseFloat();
  Serial.print("Inputted value of pz : "); Serial.print(pz); Serial.println();
}