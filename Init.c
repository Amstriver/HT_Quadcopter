#include "Init.h"
#include "ALL_DATA.h"


volatile uint32_t SysTick_count; //ϵͳʱ�����
_st_Mpu WtIMU;   //WtIMUԭʼ����
_st_AngE Angle;    //��ǰ�Ƕ���ֵ̬

int16_t motor_PWM_Value[4];


PidObject pidRateX; //�ڻ�PID����
PidObject pidRateY;
PidObject pidRateZ;

PidObject pidPitch; //�⻷PID����
PidObject pidRoll;
PidObject pidYaw;


void pid_param_Init(void); //PID���Ʋ�����ʼ������дPID�����ᱣ�����ݣ��������ɺ�ֱ���ڳ�������� ����¼���ɿ�

void ALL_Init(void)
{
	pid_param_Init();       //PID������ʼ��
	
	delay_ms(200);
	USARTx_Init();  // ��ʼ��USART1�ӿ�
  PWM_Init();
	PWM_Cmd(ENABLE);  // ����PWM��״̬
  Motor_Unlock_init(PWM_CH0, PWM_CH1, PWM_CH2, PWM_CH3);  // �������
	LED_Init();
	Timer_Init();
	OLED_Init();
	OLED_Display_On();
	OLED_Clear(0);
}





////PID�ڴ˴��޸�
void pid_param_Init(void)//PID������ʼ��
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
