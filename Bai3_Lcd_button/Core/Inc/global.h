#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "lcd.h"

enum ModeState {INIT,MODE_1,MODE_2, MODE_3, MODE_4};

enum TrafficLightState{RED,GREEN, YELLOW};

extern enum ModeState MODE;
extern enum TrafficLightState TRAFFIC_LIGHT_EDITING;

extern int red_count;
extern int green_count;
extern int yellow_count;

extern int editing_red_seconds;
extern int editing_green_seconds;
extern int editing_yellow_seconds;

extern int first_traffic_lights_count;
extern int second_traffic_lights_count;

extern int editing_count;

void display_seconds_while_editing(int seconds);
#endif /* INC_GLOBAL_H_ */