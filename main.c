/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board.h"
#include "pwm.h"
#include "delay.h"
#include "ht32f5xxxx_tm_type.h"
#include "oled.h"


/** @addtogroup HT32_Series_Peripheral_Examples HT32 Peripheral Examples
  * @{
  */

/** @addtogroup TM_Examples TM
  * @{
  */

/** @addtogroup PWM
  * @{
  */


/* Private function prototypes -----------------------------------------------------------------------------*/
void Delay(u32 uLoop);
void Motor_Unlock_init(TM_CH_Enum TM_CH_1, TM_CH_Enum TM_CH_2, TM_CH_Enum TM_CH_3, TM_CH_Enum TM_CH_4);

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
	
  PWM_Init();
  Motor_Unlock_init(PWM_CH0, PWM_CH1, PWM_CH2, PWM_CH3);  // 电调解锁
	OLED_Init();
	OLED_Display_On();
	OLED_Clear(0);
  OLED_P8x16String(31, 0, "HEELO HT"); 
//	char numberStr[10];
//  sprintf(numberStr, "%d", i);	// 将数值i转换为字符串
//  OLED_P8x16String(0, 0, numberStr);  // 显示该数字

  while (1){
	PWM_UpdateDuty(PWM_CH1, PWM_DUTY_20);
	}
}

/*********************************************************************************************************//**
  * @brief  Dealy loop.
  * @param  uLoop: Delay loop count
  * @retval None
  ***********************************************************************************************************/
void Delay(u32 uLoop)
{
  vu32 i;
  for (i = 0; i < uLoop; i++);
}

// 电调解锁 注意PWM频率设置，PWM高点和低点
void Motor_Unlock_init(TM_CH_Enum TM_CH_1, TM_CH_Enum TM_CH_2, TM_CH_Enum TM_CH_3, TM_CH_Enum TM_CH_4)
{
	PWM_UpdateDuty(TM_CH_1, PWM_DUTY_95);
	PWM_UpdateDuty(TM_CH_2, PWM_DUTY_95);
	PWM_UpdateDuty(TM_CH_3, PWM_DUTY_95);
	PWM_UpdateDuty(TM_CH_4, PWM_DUTY_95);
	PWM_Cmd(ENABLE);  // 设置PWM打开状态
	delay_ms(3500);
	PWM_UpdateDuty(TM_CH_1, PWM_DUTY_15);
	PWM_UpdateDuty(TM_CH_2, PWM_DUTY_15);
	PWM_UpdateDuty(TM_CH_3, PWM_DUTY_15);
	PWM_UpdateDuty(TM_CH_4, PWM_DUTY_15);
	delay_ms(3500);
//	PWM_Cmd(ENABLE);
}
#if (HT32_LIB_DEBUG == 1)
/*********************************************************************************************************//**
  * @brief  Report both the error name of the source file and the source line number.
  * @param  filename: pointer to the source file name.
  * @param  uline: error line source number.
  * @retval None
  ***********************************************************************************************************/
void assert_error(u8* filename, u32 uline)
{
  /*
     This function is called by IP library that the invalid parameters has been passed to the library API.
     Debug message can be added here.
     Example: printf("Parameter Error: file %s on line %d\r\n", filename, uline);
  */

  while (1)
  {
  }
}
#endif


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
