 /**
 ******************************************************************************
 * @file    IO_Toggle/main.c 
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    19-September-2011
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDI """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
 *  NG THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************  
 */
/* Includes ------------------------------------------------------------------*/
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
#include "stm32_keypad4x4.h"

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
 * @{
 */

/** @addtogroup IO_Toggle
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);

/* Private functions ---------------------------------------------------------*/
void DelaySec(int sec) {
    int i;
    int tmp = 0;
    if (sec != 0) {
        tmp = sec * 67200;
    }
    Delay(tmp);

}

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
    /*!< At this stage the microcontroller clock setting is already configured, 
         this is done through SystemInit() function which is called from startup
         file (startup_stm32f4xx.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
          system_stm32f4xx.c file
     */
    char c = ' ';
    short n = 0, pin = 123, i = 0, j = 0, decimal = 1, vrai = 1;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);


    keypad4x4_GPIOConfig();

    keypad4x4_Init(1, 1, 1, 1); 
    //GPIO_SetBits(GPIOD, GPIO_Pin_12);
    DelaySec(200);
    while (1) {
        
        if (vrai == 0){
             GPIO_SetBits(GPIOD, GPIO_Pin_15);
        } else {
            GPIO_ResetBits(GPIOD, GPIO_Pin_15);
        }
        if ((i >= 3) && (vrai == 0)) {
            GPIO_SetBits(GPIOD, GPIO_Pin_13);
        }
        keypad4x4_Init(1, 1, 1, 1);
        while (keypad4x4_isButtonPressed()==0) {
GPIO_ResetBits(GPIOD, GPIO_Pin_12);

        }
        if (keypad4x4_isButtonPressed() == 1) {
            GPIO_SetBits(GPIOD, GPIO_Pin_12);
            c = keypad4x4_ReadChar();
            /*
            if (c == KEYPAD4x4__VALUE_x) {
                GPIO_SetBits(GPIOD, GPIO_Pin_12);
            } else if (c == KEYPAD4x4__VALUE_7) {
                GPIO_SetBits(GPIOD, GPIO_Pin_13);
            } else if (c == KEYPAD4x4__VALUE_4) {
                GPIO_SetBits(GPIOD, GPIO_Pin_14);
            } else if (c == KEYPAD4x4__VALUE_1) {
                GPIO_SetBits(GPIOD, GPIO_Pin_15);
            } else if (c == KEYPAD4x4__VALUE_2) {
                GPIO_SetBits(GPIOD, GPIO_Pin_12);
            } else if (c == KEYPAD4x4__VALUE_3) {
                GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_14);
            } else if (c == KEYPAD4x4__VALUE_A) {
                GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_15);
            }
             * */
            if (c == KEYPAD4x4__VALUE_U) {
                i++;
                if (n == pin) {
                    vrai = 1;
                    GPIO_SetBits(GPIOD, GPIO_Pin_12);
                    DelaySec(500);
                    GPIO_ResetBits(GPIOD, GPIO_Pin_12);
                    DelaySec(500);
                    GPIO_SetBits(GPIOD, GPIO_Pin_12);
                    DelaySec(500);
                    GPIO_ResetBits(GPIOD, GPIO_Pin_12);
                } else {
                    vrai = 0;
                    GPIO_SetBits(GPIOD, GPIO_Pin_14);
                    DelaySec(1000);
                    GPIO_ResetBits(GPIOD, GPIO_Pin_14);
                }
                n=0;
                decimal=1;
            }
            else if (c != 'A' && c != 'B' && c != 'D' && c != 'C' && c != '#' && c != '*' && i < 3 && j == 0 && n<1000) {
                
                n = keypad4x4_charToShort(c) * decimal + n;
                decimal = decimal * 10;
            } 
            if ((n>=1000) && (j==0)){
                GPIO_SetBits(GPIOD, GPIO_Pin_13);
                DelaySec(200);
                GPIO_ResetBits(GPIOD, GPIO_Pin_13);
                DelaySec(200);
                GPIO_SetBits(GPIOD, GPIO_Pin_13);
                DelaySec(200);
                GPIO_ResetBits(GPIOD, GPIO_Pin_13);
                n=0;
                decimal=1;
                i++;
            }
            
            j=1;
            c = ' ';
        }
        if (keypad4x4_isButtonPressed() == 0){
            //GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
            j=0;
            GPIO_ResetBits(GPIOD, GPIO_Pin_12);
        }
        //GPIO_SetBits(GPIOE, GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13);


    }
}

/**
 * @brief  Delay Function.
 * @param  nCount:specifies the Delay time length.
 * @retval None
 */
void Delay(__IO uint32_t nCount) {
    while (nCount--) {
    }
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line) {
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1) {
    }
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
