/*
 * global.h
 *
 *  Created on: Sep 25, 2024
 *      Author: hachi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 0

#define SEL_AUTO		1
#define SEL_MAN			2
#define SEL_RED			3
#define SEL_AMBER		4
#define SEL_GREEN		5

#define AUTO_RED_GREEN 	6
#define AUTO_RED_AMBER 	7
#define AUTO_GREEN_RED 	8
#define AUTO_AMBER_RED 	9

#define MAN_RED_GREEN 	11
#define MAN_RED_AMBER 	12
#define MAN_GREEN_RED 	13
#define MAN_AMBER_RED 	14

#include "main.h"
#include "software_timer.h"
#include "button_reading.h"
#include "display7SEG.h"
#include "counter.h"
extern uint8_t status;

#endif /* INC_GLOBAL_H_ */
