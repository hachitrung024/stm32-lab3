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
				increaseDuration(0);
				setTimer(0, 20000);
			}
			if(isButtonHolding(1)){
				if(isFlagTimer(2)){
					setTimer(2, 500);
					increaseDuration(0);
				}
			}
			if(isButtonPressed(2)|| isFlagTimer(0)){
				green_duration = red_duration - amber_duration;
				status = INIT;
			}
			break;
		case SET_AMBER:
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			if(isButtonPressed(1)){
				increaseDuration(1);
				setTimer(0, 20000);
			}
			if(isButtonHolding(1)){
				if(isFlagTimer(2)){
					setTimer(2, 500);
					increaseDuration(1);
				}
			}
			if(isButtonPressed(2)|| isFlagTimer(0)){
				green_duration = red_duration - amber_duration;
				status = INIT;
			}
			break;
		case SET_GREEN:
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);
			if(isButtonPressed(1)){
				increaseDuration(2);
				setTimer(0, 20000);
			}
			if(isButtonHolding(1)){
				if(isFlagTimer(2)){
					setTimer(2, 500);
					increaseDuration(2);
				}
			}
			if(isButtonPressed(2)|| isFlagTimer(0)){
				amber_duration = red_duration - green_duration;
				status = INIT;
			}
			break;
		default:
			break;
	}
}
