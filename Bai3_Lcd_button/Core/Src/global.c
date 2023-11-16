#include "global.h"

enum ModeState MODE;
enum TrafficLightState TRAFFIC_LIGHT_EDITING;

int one_second_count = 0;

int red_count = 100; //5s
int green_count = 60; //3s
int yellow_count = 40; //2s

int editing_red_seconds = 5;
int editing_green_seconds = 3;
int editing_yellow_seconds = 2;

int first_traffic_lights_count = 0;
int second_traffic_lights_count = 0;

int first_traffic_lights_count_down;
int second_traffic_lights_count_down;

int editing_count = 0;

void display_seconds_while_editing(int seconds){
    lcd_ShowIntNum(60, 2, seconds, 4, BRED, WHITE, 32);
}
