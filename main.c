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
//  sprintf(numberStr, "%d", i);	// ����ֵiת��Ϊ�ַ���
//  OLED_P8x16String(0, 0, numberStr);  // ��ʾ������
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
		// ��ʾfAng�����е�ֵ 
		char floatStr1[20]; 
		char floatStr2[20]; 
		char floatStr3[20];


		if (Flag == 1)
		{sprintf(floatStr1, "Roll = %.2f", Angle.roll);  // ��fAng[0]ת��Ϊ������λС�����ַ���  �����
		OLED_P8x16String(10, 0, floatStr1);   // ��OLED����ʾ  
			
		sprintf(floatStr2, "Pitch = %.2f", Angle.pitch);  // ת��fAng[1]  ������
		OLED_P8x16String(10, 2, floatStr2);   // ��ʾ   
//		
		sprintf(floatStr3, "Yaw = %.2f", Angle.yaw);  // ת��fAng[2]  ƫ����
		OLED_P8x16String(10, 4, floatStr3);   // ��ʾ  
		}
		delay_ms(1000);                      // ��ʱ1��
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
