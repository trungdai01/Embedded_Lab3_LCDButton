#include "fsm_simple_buttons.h"

void fsm_simple_buttons_run(void) {
	switch(MODE) {
		case INIT:
			MODE = MODE_1;
			break;
		case MODE_1:
			if(button_count[0] == 1){
                MODE = MODE_2;
                TRAFFIC_LIGHT_EDITING = RED;
            }
            display_first_traffic_lights();
            display_second_traffic_lights();
			break;
		case MODE_2:
            display_editing_lights();
			if(button_count[0] == 1){
                MODE = MODE_3;
                TRAFFIC_LIGHT_EDITING = GREEN;
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
			 if(button_count[0] == 1){
                MODE = MODE_4;
                TRAFFIC_LIGHT_EDITING = YELLOW;
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
            if(button_count[0] == 1){
                MODE = MODE_1;
                first_traffic_lights_count = 0;
                second_traffic_lights_count = 0;
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