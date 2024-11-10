/*
 * global.c
 *
 *  Created on: Sep 25, 2024
 *      Author: hachi
 */


#include "global.h"

uint8_t status;

uint8_t counters[2];
uint8_t red_duration, amber_duration, green_duration;
uint8_t temp_duration;
void setCounter(uint8_t index, uint8_t value){
	setTimer(0, 1000);
	counters[index] = value;
	updateBuffer7SEG(counters[0], counters[1]);
}
void counterRun(){
	if(isFlagTimer(0)){
		setTimer(0, 1000);
		counters[0]--;
		counters[1]--;
		updateBuffer7SEG(counters[0], counters[1]);
	}
}

void increaseDuration(uint8_t index){
	if(index == 0){
	}else if(index == 1){
		amber_duration++;
		if(amber_duration >= red_duration) amber_duration = red_duration - green_duration;
		updateBuffer7SEG(4, amber_duration);
	}else if(index == 2){
		green_duration++;
		if(green_duration >= red_duration) green_duration = red_duration - amber_duration;
		updateBuffer7SEG(5, green_duration);
	}
}
void led_on(uint8_t way, uint8_t led){
	if(way==WAY1){
		if(led == RED) HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, LED_ON);
		else HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, LED_OFF);

		if(led == AMBER)HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, LED_ON);
		else HAL_GPIO_WritePin(LED_AMBER0_GPIO_Port, LED_AMBER0_Pin, LED_OFF);

		if(led == GREEN)HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, LED_ON);
		else HAL_GPIO_WritePin(LED_GREEN0_GPIO_Port, LED_GREEN0_Pin, LED_OFF);
	}
	if(way==WAY2){
		if(led == RED)HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_ON);
		else HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, LED_OFF);

		if(led == AMBER)HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, LED_ON);
		else HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, LED_OFF);

		if(led == GREEN)HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_ON);
		else HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, LED_OFF);
	}
}

