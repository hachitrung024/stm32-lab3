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
				setTimer(0, SELECT_TIMEOUT);
				updateBuffer7SEG(1, 1);
				HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, RESET);
				HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, RESET);
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
				HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			}
			break;
		case SEL_AUTO:
			if(isFlagTimer(0) || isButtonPressed(BT_OK)){
				status = AUTO_RED_GREEN;
				led_on(WAY1, RED);
				led_on(WAY2, GREEN);
				setCounter(0, red_duration);
				setCounter(1, green_duration);
			}else if(isButtonPressed(BT_MODE)){
				updateBuffer7SEG(2, 2);
				status = SEL_MAN;
				setTimer(0, SELECT_TIMEOUT);
			}
			break;
		case SEL_MAN:
			if(isFlagTimer(0)){
				status = INIT;
			}
			if(isButtonPressed(BT_OK)){
				status = MAN_RED_GREEN;
				led_on(WAY1, RED);
				led_on(WAY2, GREEN);
				setTimer(0, SETTING_TIMEOUT);
			}else if(isButtonPressed(BT_MODE)){
				status = SEL_RED;
				led_on(WAY1, RED);
				led_on(WAY2, RED);
				updateBuffer7SEG(3, 3);
				setTimer(0, SELECT_TIMEOUT);
			}
			//Blink all led
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_RED0_GPIO_Port, LED_RED0_Pin);
				HAL_GPIO_TogglePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin);
				HAL_GPIO_TogglePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin);
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			}
			break;
		case SEL_RED:
			if(isFlagTimer(0)){
				status = INIT;
			}
			if(isButtonPressed(BT_OK)){
				temp_duration = red_duration;
				status = SET_RED;
				led_on(WAY1, RED);
				led_on(WAY2, RED);
				setTimer(0, SETTING_TIMEOUT);
				updateBuffer7SEG(3, red_duration);
			}else if(isButtonPressed(BT_MODE)){
				status = SEL_AMBER;
				led_on(WAY1, AMBER);
				led_on(WAY2, AMBER);
				updateBuffer7SEG(4, 4);
				setTimer(0, SELECT_TIMEOUT);
			}
			//Blink RED
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_RED0_GPIO_Port, LED_RED0_Pin);
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			}
			break;
		case SEL_AMBER:
			if(isFlagTimer(0)){
				status = INIT;
			}
			if(isButtonPressed(BT_OK)){
				temp_duration = amber_duration;
				status = SET_AMBER;
				led_on(WAY1, AMBER);
				led_on(WAY2, AMBER);
				setTimer(0, SETTING_TIMEOUT);
				updateBuffer7SEG(4, amber_duration);
			}else if(isButtonPressed(BT_MODE)){
				status = SEL_GREEN;
				led_on(WAY1, GREEN);
				led_on(WAY2, GREEN);
				updateBuffer7SEG(5, 5);
				setTimer(0, SELECT_TIMEOUT);
			}
			//Blink AMBER
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
			}
			break;
		case SEL_GREEN:
			if(isFlagTimer(0)){
				status = INIT;
			}
			if(isButtonPressed(BT_OK)){
				temp_duration = green_duration;
				status = SET_GREEN;
				led_on(WAY1, GREEN);
				led_on(WAY2, GREEN);
				setTimer(0, SETTING_TIMEOUT);
				updateBuffer7SEG(5, green_duration);
			}else if(isButtonPressed(BT_MODE)){
				status = INIT;
			}
			//Blink GREEN
			if(isFlagTimer(2)){
				setTimer(2, 500);
				HAL_GPIO_TogglePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			}
			break;
		default:
			break;
	}
}
