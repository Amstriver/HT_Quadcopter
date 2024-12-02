#include "ALL_DATA.h" 
#include "control.h"
#include "pwm.h"
#include "pid.h"
#include "myMath.h"

//------------------------------------------------------------------------------
PidObject *(pPidObject[])={&pidRateX,&pidRateY,&pidRateZ,&pidRoll,&pidPitch,&pidYaw   //结构体数组，将每一个数组放一个pid结构体，这样就可以批量操作各个PID的数据了  比如解锁时批量复位pid控制数据，新手明白这句话的作用就可以了
};
/**************************************************************
 *  flight control
 * @param[in] 
 * @param[out] 
 * @return     
 ***************************************************************/
void FlightPidControl(float dt)
{
	
      pidRateX.measured = WtIMU.gyroX * Gyro_G; //内环测量值 角度/秒 Roll
			pidRateY.measured = WtIMU.gyroY * Gyro_G;  // Pitch
			pidRateZ.measured = WtIMU.gyroZ * Gyro_G;  // Yaw
		
			pidPitch.measured = Angle.pitch; //外环测量值 单位：角度
		  pidRoll.measured = Angle.roll;
			pidYaw.measured = Angle.yaw;
		
		 	pidUpdate(&pidRoll,dt);    //调用PID处理函数来处理外环	横滚角PID		
			pidRateX.desired = pidRoll.out; //将外环的PID输出作为内环PID的期望值即为串级PID
			pidUpdate(&pidRateX,dt);  //再调用内环

		 	pidUpdate(&pidPitch,dt);    //调用PID处理函数来处理外环	俯仰角PID	
			pidRateY.desired = pidPitch.out;  
			pidUpdate(&pidRateY,dt); //再调用内环

			CascadePID(&pidRateZ,&pidYaw,dt);	//也可以直接调用串级PID函数来处理

}


#define MOTOR1 motor_PWM_Value[0]  // PC4 
#define MOTOR2 motor_PWM_Value[1]  // PC5
#define MOTOR3 motor_PWM_Value[2]  // PC8 
#define MOTOR4 motor_PWM_Value[3]  // PC9

void MotorControl(void)
{	
		MOTOR1 = MOTOR2 = MOTOR3 = MOTOR4 = HTCFG_PWM_TM_RELOAD * 0.85;  // PWM初始值
					
//以下输出的脉冲分配取决于电机PWM分布与飞控坐标体系。
//           机头（USB口正对的地方）      
//   PC5     ♂       PC4
//      *           *
//      	*       *
//    		  *   *
//      			*  
//    		  *   *
//      	*       *
//      *           *
//   PC9              PC8			
  // 此处 wt_Imu 位置放反，导致前后为Roll，左右为Pitch
////		pidRateX.out 横滚角串级PID输出 控制前后，可以看出PC5 PC4和PC9 PC8，前后两组电机同增同减
////    pidRateY.out 俯仰角串级PID输出 控制左右，可以看出PC5 PC9和PC4 PC8，左右两组电机同增同减

// 正负号取决于算法输出 比如输出是正的话  往前飞必然是尾巴两个电机增加,往右飞必然是左边两个电机增加		

//		MOTOR1 +=    + pidRateX.out + pidRateY.out + pidRateZ.out;//; 姿态输出分配给各个电机的控制量
//		MOTOR2 +=    + pidRateX.out - pidRateY.out - pidRateZ.out ;//;
//		MOTOR3 +=    - pidRateX.out + pidRateY.out - pidRateZ.out;
//		MOTOR4 +=    - pidRateX.out - pidRateY.out + pidRateZ.out;//;
  // pidRateX.out ---> 机头前倾和后仰   pidRateY.out ---> 机身左摆或右摆
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
