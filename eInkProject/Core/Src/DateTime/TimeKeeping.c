/*
 * Time.c
 *
 *  Created on: May 23, 2021
 *      Author: domin
 */

#include <DateTime/TimeKeeping.h>

#include <eInk_config/EPD_2in13_V2.h>
#include <eInk_config/EPD_Test.h>


extern RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime;
RTC_AlarmTypeDef sAlarm;

void Time_Init(){
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	uint8_t next_second = sTime.Seconds+=10;
	if (next_second > 59) next_second = 0;

	sAlarm.AlarmTime.Hours = 0x0;
	sAlarm.AlarmTime.Minutes = 0x0;
	sAlarm.AlarmTime.Seconds = next_second;
	sAlarm.AlarmTime.SubSeconds = 0x0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_SECONDS;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	sAlarm.AlarmDateWeekDay = 0x1;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
	RTC_AlarmCallback();
}


void RTC_AlarmCallback(){
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	uint8_t next_second = sTime.Seconds+=10;
	if (next_second > 59) next_second = 0;

	sAlarm.AlarmTime.Hours = sTime.Hours;
	sAlarm.AlarmTime.Minutes = sTime.Minutes;
	sAlarm.AlarmTime.Seconds = next_second;
	sAlarm.AlarmTime.SubSeconds = 0x0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_SECONDS;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	sAlarm.AlarmDateWeekDay = 0x1;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}
}
