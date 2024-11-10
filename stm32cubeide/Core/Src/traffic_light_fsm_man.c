/*
 * traffic_light_fsm_man.c
 *
 *  Created on: Sep 25, 2024
 *      Author: hachi
 */

#include "traffic_light_fsm_man.h"

void traffic_light_fsm_man(){
	switch (status) {
		case MAN_RED_GREEN:
			if(isFlagTimer(0)|| isButtonPressed(BT_MODE)){
				status = INIT;
			}else if(isButtonPressed(BT_SET)){
				status = MAN_RED_AMBER;
				led_on(WAY1, RED);
				led_on(WAY2, AMBER);
				setTimer(0, MANUAL_TIMEOUT);
			}
			break;
		case MAN_RED_AMBER:
			if(isFlagTimer(0)|| isButtonPressed(BT_MODE)){
				status = INIT;
			}else if(isButtonPressed(BT_SET)){
				status = MAN_GREEN_RED;
				led_on(WAY1, GREEN);
				led_on(WAY2, RED);
				setTimer(0, MANUAL_TIMEOUT);
			}
			break;
		case MAN_GREEN_RED:
			if(isFlagTimer(0)|| isButtonPressed(BT_MODE)){
				status = INIT;
			}else if(isButtonPressed(BT_SET)){
				status = MAN_AMBER_RED;
				led_on(WAY1, AMBER);
				led_on(WAY2, RED);
				setTimer(0, MANUAL_TIMEOUT);
			}
			break;
		case MAN_AMBER_RED:
			if(isFlagTimer(0)|| isButtonPressed(BT_MODE)){
				status = INIT;
			}else if(isButtonPressed(BT_SET)){
				status = MAN_RED_GREEN;
				led_on(WAY1, RED);
				led_on(WAY2, GREEN);
				setTimer(0, MANUAL_TIMEOUT);
			}
			break;
		default:
			break;
	}
}
