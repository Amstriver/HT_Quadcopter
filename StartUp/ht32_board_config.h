/*********************************************************************************************************//**
 * @file    TM/PWM/ht32_board_config.h
 * @version $Rev:: 6681         $
 * @date    $Date:: 2023-01-18 #$
 * @brief   The header file of board configuration.
 *************************************************************************************************************
 * @attention
 *
 * Firmware Disclaimer Information
 *
 * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
 *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
 *    other intellectual property laws.
 *
 * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
 *    other than HOLTEK and the customer.
 *
 * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
 *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
 *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
 *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
 *
 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 ************************************************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32_BOARD_CONFIG_H
#define __HT32_BOARD_CONFIG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"

/* Settings ------------------------------------------------------------------------------------------------*/
#define  HTCFG_PWM_TM_PCLK                       (LIBCFG_MAX_SPEED)

#if defined(LIBCFG_TM_SCTM_2CHANNEL)
  #define HTCFG_PWM_2CHANNEL 1
#else
  #define HTCFG_PWM_2CHANNEL 0
#endif

#if defined(USE_HT32F50030_SK)
  #define  HTCFG_PWM_TM_IPN                       SCTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       10

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       11
#endif

#if defined(USE_HT32F52230_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F52241_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F52253_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F52341_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F52352_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       C
  #define  HTCFG_PWM0_GPION                       4

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       5

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       8

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       9
#endif

#if defined(USE_HT32F0008_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F50230_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F50241_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F52354_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F0006_DVB)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       C
  #define  HTCFG_PWM0_GPION                       4

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       5

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       8

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       9
#endif

#if defined(USE_HT32F57341_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       C
  #define  HTCFG_PWM0_GPION                       10

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       11

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       12

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       13
#endif

#if defined(USE_HT32F57352_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       C
  #define  HTCFG_PWM0_GPION                       10

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       11

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       12

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       13
#endif

#if defined(USE_HT32F50343_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F52367_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_BM53A367A_DVB)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A               // D27
  #define  HTCFG_PWM0_GPION                       4

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A               // D28
  #define  HTCFG_PWM1_GPION                       5

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A               // D26
  #define  HTCFG_PWM2_GPION                       6

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A               // D29
  #define  HTCFG_PWM3_GPION                       7
#endif

#if defined(USE_HT32F61141_SK)  //PRELIMINARY_NOT_TEST
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       B
  #define  HTCFG_PWM0_GPION                       1

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       B
  #define  HTCFG_PWM1_GPION                       0

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       15

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       14
#endif

#if defined(USE_HT32F65240_DVB)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       7

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       4

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       5

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       6
#endif

#if defined(USE_HT32F65240_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       7

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       4

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       5

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       6
#endif

#if defined(USE_HT32F65232_SK)  //PRELIMINARY_NOT_TEST
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       7

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       C
  #define  HTCFG_PWM1_GPION                       4

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       C
  #define  HTCFG_PWM2_GPION                       5

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       C
  #define  HTCFG_PWM3_GPION                       6
#endif

#if defined(USE_HT32F61245_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       4

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       5

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       6

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       7
#endif

#if defined(USE_HT32F61355_SK) || defined(USE_HT32F61356_SK) || defined(USE_HT32F61357_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       4

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       5

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       6

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       7
#endif

#if defined(USE_HT32F54241_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F54253_SK)
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       0

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       1

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       2

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       3
#endif

#if defined(USE_HT32F67051_SK)  //PRELIMINARY_NOT_TEST
  #define  HTCFG_PWM_TM_IPN                       GPTM0

  #define  HTCFG_PWM0_CHN                         0
  #define  HTCFG_PWM0_GPIOX                       A
  #define  HTCFG_PWM0_GPION                       2

  #define  HTCFG_PWM1_CHN                         1
  #define  HTCFG_PWM1_GPIOX                       A
  #define  HTCFG_PWM1_GPION                       3

  #define  HTCFG_PWM2_CHN                         2
  #define  HTCFG_PWM2_GPIOX                       A
  #define  HTCFG_PWM2_GPION                       4

  #define  HTCFG_PWM3_CHN                         3
  #define  HTCFG_PWM3_GPIOX                       A
  #define  HTCFG_PWM3_GPION                       5
#endif


#ifdef __cplusplus
}
#endif

#endif
