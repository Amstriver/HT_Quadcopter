#include "led.h"

void LED_Init(void)
{
  { /* Enable peripheral clock                                                                              */
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
    CKCUClock.Bit.AFIO = 1;
    CKCUClock.Bit.PC = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }

  { /* Configure GPIO as output mode                                                                        */

    /* Configure AFIO mode as GPIO                                                                          */
    //AFIO_GPxConfig(GPIO_PB, AFIO_PIN_1, AFIO_FUN_GPIO);

    /* Configure GPIO pull resistor                                                                         */
    GPIO_PullResistorConfig(HT_GPIOC, GPIO_PIN_14 | GPIO_PIN_15, GPIO_PR_DOWN);

    /* Default value RESET/SET                                                                              */
    GPIO_WriteOutBits(HT_GPIOC, GPIO_PIN_14 | GPIO_PIN_15, SET);

    /* Configure GPIO direction as output                                                                   */
    GPIO_DirectionConfig(HT_GPIOC, GPIO_PIN_14 | GPIO_PIN_15, GPIO_DIR_OUT);
  }
}
// 硬件原理图中 PC14 ---> LED1（GPIO_PIN_14）   PC15 ---> LED2（GPIO_PIN_15）
void LED_ON(u16 GPIO_PIN_nBITMAP)
{
	  GPIO_ClearOutBits(HT_GPIOC, GPIO_PIN_nBITMAP); // GPIO = LOW
}

void LED_OFF(u16 GPIO_PIN_nBITMAP)
{
	  GPIO_SetOutBits(HT_GPIOC, GPIO_PIN_nBITMAP);  // GPIO = HIGH
}