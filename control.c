#include "ALL_DATA.h" 
#include "control.h"
#include "pwm.h"
#include "pid.h"
#include "myMath.h"

//------------------------------------------------------------------------------
PidObject *(pPidObject[])={&pidRateX,&pidRateY,&pidRateZ,&pidRoll,&pidPitch,&pidYaw   //�ṹ�����飬��ÿһ�������һ��pid�ṹ�壬�����Ϳ���������������PID��������  �������ʱ������λpid�������ݣ�����������仰�����þͿ�����
};
/**************************************************************
 *  flight control
 * @param[in] 
 * @param[out] 
 * @return     
 ***************************************************************/
void FlightPidControl(float dt)
{
	
      pidRateX.measured = WtIMU.gyroX * Gyro_G; //�ڻ�����ֵ �Ƕ�/�� Roll
			pidRateY.measured = WtIMU.gyroY * Gyro_G;  // Pitch
			pidRateZ.measured = WtIMU.gyroZ * Gyro_G;  // Yaw
		
			pidPitch.measured = Angle.pitch; //�⻷����ֵ ��λ���Ƕ�
		  pidRoll.measured = Angle.roll;
			pidYaw.measured = Angle.yaw;
		
		 	pidUpdate(&pidRoll,dt);    //����PID�������������⻷	�����PID		
			pidRateX.desired = pidRoll.out; //���⻷��PID�����Ϊ�ڻ�PID������ֵ��Ϊ����PID
			pidUpdate(&pidRateX,dt);  //�ٵ����ڻ�

		 	pidUpdate(&pidPitch,dt);    //����PID�������������⻷	������PID	
			pidRateY.desired = pidPitch.out;  
			pidUpdate(&pidRateY,dt); //�ٵ����ڻ�

			CascadePID(&pidRateZ,&pidYaw,dt);	//Ҳ����ֱ�ӵ��ô���PID����������

}


#define MOTOR1 motor_PWM_Value[0]  // PC4 
#define MOTOR2 motor_PWM_Value[1]  // PC5
#define MOTOR3 motor_PWM_Value[2]  // PC8 
#define MOTOR4 motor_PWM_Value[3]  // PC9

void MotorControl(void)
{	
		MOTOR1 = MOTOR2 = MOTOR3 = MOTOR4 = HTCFG_PWM_TM_RELOAD * 0.85;  // PWM��ʼֵ
					
//����������������ȡ���ڵ��PWM�ֲ���ɿ�������ϵ��
//           ��ͷ��USB�����Եĵط���      
//   PC5     ��       PC4
//      *           *
//      	*       *
//    		  *   *
//      			*  
//    		  *   *
//      	*       *
//      *           *
//   PC9              PC8			
  // �˴� wt_Imu λ�÷ŷ�������ǰ��ΪRoll������ΪPitch
////		pidRateX.out ����Ǵ���PID��� ����ǰ�󣬿��Կ���PC5 PC4��PC9 PC8��ǰ��������ͬ��ͬ��
////    pidRateY.out �����Ǵ���PID��� �������ң����Կ���PC5 PC9��PC4 PC8������������ͬ��ͬ��

// ������ȡ�����㷨��� ������������Ļ�  ��ǰ�ɱ�Ȼ��β�������������,���ҷɱ�Ȼ����������������		

//		MOTOR1 +=    + pidRateX.out + pidRateY.out + pidRateZ.out;//; ��̬����������������Ŀ�����
//		MOTOR2 +=    + pidRateX.out - pidRateY.out - pidRateZ.out ;//;
//		MOTOR3 +=    - pidRateX.out + pidRateY.out - pidRateZ.out;
//		MOTOR4 +=    - pidRateX.out - pidRateY.out + pidRateZ.out;//;
  // pidRateX.out ---> ��ͷǰ��ͺ���   pidRateY.out ---> ������ڻ��Ұ�
		MOTOR1 +=    + pidRateX.out + pidRateY.out;
		MOTOR2 +=    + pidRateX.out - pidRateY.out;
		MOTOR3 +=    - pidRateX.out + pidRateY.out;
		MOTOR4 +=    - pidRateX.out - pidRateY.out;
	
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH0, LIMIT(MOTOR1,HTCFG_PWM_TM_RELOAD * 0.60,HTCFG_PWM_TM_RELOAD * 0.85));  // PC4
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH1, LIMIT(MOTOR2,HTCFG_PWM_TM_RELOAD * 0.60,HTCFG_PWM_TM_RELOAD * 0.85));  // PC5 
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH2, LIMIT(MOTOR3,HTCFG_PWM_TM_RELOAD * 0.60,HTCFG_PWM_TM_RELOAD * 0.85));  // PC8
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH3, LIMIT(MOTOR4,HTCFG_PWM_TM_RELOAD * 0.60,HTCFG_PWM_TM_RELOAD * 0.85));  // PC9  
} 

/************************************END OF FILE********************************************/ 
