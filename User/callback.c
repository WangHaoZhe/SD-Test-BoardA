/**
  ******************************************************************************
  * @file           : callback.h
  * @author         : Albert Wang
  * @brief          : None
  * @date           : 2023/11/19
  ******************************************************************************
  * Copyright (c) 2023 Team JiaoLong-SJTU
  * All rights reserved.
  ******************************************************************************
  */

#include "callback.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim10) { // 1kHz
        controlLoop();
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == KEY_Pin) {
        if (HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin)) {
            sd_flag = 1;
            HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
        } else{
            HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
        }
    }
}
