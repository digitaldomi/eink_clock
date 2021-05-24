/*****************************************************************************
* | File      	:   EPD_2IN13_V2_test.c
* | Author      :   Waveshare team
* | Function    :   2.13inch e-paper(V2) test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-06-13
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include <eInk_config/EPD_2in13_V2.h>
#include <eInk_config/EPD_Test.h>
#include "stm32l4xx_hal_rtc.h"

extern RTC_HandleTypeDef hrtc;

int EPD_2in13_V2_test(void)
{
    printf("EPD_2IN13_V2_test Demo\r\n");
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    EPD_2IN13_V2_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlackImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN13_V2_WIDTH % 8 == 0)? (EPD_2IN13_V2_WIDTH / 8 ): (EPD_2IN13_V2_WIDTH / 8 + 1)) * EPD_2IN13_V2_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN13_V2_WIDTH, EPD_2IN13_V2_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_SetMirroring(MIRROR_HORIZONTAL); //
    //Paint_SetMirroring(MIRROR_VERTICAL); //
    Paint_Clear(WHITE);


#if 1   //show image for array
    printf("show image for array\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_DrawBitMap(gImage_2in13);
    //Paint_DrawBitMap(myImage);

    EPD_2IN13_V2_Display(BlackImage);
    DEV_Delay_ms(3000);
#endif

#if 0   // Drawing on the image
    printf("Drawing\r\n");
    //1.Select Image
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    // 2.Drawing on the image
    Paint_DrawPoint(5, 10, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    Paint_DrawPoint(5, 25, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
    Paint_DrawPoint(5, 40, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    Paint_DrawPoint(5, 55, BLACK, DOT_PIXEL_4X4, DOT_STYLE_DFT);

    Paint_DrawLine(20, 10, 70, 60, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawLine(70, 10, 20, 60, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawRectangle(20, 10, 70, 60, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawRectangle(85, 10, 135, 60, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);

    Paint_DrawLine(45, 15, 45, 55, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawLine(25, 35, 70, 35, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawCircle(45, 35, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawCircle(110, 35, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);

    Paint_DrawString_EN(140, 15, "waveshare", &Font16, BLACK, WHITE);
    Paint_DrawNum(140, 40, 123456789, &Font16, BLACK, WHITE);

    Paint_DrawString_CN(140, 60, "���abc", &Font12CN, BLACK, WHITE);
    Paint_DrawString_CN(5, 65, "΢ѩ����", &Font24CN, WHITE, BLACK);

    EPD_2IN13_V2_Display(BlackImage);
    DEV_Delay_ms(2000);
#endif

#if 1   //Partial refresh, example shows time
    printf("Partial refresh\r\n");
    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    EPD_2IN13_V2_DisplayPartBaseImage(BlackImage);

    EPD_2IN13_V2_Init(EPD_2IN13_V2_PART);
    Paint_SelectImage(BlackImage);
    PAINT_TIME sPaint_time;
    sPaint_time.Hour = 12;
    sPaint_time.Min = 34;
    sPaint_time.Sec = 56;

    PAINT_TIME rtctime;
    PAINT_TIME alarmtime;

    RTC_TimeTypeDef sTime;
    RTC_AlarmTypeDef sAlarm;

    uint16_t num = 65530;
    for (;;) {

    	sPaint_time.Sec = sPaint_time.Sec + 1;
        if (sPaint_time.Sec == 60) {
            sPaint_time.Min = sPaint_time.Min + 1;
            sPaint_time.Sec = 0;
            if (sPaint_time.Min == 60) {
                sPaint_time.Hour =  sPaint_time.Hour + 1;
                sPaint_time.Min = 0;
                if (sPaint_time.Hour == 24) {
                    sPaint_time.Hour = 0;
                    sPaint_time.Min = 0;
                    sPaint_time.Sec = 0;
                }
            }
        }
        Paint_ClearWindows(20, 80, 20 + Font24.Width * 7, 80 + Font24.Height, WHITE);
        Paint_DrawTime(20, 80, &sPaint_time, &Font24, WHITE, BLACK);

        RTC_DateTypeDef sDate;

    	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    	rtctime.Hour = sTime.Hours;
    	rtctime.Min = sTime.Minutes;
    	rtctime.Sec = sTime.Seconds;

        Paint_ClearWindows(20, 20, 20 + Font24.Width * 7, 20 + Font24.Height, WHITE);
        Paint_DrawTime(20, 20, &rtctime, &Font24, WHITE, BLACK);

        HAL_RTC_GetAlarm(&hrtc, &sAlarm, RTC_ALARM_A, RTC_FORMAT_BIN);
        alarmtime.Hour = sAlarm.AlarmTime.Hours;
        alarmtime.Min = sAlarm.AlarmTime.Minutes;
        alarmtime.Sec = sAlarm.AlarmTime.Seconds;

        Paint_ClearWindows(20, 50, 20 + Font24.Width * 7, 50 + Font24.Height, WHITE);
        Paint_DrawTime(20, 50, &alarmtime, &Font24, WHITE, BLACK);

        Paint_DrawPoint(num%250, 120, BLACK, DOT_PIXEL_1X1, DOT_FILL_AROUND);

        num = num - 1;
        if(num == 0) {
            break;
        }
        EPD_2IN13_V2_DisplayPart(BlackImage);
        DEV_Delay_ms(1000);//Analog clock 1s
    }

#endif
    printf("Clear...\r\n");

    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    EPD_2IN13_V2_Clear();
    DEV_Delay_ms(2000);//Analog clock 1s

    printf("Goto Sleep...\r\n");
    EPD_2IN13_V2_Sleep();
    free(BlackImage);
    BlackImage = NULL;
    DEV_Delay_ms(1000);//Analog clock 1s

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
    
    return 0;
}

