#include "traffic_lights.h"

void display_first_traffic_lights(){
	lcd_Fill(15, 50, 50, 20, WHITE);
	int total_time_count =red_count + green_count + yellow_count;
	first_traffic_lights_count = (first_traffic_lights_count + 1) % total_time_count;

	if(first_traffic_lights_count < red_count)
	{
		lcd_ShowIntNum(15, 50, (total_time_count - first_traffic_lights_count - green_count - yellow_count + 20)/20, 4, BRED, WHITE, 32);
		lcd_DrawCircle(60, 200, WHITE, 20, 1);
		lcd_DrawCircle(60, 120, RED, 20, 1);
		lcd_DrawCircle(60, 200, YELLOW, 20, 0);
		lcd_DrawCircle(60, 280, GREEN, 20, 0);
		return;
	}
	lcd_Fill(15, 50, 50, 20, WHITE);
	if(first_traffic_lights_count < (red_count + green_count)){
		lcd_ShowIntNum(15, 50, (total_time_count - first_traffic_lights_count - yellow_count + 20)/20, 4, BRED, WHITE, 32);
		lcd_DrawCircle(60, 120, WHITE, 20, 1);
		lcd_DrawCircle(60, 120, RED, 20, 0);
		lcd_DrawCircle(60, 200, YELLOW, 20, 0);
		lcd_DrawCircle(60, 280, GREEN, 20, 1);
		return;
	}
	lcd_Fill(15, 50, 50, 20, WHITE);
	lcd_ShowIntNum(15, 50, (total_time_count - first_traffic_lights_count + 20)/20, 4, BRED, WHITE, 32);
	lcd_DrawCircle(60, 280, WHITE, 20, 1);
	lcd_DrawCircle(60, 120, RED, 20, 0);
	lcd_DrawCircle(60, 200, YELLOW, 20, 1);
	lcd_DrawCircle(60, 280, GREEN, 20, 0);
}

void display_second_traffic_lights(){
	lcd_Fill(150, 50, 50, 20, WHITE);
	int total_time_count =red_count + green_count + yellow_count;
    second_traffic_lights_count = (second_traffic_lights_count + 1) % total_time_count;
    if(second_traffic_lights_count < green_count)
    {
        lcd_ShowIntNum(100, 50, (total_time_count - second_traffic_lights_count - red_count - yellow_count + 20)/20, 4, BRED, WHITE, 32);
        lcd_DrawCircle(160, 120, WHITE, 20, 1);
        lcd_DrawCircle(160, 120, RED, 20, 0);
        lcd_DrawCircle(160, 200, YELLOW, 20, 0);
        lcd_DrawCircle(160, 280, GREEN, 20, 1);
        return;
    }
    lcd_Fill(150, 50, 50, 20, WHITE);
    if( second_traffic_lights_count < (green_count + yellow_count)){
        lcd_ShowIntNum(100, 50, (total_time_count - second_traffic_lights_count - red_count+ 20)/20, 4, BRED, WHITE, 32);
    	lcd_DrawCircle(160, 280, WHITE, 20, 1);
        lcd_DrawCircle(160, 120, RED, 20, 0);
        lcd_DrawCircle(160, 200, YELLOW, 20, 1);
        lcd_DrawCircle(160, 280, GREEN, 20, 0);
        return;
    }
    lcd_Fill(150, 50, 50, 20, WHITE);
    lcd_ShowIntNum(100, 50, (total_time_count - second_traffic_lights_count+20)/20, 4, BRED, WHITE, 32);
    lcd_DrawCircle(160, 200, WHITE, 20, 1);
    lcd_DrawCircle(160, 120, RED, 20, 1);
    lcd_DrawCircle(160, 200, YELLOW, 20, 0);
    lcd_DrawCircle(160, 280, GREEN, 20, 0);

}
void display_editing_lights(){
	editing_count = (editing_count+1)%10;
	if(editing_count == 5){
		switch(TRAFFIC_LIGHT_EDITING){
			case RED_STATE:
				lcd_DrawCircle(160, 120, RED, 20, 1);
				lcd_DrawCircle(60, 120, RED, 20, 1);	
				break;
			case GREEN_STATE:
				lcd_DrawCircle(160, 120, GREEN, 20, 1);
				lcd_DrawCircle(60, 120, GREEN, 20, 1);	
				break;
			case YELLOW_STATE:
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

void turn_off_lights(){
	lcd_Clear(WHITE);
}
	
