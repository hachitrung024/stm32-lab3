/*
 * counter.c
 *
 *  Created on: Oct 1, 2024
 *      Author: hachi
 */


#include "counter.h"

uint8_t counters[MAX_COUNTER];
uint8_t red_duration, amber_duration, green_duration;
void setCounter(uint8_t index, uint8_t value){
	setTimer(0, 1000);
	counters[index] = value;
	updateBuffer7SEG(counters[0], counters[1]);
}
void counterRun(){
	if(isFlagTimer(0) && counters[0]>0 && counters[1]>0){
		setTimer(0, 1000);
		counters[0]--;
		counters[1]--;
		updateBuffer7SEG(counters[0], counters[1]);
	}
}
