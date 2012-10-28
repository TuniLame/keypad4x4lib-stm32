#include "stm32_keypad4x4.h"

short keypad4x4_connect() {
    return 0;
}

short keypad4x4_GPIOConfig() {
    int i = 0, j = 0;
    RCC_AHB1PeriphClockCmd(KEYPAD4x4_1_GPIO_CLK, ENABLE);
    if (KEYPAD4x4_1_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK)
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_2_GPIO_CLK, ENABLE);
    if ((KEYPAD4x4_3_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK) && (KEYPAD4x4_3_GPIO_CLK != KEYPAD4x4_1_GPIO_CLK))
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_3_GPIO_CLK, ENABLE);
    if ((KEYPAD4x4_4_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK) && (KEYPAD4x4_4_GPIO_CLK != KEYPAD4x4_1_GPIO_CLK) && (KEYPAD4x4_4_GPIO_CLK != KEYPAD4x4_3_GPIO_CLK))
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_4_GPIO_CLK, ENABLE);
    if ((KEYPAD4x4_5_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK) && (KEYPAD4x4_5_GPIO_CLK != KEYPAD4x4_1_GPIO_CLK) && (KEYPAD4x4_5_GPIO_CLK != KEYPAD4x4_3_GPIO_CLK) && (KEYPAD4x4_5_GPIO_CLK != KEYPAD4x4_4_GPIO_CLK))
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_5_GPIO_CLK, ENABLE);
    if ((KEYPAD4x4_6_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK) && (KEYPAD4x4_6_GPIO_CLK != KEYPAD4x4_1_GPIO_CLK) && (KEYPAD4x4_6_GPIO_CLK != KEYPAD4x4_3_GPIO_CLK) && (KEYPAD4x4_6_GPIO_CLK != KEYPAD4x4_4_GPIO_CLK) && (KEYPAD4x4_6_GPIO_CLK != KEYPAD4x4_5_GPIO_CLK))
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_6_GPIO_CLK, ENABLE);
    if ((KEYPAD4x4_7_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK) && (KEYPAD4x4_7_GPIO_CLK != KEYPAD4x4_1_GPIO_CLK) && (KEYPAD4x4_7_GPIO_CLK != KEYPAD4x4_3_GPIO_CLK) && (KEYPAD4x4_7_GPIO_CLK != KEYPAD4x4_4_GPIO_CLK) && (KEYPAD4x4_7_GPIO_CLK != KEYPAD4x4_5_GPIO_CLK) && (KEYPAD4x4_7_GPIO_CLK != KEYPAD4x4_6_GPIO_CLK))
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_7_GPIO_CLK, ENABLE);
    if ((KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_2_GPIO_CLK) && (KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_1_GPIO_CLK) && (KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_3_GPIO_CLK) && (KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_4_GPIO_CLK) && (KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_5_GPIO_CLK) && (KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_6_GPIO_CLK) && (KEYPAD4x4_8_GPIO_CLK != KEYPAD4x4_7_GPIO_CLK))
        RCC_AHB1PeriphClockCmd(KEYPAD4x4_8_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_3_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_4_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_5_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_5_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_6_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_6_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_7_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_7_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYPAD4x4_8_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEYPAD4x4_8_GPIO_PORT, &GPIO_InitStructure);

    return 1;
}

short keypad4x4_Init(short pin1, short pin2, short pin3, short pin4) {
    if (pin1 > 0)
        GPIO_SetBits(KEYPAD4x4_1_GPIO_PORT, KEYPAD4x4_1_PIN);
    else
        GPIO_ResetBits(KEYPAD4x4_1_GPIO_PORT, KEYPAD4x4_1_PIN);
    if (pin2 > 0)
        GPIO_SetBits(KEYPAD4x4_2_GPIO_PORT, KEYPAD4x4_2_PIN);
    else
        GPIO_ResetBits(KEYPAD4x4_2_GPIO_PORT, KEYPAD4x4_2_PIN);
    if (pin3 > 0)
        GPIO_SetBits(KEYPAD4x4_3_GPIO_PORT, KEYPAD4x4_3_PIN);
    else
        GPIO_ResetBits(KEYPAD4x4_3_GPIO_PORT, KEYPAD4x4_3_PIN);
    if (pin4 > 0)
        GPIO_SetBits(KEYPAD4x4_4_GPIO_PORT, KEYPAD4x4_4_PIN);
    else
        GPIO_ResetBits(KEYPAD4x4_4_GPIO_PORT, KEYPAD4x4_4_PIN);
    return 1;
}

short keypad4x4_isButtonPressed() {
    if ((GPIO_ReadInputDataBit(KEYPAD4x4_5_GPIO_PORT, KEYPAD4x4_5_PIN))
            || (GPIO_ReadInputDataBit(KEYPAD4x4_6_GPIO_PORT, KEYPAD4x4_6_PIN))
            || (GPIO_ReadInputDataBit(KEYPAD4x4_7_GPIO_PORT, KEYPAD4x4_7_PIN))
            || (GPIO_ReadInputDataBit(KEYPAD4x4_8_GPIO_PORT, KEYPAD4x4_8_PIN))) {
        return 1;
    } else {
        return 0;
    }
}

char keypad4x4_ReadChar() {
    keypad4x4_Init(1, 0, 0, 0); //GPIO_ResetBits(GPIOE, GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13);
    if (GPIO_ReadInputDataBit(KEYPAD4x4_5_GPIO_PORT, KEYPAD4x4_5_PIN)) {
        return KEYPAD4x4__VALUE_1;
    } else {
        keypad4x4_Init(0, 1, 0, 0);
        if (GPIO_ReadInputDataBit(KEYPAD4x4_5_GPIO_PORT, KEYPAD4x4_5_PIN)) {
            return KEYPAD4x4__VALUE_4;
        } else {
            keypad4x4_Init(0, 0, 1, 0);
            if (GPIO_ReadInputDataBit(KEYPAD4x4_5_GPIO_PORT, KEYPAD4x4_5_PIN)) {
                return KEYPAD4x4__VALUE_7;
            } else {
                keypad4x4_Init(0, 0, 0, 1);
                if (GPIO_ReadInputDataBit(KEYPAD4x4_5_GPIO_PORT, KEYPAD4x4_5_PIN)) {
                    return KEYPAD4x4__VALUE_x;
                }
            }
        }
    }
    keypad4x4_Init(1, 0, 0, 0);
    if (GPIO_ReadInputDataBit(KEYPAD4x4_6_GPIO_PORT, KEYPAD4x4_6_PIN)) {
        return KEYPAD4x4__VALUE_2;
    } else {
        keypad4x4_Init(0, 1, 0, 0);
        if (GPIO_ReadInputDataBit(KEYPAD4x4_6_GPIO_PORT, KEYPAD4x4_6_PIN)) {
            return KEYPAD4x4__VALUE_5;
        } else {
            keypad4x4_Init(0, 0, 1, 0);
            if (GPIO_ReadInputDataBit(KEYPAD4x4_6_GPIO_PORT, KEYPAD4x4_6_PIN)) {
                return KEYPAD4x4__VALUE_8;
            } else {
                keypad4x4_Init(0, 0, 0, 1);
                if (GPIO_ReadInputDataBit(KEYPAD4x4_6_GPIO_PORT, KEYPAD4x4_6_PIN)) {
                    return KEYPAD4x4__VALUE_0;
                }
            }
        }
    }
    keypad4x4_Init(1, 0, 0, 0);
    if (GPIO_ReadInputDataBit(KEYPAD4x4_7_GPIO_PORT, KEYPAD4x4_7_PIN)) {
        return KEYPAD4x4__VALUE_3;
    } else {
        keypad4x4_Init(0, 1, 0, 0);
        if (GPIO_ReadInputDataBit(KEYPAD4x4_7_GPIO_PORT, KEYPAD4x4_7_PIN)) {
            return KEYPAD4x4__VALUE_6;
        } else {
            keypad4x4_Init(0, 0, 1, 0);
            if (GPIO_ReadInputDataBit(KEYPAD4x4_7_GPIO_PORT, KEYPAD4x4_7_PIN)) {
                return KEYPAD4x4__VALUE_9;
            } else {
                keypad4x4_Init(0, 0, 0, 1);
                if (GPIO_ReadInputDataBit(KEYPAD4x4_7_GPIO_PORT, KEYPAD4x4_7_PIN)) {
                    return KEYPAD4x4__VALUE_U;
                }
            }
        }
    }
    keypad4x4_Init(1, 0, 0, 0);
    if (GPIO_ReadInputDataBit(KEYPAD4x4_8_GPIO_PORT, KEYPAD4x4_8_PIN)) {
        return KEYPAD4x4__VALUE_A;
    } else {
        keypad4x4_Init(0, 1, 0, 0);
        if (GPIO_ReadInputDataBit(KEYPAD4x4_8_GPIO_PORT, KEYPAD4x4_8_PIN)) {
            return KEYPAD4x4__VALUE_B;
        } else {
            keypad4x4_Init(0, 0, 1, 0);
            if (GPIO_ReadInputDataBit(KEYPAD4x4_8_GPIO_PORT, KEYPAD4x4_8_PIN)) {
                return KEYPAD4x4__VALUE_C;
            } else {
                keypad4x4_Init(0, 0, 0, 1);
                if (GPIO_ReadInputDataBit(KEYPAD4x4_8_GPIO_PORT, KEYPAD4x4_8_PIN)) {
                    return KEYPAD4x4__VALUE_D;
                }
            }
        }
    }
    
}
short keypad4x4_charToShort(char c) {
    switch (c) {
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case 'A':
            return 'A';
            break;
        case 'B':
            return 'B';
            break;
        case 'C':
            return 'C';
            break;
        case 'D':
            return 'D';
            break;
        case '0':
            return 0;
            break;
    }
}