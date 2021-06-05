/*
 * Time.c
 *
 *  Created on: May 23, 2021
 *      Author: domin
 */

#include <DateTime/TimeKeeping.h>

#include <eInk_config/EPD_2in13_V2.h>
#include <eInk_config/EPD_Test.h>
#include "GUI/GUI_MainFrame.h"

uint8_t drawTimeNow = 1;
uint8_t drawTimeNowFullRedraw = 1;
uint8_t drawDateNow = 1;

extern RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime;
RTC_AlarmTypeDef sAlarm;
RTC_DateTypeDef sDate;

void Time_Init(){
	RTC_AlarmCallback();
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
	RTC_AlarmCallback();
}

// Called every minute
void RTC_AlarmCallback(){

	uint8_t seconds_interval = 1;
	if(seconds_interval > 59) seconds_interval = 59; //No bigger than 59 seconds

	//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); //Dummy read for valid time values

	uint8_t next_second = sTime.Seconds+seconds_interval; //Max 59 second intervals

	if (next_second >= 60) {
		sAlarm.AlarmTime.Minutes = sAlarm.AlarmTime.Minutes + 1;
		next_second-=60; //subtract 60s
		sAlarm.AlarmTime.Seconds = next_second;
		if (sAlarm.AlarmTime.Minutes == 60) {
			sAlarm.AlarmTime.Hours =  sAlarm.AlarmTime.Hours + 1;
			sAlarm.AlarmTime.Minutes = 0;
			if (sAlarm.AlarmTime.Hours == 24) {
				sAlarm.AlarmTime.Hours = 0;
				sAlarm.AlarmTime.Minutes = 0;
				sAlarm.AlarmTime.Seconds = 0;
			}
		}
	}

	sAlarm.AlarmTime.SubSeconds = 0x0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_ALL;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	sAlarm.AlarmDateWeekDay = 0x1;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	{
	Error_Handler();
	}

	//Refresh Time
	//GUI_DrawTime(); every minute
	if(next_second == 0 ){
		if(sTime.Seconds == 0){ //once every minute
			drawTimeNowFullRedraw = 1;
		}
		drawTimeNow = 1;
	}

	//Refresh Date
	if(sTime.Hours == 0 && sTime.Minutes == 0 && sTime.Seconds == 0){
		drawDateNow = 1;
	}


}
