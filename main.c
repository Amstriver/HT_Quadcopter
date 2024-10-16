/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board.h"
#include "pwm.h"
#include "delay.h"
#include "ht32f5xxxx_tm_type.h"
#include "oled.h"
#include "time.h"
#include "led.h"
#include "uart.h"

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



extern float fAng[3];
extern float Temp;    
extern uint8_t Flag;

//uint8_t data = 0;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
	// Timer_Init();
	USARTx_Init();  // ��ʼ��USART1�ӿ�
	Usart_SendStr(COM1_PORT,(uint8_t *)"------HT32 UART TEST-------\r\n");//ѭ�������ַ�����������
  //PWM_Init();
  //Motor_Unlock_init(PWM_CH0, PWM_CH1, PWM_CH2, PWM_CH3);  // �������
	LED_Init();
	OLED_Init();
	OLED_Display_On();
	OLED_Clear(0);
//	char numberStr[10];
//  sprintf(numberStr, "%d", i);	// ����ֵiת��Ϊ�ַ���
//  OLED_P8x16String(0, 0, numberStr);  // ��ʾ������

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
		{sprintf(floatStr1, "Roll = %.2f", fAng[0]);  // ��fAng[0]ת��Ϊ������λС�����ַ���  �����
		OLED_P8x16String(10, 0, floatStr1);   // ��OLED����ʾ  
			
		sprintf(floatStr2, "Pitch = %.2f", fAng[1]);  // ת��fAng[1]  ������
		OLED_P8x16String(10, 2, floatStr2);   // ��ʾ   
//		
		sprintf(floatStr3, "Yaw = %.2f", fAng[2]);  // ת��fAng[2]  ƫ����
		OLED_P8x16String(10, 4, floatStr3);   // ��ʾ  
		}
		delay_ms(1000);                      // ��ʱ1��
	//PWM_UpdateDuty(PWM_CH1, PWM_DUTY_20);
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

// ������� ע��PWMƵ�����ã�PWM�ߵ�͵͵�
void Motor_Unlock_init(TM_CH_Enum TM_CH_1, TM_CH_Enum TM_CH_2, TM_CH_Enum TM_CH_3, TM_CH_Enum TM_CH_4)
{
	PWM_UpdateDuty(TM_CH_1, PWM_DUTY_95);
	PWM_UpdateDuty(TM_CH_2, PWM_DUTY_95);
	PWM_UpdateDuty(TM_CH_3, PWM_DUTY_95);
	PWM_UpdateDuty(TM_CH_4, PWM_DUTY_95);
	PWM_Cmd(ENABLE);  // ����PWM��״̬
	delay_ms(3500);
	PWM_UpdateDuty(TM_CH_1, PWM_DUTY_15);
	PWM_UpdateDuty(TM_CH_2, PWM_DUTY_15);
	PWM_UpdateDuty(TM_CH_3, PWM_DUTY_15);
	PWM_UpdateDuty(TM_CH_4, PWM_DUTY_15);
	delay_ms(3500);
//	PWM_Cmd(ENABLE);
}

//void COM_IRQHandler(void)
//{
//	u8 data;
//	printf("LED\r\n");
//	if( USART_GetFlagStatus(COM_PORT, USART_FLAG_RXDR) )
//	{
//		data = USART_ReceiveData(COM_PORT);
//		printf("data = %c\r\n",data);
//		if(data == '0')
//		{
//			LED_ON(GPIO_PIN_14);
//			printf("LED1 ON\r\n");
//		}
//		else if(data == '1')
//		{
//			LED_OFF(GPIO_PIN_14);
//			printf("LED1 OFF\r\n");
//		}
//	}
//}


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
