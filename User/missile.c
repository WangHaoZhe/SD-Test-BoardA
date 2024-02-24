/**
******************************************************************************
* @file : missile.c
* @author : Albert Wang
* @brief : None
* @date : 2023/11/19
******************************************************************************
* Copyright (c) 2023 Team JiaoLong-SJTU
* All rights reserved.
******************************************************************************
*/

#include "missile.h"
#include "fatfs.h"

FIL log_file;
uint8_t sd_flag;

void controlInit(void) {
    HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
    f_mount(&SDFatFS, "0:/", 1);
    f_open(&log_file, "log.csv", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);
    f_printf(&log_file, "TIME,%d,EVENT,Log file created\n", HAL_GetTick());
    f_lseek(&log_file, f_size(&log_file));
    f_printf(&log_file, "TIME,%d,EVENT,Init finished\n", HAL_GetTick());
    f_close(&log_file);
    f_open(&log_file, "log.csv", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);
    HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
    HAL_TIM_Base_Start_IT(&htim10);
}

void controlLoop(void) {
    // Global Begin
    uint32_t count = HAL_GetTick();
    // Global End

    if (count % 1 == 0 && !sd_flag) {
        f_lseek(&log_file, f_size(&log_file));
        f_printf(&log_file, "TIME,%d,EVENT,A ba a ba this is a test\n", count);
    }
    if (sd_flag) {
        f_lseek(&log_file, f_size(&log_file));
        f_printf(&log_file, "TIME,%d,EVENT,Log stopped manually\n", count);
        f_close(&log_file);
    }
}
