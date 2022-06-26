#ifndef SM99_KINEMATICS_H
#define SM99_KINEMATICS_H

#include <Arduino.h>

class Kinematics 
{
    public:
    double m_xcoor = 0, m_ycoor = 0, m_zcoor = 0;
    double m_r12 = 0, m_r22 = 0, m_r23 = 0;
    double m_angle1 = 0, m_angle2 = 0, m_angle3 = 0, m_angle4 = 0, m_angle5 = 0;
    
    void SetSpaceMatrix(double r12, double r22, double r23, double xcoor, double ycoor, double zcoor);
    void CalculateJointAngles();
    void GetUserInput(double& r12, double& r22, double& r23, double& px, double& py, double& pz);
};

#endif 