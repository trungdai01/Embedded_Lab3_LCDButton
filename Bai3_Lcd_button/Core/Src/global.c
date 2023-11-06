#include "global.h"

enum ModeState MODE;
enum TrafficLightState TRAFFIC_LIGHT_EDITING;

int red_count = 100; //5s
int green_count = 60; //3s
int yellow_count = 20; //1s

int editing_red_seconds = 5;
int editing_green_seconds = 3;
int editing_yellow_seconds = 1;

int first_traffic_lights_count = 0;
int second_traffic_lights_count = 0;

int editing_count = 0;

void display_seconds_while_editing(int seconds){
    lcd_ShowIntNum(50, 2, seconds, 4, BRED, WHITE, 32);
}