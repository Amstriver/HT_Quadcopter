#include "ALL_DATA.h" 
#include "control.h"
#include "pwm.h"
#include "pid.h"
#include "myMath.h"

//extern _st_Mpu WtIMU;   //WtIMUԭʼ����
//extern _st_AngE Angle;
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
	
      pidRateX.measured = WtIMU.gyroX * Gyro_G; //�ڻ�����ֵ �Ƕ�/��
			pidRateY.measured = WtIMU.gyroY * Gyro_G;
			pidRateZ.measured = WtIMU.gyroZ * Gyro_G;
		
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


#define MOTOR1 motor_PWM_Value[0] 
#define MOTOR2 motor_PWM_Value[1] 
#define MOTOR3 motor_PWM_Value[2] 
#define MOTOR4 motor_PWM_Value[3] 

void MotorControl(void)
{	
		MOTOR1 = MOTOR2 = MOTOR3 = MOTOR4 = HTCFG_PWM_TM_RELOAD * 0.85;  //��100����̬����
					
//����������������ȡ���ڵ��PWM�ֲ���ɿ�������ϵ���뿴�ɿ�������ϵͼ�⣬���ĸ����PWM�ֲ��ֲ�	
//           ��ͷ      
//   PWM3     ��       PWM1
//      *           *
//      	*       *
//    		  *   *
//      			*  
//    		  *   *
//      	*       *
//      *           *
//    PWM4           PWM2			
//		pidRateX.out ����Ǵ���PID��� �������ң����Կ���1 2��3 4������������ͬ��ͬ��
//    pidRateY.out �����Ǵ���PID��� ����ǰ�󣬿��Կ���2 3��1 4��ǰ��������ͬ��ͬ��
//		pidRateZ.out ����Ǵ���PID��� ������ת�����Կ���2 4��1 3������Խ��ߵ��ͬ��ͬ��	

// ������ȡ�����㷨��� ������������Ļ�  ��ǰ�ɱ�Ȼ��β�������������,���ҷɱ�Ȼ����������������		

		MOTOR1 +=    + pidRateX.out + pidRateY.out + pidRateZ.out;//; ��̬����������������Ŀ�����
		MOTOR2 +=    + pidRateX.out - pidRateY.out - pidRateZ.out ;//;
		MOTOR3 +=    - pidRateX.out + pidRateY.out - pidRateZ.out;
		MOTOR4 +=    - pidRateX.out - pidRateY.out + pidRateZ.out;//;

//		MOTOR1 +=    + pidRateX.out;
//		MOTOR2 +=    + pidRateX.out;
//		MOTOR3 +=    - pidRateX.out;
//		MOTOR4 +=    - pidRateX.out;
	
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH0, LIMIT(MOTOR1,HTCFG_PWM_TM_RELOAD * 0.75,HTCFG_PWM_TM_RELOAD * 0.85));
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH1, LIMIT(MOTOR2,HTCFG_PWM_TM_RELOAD * 0.75,HTCFG_PWM_TM_RELOAD * 0.85));
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH2, LIMIT(MOTOR3,HTCFG_PWM_TM_RELOAD * 0.75,HTCFG_PWM_TM_RELOAD * 0.85));
	TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH3, LIMIT(MOTOR4,HTCFG_PWM_TM_RELOAD * 0.75,HTCFG_PWM_TM_RELOAD * 0.85));
} 

/************************************END OF FILE********************************************/ 
