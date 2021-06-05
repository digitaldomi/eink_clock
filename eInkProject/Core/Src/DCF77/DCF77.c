/*
 * DCF77.c
 *
 *  Created on: Jun 5, 2021
 *      Author: domin
 */

#include "DCF77.h"


void DCF77_Init(){
	DCF77_Enable(1);
}

void  DCF77_Enable(uint8_t state){
	if(state == 1){
		HAL_GPIO_WritePin(DCF77_EN_GPIO_Port, DCF77_EN_Pin, 0); //On, Active Low
	}else{
		HAL_GPIO_WritePin(DCF77_EN_GPIO_Port, DCF77_EN_Pin, 1); //Off, Active Low
	}
}
