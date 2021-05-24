/*
 * Time.h
 *
 *  Created on: May 23, 2021
 *      Author: domin
 */

#ifndef SRC_DATETIME_TIMEKEEPING_H_
#define SRC_DATETIME_TIMEKEEPING_H_

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_rtc.h"
#include "main.h"


void Time_Init();

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc);
void RTC_AlarmCallback();


#endif /* SRC_DATETIME_TIMEKEEPING_H_ */
