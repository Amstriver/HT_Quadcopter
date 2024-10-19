/* Includes ------------------------------------------------------------------------------------------------*/
#include "Init.h"
#include "ALL_DATA.h"

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
   
extern uint8_t Flag;

//uint8_t data = 0;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
	ALL_Init();

//	char numberStr[10];
//  sprintf(numberStr, "%d", i);	// 将数值i转换为字符串
//  OLED_P8x16String(0, 0, numberStr);  // 显示该数字
		TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH0, PWM_DUTY_80);
		TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH1, PWM_DUTY_80);
		TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH2, PWM_DUTY_80);
		TM_SetCaptureCompare(HTCFG_PWM_TM_PORT, PWM_CH3, PWM_DUTY_80);
  while (1){
//	uint32_t countValue = TM_GetCounter(HT_GPTM0);
//  char numberStr[10];		
//  sprintf(numberStr, "%d", countValue);
//	OLED_P8x16String(15, 6, numberStr);
//	delay_ms(1000);
		// 显示fAng数组中的值 
		char floatStr1[20]; 
		char floatStr2[20]; 
		char floatStr3[20];


		if (Flag == 1)
		{sprintf(floatStr1, "Roll = %.2f", Angle.roll);  // 将fAng[0]转换为保留两位小数的字符串  横滚角
		OLED_P8x16String(10, 0, floatStr1);   // 在OLED上显示  
			
		sprintf(floatStr2, "Pitch = %.2f", Angle.pitch);  // 转换fAng[1]  俯仰角
		OLED_P8x16String(10, 2, floatStr2);   // 显示   
//		
		sprintf(floatStr3, "Yaw = %.2f", Angle.yaw);  // 转换fAng[2]  偏航角
		OLED_P8x16String(10, 4, floatStr3);   // 显示  
		}
		delay_ms(1000);                      // 延时1秒
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
