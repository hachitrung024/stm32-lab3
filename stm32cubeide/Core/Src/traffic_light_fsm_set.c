/*
 * traffic_light_fsm_set.c
 *
 *  Created on: Oct 1, 2024
 *      Author: hachi
 */

#include "traffic_light_fsm_set.h"

void traffic_light_fsm_set(){
	switch (status) {
		case SET_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			if(isButtonPressed(1)){
				increaseRed();
				updateBuffer7SEG(red_duration, red_duration);
				setTimer(0, 20000);
			}
			if(isButtonHolding(1)){
				if(isFlagTimer(2)){
					setTimer(2, 500);
					red_duration = red_duration + 1;
					if(red_duration > 99) red_duration = 1;
					updateBuffer7SEG(red_duration, red_duration);
				}
			}
			if(isButtonPressed(2)|| isFlagTimer(0)){
				green_duration = red_duration - amber_duration;
				status = INIT;
			}
			break;
		default:
			break;
	}
}
