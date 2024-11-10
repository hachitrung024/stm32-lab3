/*
 * display7SEG.h
 *
 *  Created on: Sep 30, 2024
 *      Author: hachi
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "software_timer.h"

#define MAX_LED7SEG 4
void display7SEG(uint8_t num);
void update7SEG(uint8_t num);
void run7SEG();
void updateBuffer7SEG(uint8_t num1, uint8_t num2);

#endif /* INC_DISPLAY7SEG_H_ */
