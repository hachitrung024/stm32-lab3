/*
 * display7SEG.c
 *
 *  Created on: Sep 30, 2024
 *      Author: hachi
 */


#include "display7SEG.h"

uint8_t led7SEG_index = 0;
uint8_t led7SEG_buffer[MAX_LED7SEG];

void run7SEG(){
	if(isFlagTimer(1)){
		setTimer(1, 100);
		if(led7SEG_index >= MAX_LED7SEG) led7SEG_index = 0;
		update7SEG(led7SEG_index++);
	}
}
void updateBuffer7SEG(uint8_t num1, uint8_t num2){
	led7SEG_buffer[0] = num1/10;
	led7SEG_buffer[1] = num1%10;
	led7SEG_buffer[2] = num2/10;
	led7SEG_buffer[3] = num2%10;
}
void update7SEG(uint8_t num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led7SEG_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led7SEG_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led7SEG_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led7SEG_buffer[3]);
			break;
		default:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
	}
}
void display7SEG(uint8_t num){
  switch(num){
	  case 0:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  case 3:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  case 4:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  case 5:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  case 6:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  case 7:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		  break;
	  case 8:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  case 9:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
		  break;
	  default:
		  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
		  break;
  }
}
