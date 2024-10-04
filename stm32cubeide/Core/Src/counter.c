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
void increaseDuration(uint8_t index){
	if(index == 0){
		red_duration++;
		if(red_duration > 99) red_duration = green_duration + amber_duration;
		updateBuffer7SEG(red_duration, 1);
	}else if(index == 1){
		amber_duration++;
		if(amber_duration >= red_duration) amber_duration = red_duration - green_duration;
		updateBuffer7SEG(amber_duration, 2);
	}else if(index == 2){
		green_duration++;
		if(green_duration >= red_duration) green_duration = red_duration - amber_duration;
		updateBuffer7SEG(green_duration, 3);
	}
}
