/*
 * traffic_light_fsm_man.c
 *
 *  Created on: Sep 25, 2024
 *      Author: hachi
 */

#include "traffic_light_fsm_man.h"

void traffic_light_fsm_man(){
	switch (status) {
		break;
		case MAN_RED_GREEN:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			if(isFlagTimer(0)){
				status = INIT;
			}else if(isButtonPressed(0)){
				status = SEL_MAN;
			}else if(isButtonPressed(1)){
				status = MAN_RED_AMBER;
				setTimer(0, 2000);
			}
			break;
		case MAN_RED_AMBER:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(isFlagTimer(0)){
				status = MAN_GREEN_RED;
				setTimer(0, 10000);
			}
			break;
		case MAN_GREEN_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(isFlagTimer(0)){
				status = INIT;
			}else if(isButtonPressed(1)){
				status = MAN_AMBER_RED;
				setTimer(0, 2000);
			}
			break;
		case MAN_AMBER_RED:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);
			if(isFlagTimer(0)){
				status = MAN_RED_GREEN;
				setTimer(0, 10000);
			}
			break;
		default:
			break;
	}
}
