
#include "GUI_MainFrame.h"

#include <eInk_config/EPD_2in13_V2.h>
#include <eInk_config/EPD_Test.h>
#include "stm32l4xx_hal_rtc.h"
#include "stdio.h"

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

	PAINT_TIME rtctime;
	PAINT_TIME alarmtime;

	RTC_TimeTypeDef sTime;
	RTC_AlarmTypeDef sAlarm;
	RTC_DateTypeDef sDate;

	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	rtctime.Hour = sTime.Hours;
	rtctime.Min = sTime.Minutes;
	rtctime.Sec = sTime.Seconds;

	Paint_ClearWindows(125, 20, 125 + Font24.Width * 7, 20 + Font24.Height, WHITE);
	Paint_DrawTime(125, 20, &rtctime, &Font24, WHITE, BLACK);

	HAL_RTC_GetAlarm(&hrtc, &sAlarm, RTC_ALARM_A, RTC_FORMAT_BIN);
	alarmtime.Hour = sAlarm.AlarmTime.Hours;
	alarmtime.Min = sAlarm.AlarmTime.Minutes;
	alarmtime.Sec = sAlarm.AlarmTime.Seconds;

	Paint_ClearWindows(125, 50, 125 + Font24.Width * 7, 50 + Font24.Height, WHITE);
	Paint_DrawTime(125, 50, &alarmtime, &Font24, WHITE, BLACK);

	EPD_2IN13_V2_DisplayPart(BlackImage);

	EPD_2IN13_V2_Sleep(); //Put display to sleep...

}

void GUI_DrawDate(){
	EPD_2IN13_V2_Init(EPD_2IN13_V2_PART);
	Paint_SelectImage(BlackImage);

	RTC_TimeTypeDef sTime;
	RTC_DateTypeDef sDate;
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	uint8_t day = sDate.Date;
	uint8_t month = sDate.Month;
	uint8_t year = sDate.Year;
	char text[50];
	sprintf(text, "%02d.%02d.%02d", day, month, year);

	Paint_ClearWindows(125, 80, 125 + Font24.Width * 7, 80 + Font24.Height, WHITE);
	Paint_DrawString_EN(125, 80, text, &Font20, WHITE, BLACK);

	EPD_2IN13_V2_DisplayPart(BlackImage);

}
