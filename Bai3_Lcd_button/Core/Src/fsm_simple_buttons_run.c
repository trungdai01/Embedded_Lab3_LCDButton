#include "fsm_simple_buttons_run.h"

void fsm_simple_buttons_run(void) {
	button_Scan();
	one_second_count = (one_second_count + 1)%20;
	switch(MODE) {
		case INIT:
			MODE = MODE_1;
			break;
		case MODE_1:
			if(button_count[0] == 1){
                MODE = MODE_2;
                turn_off_lights();
                TRAFFIC_LIGHT_EDITING = RED_STATE;
                break;
            }
            display_first_traffic_lights();
            display_second_traffic_lights();
			break;
		case MODE_2:
            display_editing_lights();
            display_seconds_while_editing(editing_red_seconds);
			if(button_count[0] == 1){
                MODE = MODE_3;
                turn_off_lights();
                TRAFFIC_LIGHT_EDITING = GREEN_STATE;
                editing_red_seconds = red_count/20;
                break;
            }
            if(button_count[1] == 1){
                editing_red_seconds++;
            }
            if(button_count[2] == 1){
                red_count = editing_red_seconds * 20;
            }
			break;
		case MODE_3:
            display_editing_lights();
            display_seconds_while_editing(editing_green_seconds);
			 if(button_count[0] == 1){
                MODE = MODE_4;
                turn_off_lights();
                editing_green_seconds = green_count/20;
                TRAFFIC_LIGHT_EDITING = YELLOW_STATE;
                break;
            }
            if(button_count[1] == 1){
                editing_green_seconds++;
            }
            if(button_count[2] == 1){
                green_count = editing_green_seconds * 20;
            }
            break;
        case MODE_4:
            display_editing_lights();
            display_seconds_while_editing(editing_yellow_seconds);
            if(button_count[0] == 1){
                MODE = MODE_1;
                turn_off_lights();
                first_traffic_lights_count = 0;
                second_traffic_lights_count = 0;
                editing_yellow_seconds = yellow_count/20;
                break;
            }
             if(button_count[1] == 1){
                editing_yellow_seconds++;
            }
            if(button_count[2] == 1){
                yellow_count = editing_yellow_seconds * 20;
            }
			break;
		default:
			break;
	}
}
