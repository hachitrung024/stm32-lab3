/*
 * traffic_light_fsm_auto.c
 *
 *  Created on: Sep 25, 2024
 *      Author: hachi
 */


#include "traffic_light_fsm_auto.h"

void traffic_light_fsm_auto(){
	switch (status) {
		case AUTO_RED_GREEN:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			if(counters[1] == 0){
				status = AUTO_RED_AMBER;
				setCounter(1, amber_duration);
			}else if(isButtonPressed(0)){
				status = INIT;
			}
			break;
		case AUTO_RED_AMBER:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(counters[1]==0 || counters[0]==0){
				status = AUTO_GREEN_RED;
				setCounter(0, green_duration);
				setCounter(1, red_duration);
			}
			break;
		case AUTO_GREEN_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(counters[0]==0){
				status = AUTO_AMBER_RED;
				setCounter(0, amber_duration);
			}
			break;
		case AUTO_AMBER_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(counters[0]==0 || counters[1] == 0){
				status = AUTO_RED_GREEN;
				setCounter(0, red_duration);
				setCounter(1, green_duration);
			}
			break;
		default:
			break;
	}
}
