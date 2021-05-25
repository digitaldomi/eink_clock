/*
 * GUI_MainFrame.h
 *
 *  Created on: May 24, 2021
 *      Author: domin
 */

#ifndef SRC_DISPLAY_GUI_GUI_MAINFRAME_H_
#define SRC_DISPLAY_GUI_GUI_MAINFRAME_H_

#include <eInk_config/Debug.h>
#include <eInk_config/DEV_Config.h>
#include "GUI_Paint.h"
#include "ImageData.h"
#include <stdlib.h> // malloc() free()

void Init_GUI();
void GUI_DrawTime(uint8_t full_redraw);
void GUI_DrawDate(uint8_t print_weekday);

#endif /* SRC_DISPLAY_GUI_GUI_MAINFRAME_H_ */
