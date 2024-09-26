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
			if(isFlagTimer(0)){
				status = AUTO_RED_AMBER;
				setTimer(0, 2000);
			}else if(isButtonPressed(0)){
				status = INIT;
			}
			break;
		case AUTO_RED_AMBER:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(isFlagTimer(0)){
				status = AUTO_GREEN_RED;
				setTimer(0, 3000);
			}
			break;
		case AUTO_GREEN_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(isFlagTimer(0)){
				status = AUTO_AMBER_RED;
				setTimer(0, 2000);
			}
			break;
		case AUTO_AMBER_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);
			if(isFlagTimer(0)){
				status = AUTO_RED_GREEN;
				setTimer(0, 5000);
			}
			break;
		default:
			break;
	}
}
