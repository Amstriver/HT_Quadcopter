#include "Init.h"
#include "ALL_DATA.h"


volatile uint32_t SysTick_count; //系统时间计数
_st_Mpu WtIMU;   //WtIMU原始数据
_st_AngE Angle;    //当前角度姿态值

int16_t motor_PWM_Value[4];


PidObject pidRateX; //内环PID数据
PidObject pidRateY;
PidObject pidRateZ;

PidObject pidPitch; //外环PID数据
PidObject pidRoll;
PidObject pidYaw;


void pid_param_Init(void); //PID控制参数初始化，改写PID并不会保存数据，请调试完成后直接在程序里更改 再烧录到飞控

void ALL_Init(void)
{
	pid_param_Init();       //PID参数初始化
	
	delay_ms(200);
	USARTx_Init();  // 初始化USART1接口
  PWM_Init();
	PWM_Cmd(ENABLE);  // 设置PWM打开状态
  Motor_Unlock_init(PWM_CH0, PWM_CH1, PWM_CH2, PWM_CH3);  // 电调解锁
	LED_Init();
	Timer_Init();
	OLED_Init();
	OLED_Display_On();
	OLED_Clear(0);
}





////PID在此处修改
void pid_param_Init(void)//PID参数初始化
{
	pidRateX.kp = 3.f;
	pidRateY.kp = 3.f;
	pidRateZ.kp = 6.0f;
	
//	pidRateX.ki = 0.05f;
//	pidRateY.ki = 0.05f;
//	pidRateZ.ki = 0.02f;	
	
	pidRateX.kd = 0.24f;
	pidRateY.kd = 0.24f;
	pidRateZ.kd = 0.3f;	
	
//	pidPitch.kp = 10.0f;
//	pidRoll.kp = 10.0f;
//	pidYaw.kp = 8.0f;	


}
