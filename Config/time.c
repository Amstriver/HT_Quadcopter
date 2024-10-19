#include "time.h"
#include "led.h"
#include "control.h"
 
uint16_t count = 0;  // 计时
uint8_t led_flag = 0; // led进行翻转标志

void Timer_Init(void)
{	
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.BFTM1 = 1;  // 开启中断时钟
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	NVIC_EnableIRQ(BFTM1_IRQn);
	
	BFTM_SetCounter(HT_BFTM1, 0);
	//BFTM_SetCompare(HT_BFTM1, SystemCoreClock);  // 定时1s产生中断
	BFTM_SetCompare(HT_BFTM1, SystemCoreClock/1000);  // 定时1ms产生中断
	BFTM_IntConfig(HT_BFTM1, ENABLE);  // 使能中断
	BFTM_EnaCmd(HT_BFTM1, ENABLE);  // 使能BFTM
}

void BFTM1_IRQHandler(void)
{
		if(BFTM_GetFlagStatus(HT_BFTM1) != RESET )
		{	
		FlightPidControl(0.003f);
		MotorControl();		
			count++;			
			if(count == 1000) //1s
			{	
				//printf("-------------LED 1S FLASH TEST------------\n");		
				count = 0;
				if(led_flag == 0)
				{
					LED_ON(GPIO_PIN_14);
					led_flag = 1;
				}		
				else if(led_flag == 1)
				{
					led_flag = 0;
					LED_OFF(GPIO_PIN_14);
				}
			}
			BFTM_ClearFlag(HT_BFTM1);  // 清除中断标志
		}	
}
