/* 
 * File:   stm32_keypad4x4.h
 * Author: tunilame
 *
 * Created on 16 octobre 2012, 12:08
 */

#ifndef STM32_KEYPAD4X4_H
#define	STM32_KEYPAD4X4_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "stm32f4xx_conf.h"
#define KEYPAD4x4_PINn                             8

#define KEYPAD4x4_1_PIN                         GPIO_Pin_7
#define KEYPAD4x4_1_GPIO_PORT                   GPIOB
#define KEYPAD4x4_1_GPIO_CLK                    RCC_AHB1Periph_GPIOB  

#define KEYPAD4x4_2_PIN                         GPIO_Pin_5
#define KEYPAD4x4_2_GPIO_PORT                   GPIOB
#define KEYPAD4x4_2_GPIO_CLK                    RCC_AHB1Periph_GPIOB

#define KEYPAD4x4_3_PIN                         GPIO_Pin_3
#define KEYPAD4x4_3_GPIO_PORT                   GPIOB
#define KEYPAD4x4_3_GPIO_CLK                    RCC_AHB1Periph_GPIOB 

#define KEYPAD4x4_4_PIN                         GPIO_Pin_6
#define KEYPAD4x4_4_GPIO_PORT                   GPIOD
#define KEYPAD4x4_4_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define KEYPAD4x4_5_PIN                         GPIO_Pin_4
#define KEYPAD4x4_5_GPIO_PORT                   GPIOD
#define KEYPAD4x4_5_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define KEYPAD4x4_6_PIN                         GPIO_Pin_2
#define KEYPAD4x4_6_GPIO_PORT                   GPIOD
#define KEYPAD4x4_6_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define KEYPAD4x4_7_PIN                         GPIO_Pin_0
#define KEYPAD4x4_7_GPIO_PORT                   GPIOD
#define KEYPAD4x4_7_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define KEYPAD4x4_8_PIN                         GPIO_Pin_11
#define KEYPAD4x4_8_GPIO_PORT                   GPIOC
#define KEYPAD4x4_8_GPIO_CLK                    RCC_AHB1Periph_GPIOC
    
    
#define KEYPAD4x4__VALUE_BEGIN                  0
#define KEYPAD4x4__VALUE_1                      '1'
#define KEYPAD4x4__VALUE_2                      '2'
#define KEYPAD4x4__VALUE_3                      '3'
#define KEYPAD4x4__VALUE_4                      '4'
#define KEYPAD4x4__VALUE_5                      '5'
#define KEYPAD4x4__VALUE_6                      '6'
#define KEYPAD4x4__VALUE_7                      '7'
#define KEYPAD4x4__VALUE_8                      '8'
#define KEYPAD4x4__VALUE_9                      '9'
#define KEYPAD4x4__VALUE_A                      'A'
#define KEYPAD4x4__VALUE_B                      'B'
#define KEYPAD4x4__VALUE_C                      'C'
#define KEYPAD4x4__VALUE_D                      'D'
#define KEYPAD4x4__VALUE_0                      '0'
#define KEYPAD4x4__VALUE_U                      '#'
#define KEYPAD4x4__VALUE_x                      '*'
#define KEYPAD4x4__VALUE_END                    1111


    /* Private typedef -----------------------------------------------------------*/
    GPIO_InitTypeDef GPIO_InitStructure;
    short keypad4x4_connect();
    short keypad4x4_GPIOConfig();
    short keypad4x4_isButtonPressed();
    short keypad4x4_charToShort(char c);

#ifdef	__cplusplus
}
#endif

#endif	/* STM32_KEYPAD4X4_H */

