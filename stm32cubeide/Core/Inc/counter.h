/*
 * counter.h
 *
 *  Created on: Oct 1, 2024
 *      Author: hachi
 */

#ifndef INC_COUNTER_H_
#define INC_COUNTER_H_

#include "main.h"
#include "display7SEG.h"
#include "software_timer.h"
#define MAX_COUNTER 2
extern uint8_t counters[MAX_COUNTER];
extern uint8_t red_duration;
extern uint8_t amber_duration;
extern uint8_t green_duration;
void setCounter(uint8_t index, uint8_t value);
void counterRun();
void increaseDuration(uint8_t index);
#endif /* INC_COUNTER_H_ */
