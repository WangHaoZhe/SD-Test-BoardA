/**
******************************************************************************
* @file : missile.h
* @author : Albert Wang
* @brief : None
* @date : 2023/11/19
******************************************************************************
* Copyright (c) 2023 Team JiaoLong-SJTU
* All rights reserved.
******************************************************************************
*/

#ifndef GUIDEDMISSILE_MISSILE_H
#define GUIDEDMISSILE_MISSILE_H

#include "stm32f4xx_hal.h"
#include "tim.h"
#include "gpio.h"

void controlInit(void);

void controlLoop(void);

extern uint8_t sd_flag;

#endif //GUIDEDMISSILE_MISSILE_H
