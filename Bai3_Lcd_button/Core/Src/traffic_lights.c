#include "traffic_lights.h"

int total_time_count = red_count + green_count + yellow_count;

void display_first_traffic_lights(){
	first_traffic_lights_count = (first_traffic_lights_count + 1) % total_time_count;
	lcd_ShowIntNum(50, 2, first_traffic_lights_count, 4, BRED, WHITE, 32);
	if(first_traffic_lights_count < red_count)
	{
		lcd_DrawCircle(60, 200, WHITE, 20, 1);
		lcd_DrawCircle(60, 120, RED, 20, 1);
		lcd_DrawCircle(60, 200, YELLOW, 20, 0);
		lcd_DrawCircle(60, 280, GREEN, 20, 0);
		return;
	}
	if(first_traffic_lights_count >= red_count && first_traffic_lights_count < (red_count + green_count)){
		lcd_DrawCircle(60, 120, WHITE, 20, 1);
		lcd_DrawCircle(60, 120, RED, 20, 0);
		lcd_DrawCircle(60, 200, YELLOW, 20, 0);
		lcd_DrawCircle(60, 280, GREEN, 20, 1);
		return;
	}
	lcd_DrawCircle(60, 280, WHITE, 20, 1);
	lcd_DrawCircle(60, 120, RED, 20, 0);
	lcd_DrawCircle(60, 200, YELLOW, 20, 1);
	lcd_DrawCircle(60, 280, GREEN, 20, 0);
};
void display_second_traffic_lights(){
    second_traffic_lights_count = (second_traffic_lights_count + 1) % total_time_count;
    if(second_traffic_lights_count < green_count)
    {
        lcd_DrawCircle(160, 120, WHITE, 20, 1);
        lcd_DrawCircle(160, 120, RED, 20, 0);
        lcd_DrawCircle(160, 200, YELLOW, 20, 0);
        lcd_DrawCircle(160, 280, GREEN, 20, 1);
        return;
    }
    if(second_traffic_lights_count >= green_count && second_traffic_lights_count < (green_count + yellow_count)){
        lcd_DrawCircle(160, 280, WHITE, 20, 1);
        lcd_DrawCircle(160, 120, RED, 20, 0);
        lcd_DrawCircle(160, 200, YELLOW, 20, 1);
        lcd_DrawCircle(160, 280, GREEN, 20, 0);
        return;
    }
    lcd_DrawCircle(160, 200, WHITE, 20, 1);
    lcd_DrawCircle(160, 120, RED, 20, 1);
    lcd_DrawCircle(160, 200, YELLOW, 20, 0);
    lcd_DrawCircle(160, 280, GREEN, 20, 0);
}
void display_editing_lights(){
	editing_count = (editing_count+1)%10;
	if(editing_count == 5){
		switch(TRAFFIC_LIGHT_EDITING){
			case RED:
				lcd_DrawCircle(160, 120, RED, 20, 1);
				lcd_DrawCircle(60, 120, RED, 20, 1);	
				break;
			case GREEN:
				lcd_DrawCircle(160, 120, GREEN, 20, 1);
				lcd_DrawCircle(60, 120, GREEN, 20, 1);	
				break;
			case YELLOW:
				lcd_DrawCircle(160, 120, YELLOW, 20, 1);
				lcd_DrawCircle(60, 120, YELLOW, 20, 1);	
				break;
			default: 
				break;
		}
	}
	if(editing_count == 0){
		lcd_DrawCircle(160, 120, WHITE, 20, 0);
		lcd_DrawCircle(60, 120, WHITE, 20, 0);
	}
}
	