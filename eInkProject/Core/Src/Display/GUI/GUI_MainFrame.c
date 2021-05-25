
#include "GUI_MainFrame.h"

#include <eInk_config/EPD_2in13_V2.h>
#include <eInk_config/EPD_Test.h>
#include "stm32l4xx_hal_rtc.h"
#include "stdio.h"
#include "string.h"

extern RTC_HandleTypeDef hrtc;

UBYTE *BlackImage;
UWORD Imagesize = ((EPD_2IN13_V2_WIDTH % 8 == 0)? (EPD_2IN13_V2_WIDTH / 8 ): (EPD_2IN13_V2_WIDTH / 8 + 1)) * EPD_2IN13_V2_HEIGHT;

void Init_GUI(){
	EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
	EPD_2IN13_V2_Clear();
	DEV_Delay_ms(100);

	//Create a new image cache
	/* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
	if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
		//printf("Failed to apply for black memory...\r\n");
		return;
	}
	//printf("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, EPD_2IN13_V2_WIDTH, EPD_2IN13_V2_HEIGHT, 270, WHITE);
	Paint_SelectImage(BlackImage);
	//Paint_SetMirroring(MIRROR_HORIZONTAL); //
	Paint_SetMirroring(MIRROR_VERTICAL); //
	Paint_Clear(WHITE);

	//Paint_DrawBitMap(gImage_2in13);
	Paint_DrawBitMap(splash);

	EPD_2IN13_V2_Display(BlackImage);
	//printf("Goto Sleep...\r\n");
	EPD_2IN13_V2_Sleep();

	//DEV_Module_Exit();

}

void GUI_DrawTime(uint8_t full_redraw){
	if(full_redraw){
		EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL); //Wakeup display...
	}else{
		EPD_2IN13_V2_Init(EPD_2IN13_V2_PART); //Wakeup display...
	}

	EPD_2IN13_V2_DisplayPartBaseImage(BlackImage);

	EPD_2IN13_V2_Init(EPD_2IN13_V2_PART);
	Paint_SelectImage(BlackImage);

	PAINT_TIME alarmtime;

	RTC_TimeTypeDef sTime;
	RTC_AlarmTypeDef sAlarm;
	RTC_DateTypeDef sDate;

	//HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); //Dummy read necessary for time to be correct (?!)


	Paint_ClearWindows(125, 20, 125 + Font20.Width * 9, 20 + Font20.Height, WHITE);

	char text[9]; //HH:MM + terminator end of string
	sprintf(text, "%02d:%02d:%02d", sTime.Hours, sTime.Minutes, sTime.Seconds);
	Paint_DrawString_EN(125, 20, text, &Font20, WHITE, BLACK);


	/*HAL_RTC_GetAlarm(&hrtc, &sAlarm, RTC_ALARM_A, RTC_FORMAT_BIN);
	alarmtime.Hour = sAlarm.AlarmTime.Hours;
	alarmtime.Min = sAlarm.AlarmTime.Minutes;
	alarmtime.Sec = sAlarm.AlarmTime.Seconds;

	Paint_ClearWindows(125, 50, 125 + Font24.Width * 7, 50 + Font24.Height, WHITE);
	Paint_DrawTime(125, 50, &alarmtime, &Font24, WHITE, BLACK);*/

	EPD_2IN13_V2_DisplayPart(BlackImage);

	EPD_2IN13_V2_Sleep(); //Put display to sleep...

}

void GUI_DrawDate(uint8_t print_weekday){
	EPD_2IN13_V2_Init(EPD_2IN13_V2_PART);
	Paint_SelectImage(BlackImage);

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	uint8_t day = sDate.Date;
	uint8_t month = sDate.Month;
	uint8_t year = sDate.Year;

	char month_name[4];
	switch(month){
		case 1: strncpy(month_name, "Jan", 3); break;
		case 2: strncpy(month_name, "Feb", 3); break;
		case 3: strncpy(month_name, "Mar", 3); break;
		case 4: strncpy(month_name, "Apr", 3); break;
		case 5: strncpy(month_name, "May", 3); break;
		case 6: strncpy(month_name, "Jun", 3); break;
		case 7: strncpy(month_name, "Jul", 3); break;
		case 8: strncpy(month_name, "Aug", 3); break;
		case 9: strncpy(month_name, "Sept", 3); break;
		case 10: strncpy(month_name, "Oct", 3); break;
		case 11: strncpy(month_name, "Nov", 3); break;
		case 12: strncpy(month_name, "Dec", 3); break;
		default: strncpy(month_name, "Err", 3); break;
	}

	char text[10]; //DD MON YE -> 9 + terminator
	sprintf(text, "%.2d %.3s %02d", day, month_name, year);

	//Print date
	Paint_ClearWindows(125, 70, 125 + Font16.Width * strlen(text), 70 + Font16.Height, WHITE);
	Paint_DrawString_EN(125, 70, text, &Font16, WHITE, BLACK);

	//optional: print weekday
	if(print_weekday){
		uint8_t length;
		switch(sDate.WeekDay){
			case 1: length = 7; strncpy(text, "Monday", length); break;
			case 2: length = 8; strncpy(text, "Tuesday", length); break;
			case 3: length = 10; strncpy(text, "Wednesday", length); break;
			case 4: length = 9; strncpy(text, "Thursday", length); break;
			case 5: length = 7; strncpy(text, "Friday", length); break;
			case 6: length = 9; strncpy(text, "Saturday", length); break;
			case 7: length = 7; strncpy(text, "Sunday", length); break;
			default: length = 8; strncpy(text, "Invalid", length); break;
		}

		Paint_ClearWindows(125, 50, 125 + Font16.Width * strlen(text), 50 + Font16.Height, WHITE); //same as alarmtime !
		Paint_DrawString_EN(125, 50, text, &Font16, WHITE, BLACK);
	}

	EPD_2IN13_V2_DisplayPart(BlackImage);

	EPD_2IN13_V2_Sleep(); //Put display to sleep...

}
