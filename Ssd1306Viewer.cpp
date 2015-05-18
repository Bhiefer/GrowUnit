/* 
* Ssd1306Viewer.cpp
*
* Created: 16.5.2015 10:50:25
* Author: Bhiefer
*/


#include "Ssd1306Viewer.h"
#include "Configuration.h"
#include "Timer.h"

Ssd1306Viewer::Ssd1306Viewer(uint8_t id, int8_t d0, int8_t d1, int8_t rst, int8_t dc, int8_t cs) : Viewer(id), Adafruit_SSD1306(d1, d0, dc, rst, cs)
{
}

uint8_t Ssd1306Viewer::onCreate()
{
	begin(SSD1306_SWITCHCAPVCC);
	display();
	
	mTotalPages = 0;
	
	uint8_t i = 0;
	for(i = 0; i < sensorsSize; i++)
	{
		mTotalPages += sensors[i]->getRulesCnt();
	}
	
	Serial.print("total:");
	Serial.println(mTotalPages);
}

uint8_t Ssd1306Viewer::onMeasured()
{	
 	uint8_t currentPage = millis()/(1000 * LCD_INTERVAL) % mTotalPages;
	uint8_t currentSensor = 0;
	uint8_t currentRule = currentPage;
	
	for(currentSensor = 0; currentSensor < sensorsSize; currentSensor++)
	{
		if(currentRule < sensors[currentSensor]->getRulesCnt())
		{
			break;
		}
		else
		{
			currentRule -= sensors[currentSensor]->getRulesCnt();
		}
	}
	 
 	clearDisplay();
 
 	setCursor(1,2);	
 	setTextSize(1);
	 
// 	setTextColor(BLACK);
	
	fillRect(0,0,128,10, BLACK);
	setTextColor(WHITE);
	
	print(currentPage + 1);
	print(F("/"));
	print(mTotalPages);
	
	print(F("    "));
	
	time_t t = timer.currentLocal();
	
	print(day(t));
	print(F("."));
	print(month(t));
	print(F(". "));
	print(hour(t));
	print(F(":"));
	
	if(minute(t) < 10)
		print(F("0"));
	print(minute(t));
	
	print(F(":"));
	
	if(second(t) < 10)
		print(F("0"));
	print(second(t));
	
	drawFastHLine(0,10,128, BLACK);
	
	setCursor(0,12);		
	char line[LCD_LINE_1_LENGTH];
	memset(line, '\0', LCD_LINE_1_LENGTH);
	
	setTextColor(BLACK);
	
	Sensor* sensor = sensors[currentSensor];
	
	sensor->toString(line, LCD_LINE_1_LENGTH);
	println(line);
	
	memset(line, '\0', LCD_LINE_1_LENGTH);
	sensor->getRules()[currentRule].condition->toString(line, LCD_LINE_1_LENGTH);
	println(line);
	
	memset(line, '\0', LCD_LINE_1_LENGTH);
	sensor->getRules()[currentRule].output->toString(line, LCD_LINE_1_LENGTH);
	println(line);
	
	display();
}
