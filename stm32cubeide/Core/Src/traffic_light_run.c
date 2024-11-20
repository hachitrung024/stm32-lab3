/*
 * traffic_light_run.c
 *
 *  Created on: Nov 19, 2024
 *      Author: hachi
 */


#include "traffic_light_run.h"

void loop(){
	  traffic_light_fsm_sel();
	  traffic_light_fsm_auto();
	  traffic_light_fsm_man();
	  traffic_light_fsm_set();
}
void traffic_light_init(){
	  setTimer(0, 10);
	  setTimer(1, 10);
	  setTimer(2, 10);
	  red_duration = 5;
	  amber_duration = 2;
	  green_duration = 3;
	  SCH_Init();

	  SCH_Add_Task(loop, 1, 1);

	  SCH_Add_Task(run7SEG, 1, 10);
}
