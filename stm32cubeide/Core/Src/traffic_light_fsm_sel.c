/*
 * traffic_light_fsm_sel.c
 *
 *  Created on: Sep 26, 2024
 *      Author: hachi
 */


#include "traffic_light_fsm_sel.h"

void traffic_light_fsm_sel(){
	switch (status) {
		case INIT:
			if(1){
				status = SEL_AUTO;
				setCounter(0, 0);
				setCounter(1, 0);
				setTimer(0, 5000);
			}
			break;
		case SEL_AUTO:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			if(isFlagTimer(0) || isButtonPressed(2)){
				status = AUTO_RED_GREEN;
				setCounter(0, red_duration);
				setCounter(1, green_duration);
			}else if(isButtonPressed(0)){
				status = SEL_MAN;
				setTimer(0, 5000);
			}
			break;
		case SEL_MAN:
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_RED0_GPIO_Port, LED_RED0_Pin);
				HAL_GPIO_TogglePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin);
				HAL_GPIO_TogglePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin);

				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			}

			if(isFlagTimer(0)){
				status = AUTO_RED_GREEN;
				setCounter(0, red_duration);
				setCounter(1, green_duration);
			}
			if(isButtonPressed(2)){
				status = MAN_RED_GREEN;
				setTimer(0, 10000);
			}else if(isButtonPressed(0)){
				status = SEL_RED;
				setTimer(0, 5000);
			}
			break;
		case SEL_RED:
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);

			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_RED0_GPIO_Port, LED_RED0_Pin);
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			}
			if(isFlagTimer(0)){
				status = AUTO_RED_GREEN;
				setCounter(0, red_duration);
				setCounter(1, green_duration);
			}
			if(isButtonPressed(2)){
				status = AUTO_RED_GREEN;
				setTimer(0, 3000);
			}else if(isButtonPressed(0)){
				status = SEL_AMBER;
				setTimer(0, 5000);
			}
			break;
		case SEL_AMBER:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
			}
			if(isFlagTimer(0)){
				status = AUTO_RED_GREEN;
				setTimer(0, 3000);
			}
			if(isButtonPressed(2)){
				status = AUTO_RED_GREEN;
				setTimer(0, 3000);
			}else if(isButtonPressed(0)){
				status = SEL_GREEN;
				setTimer(0, 5000);
			}
			break;
		case SEL_GREEN:
			HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, SET);
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			}
			if(isFlagTimer(0)){
				status = AUTO_RED_GREEN;
				setCounter(0, red_duration);
				setCounter(1, green_duration);
			}
			if(isButtonPressed(2)){
				status = AUTO_RED_GREEN;
				setTimer(0, 3000);
			}else if(isButtonPressed(0)){
				status = SEL_AUTO;
				setTimer(0, 5000);
			}
			break;
		default:
			break;
	}
}
