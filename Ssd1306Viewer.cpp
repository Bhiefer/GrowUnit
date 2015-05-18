/* 
* Ssd1306Viewer.cpp
*
* Created: 16.5.2015 10:50:25
* Author: Bhiefer
*/


#include "Ssd1306Viewer.h"
#include "Configuration.h"

Ssd1306Viewer::Ssd1306Viewer(uint8_t id, int8_t d0, int8_t d1, int8_t rst, int8_t dc, int8_t cs) : Viewer(id), Adafruit_SSD1306(d1, d0, dc, rst, cs)
{
}

uint8_t Ssd1306Viewer::onCreate()
{
	begin(SSD1306_SWITCHCAPVCC);
	display();
}

uint8_t Ssd1306Viewer::onMeasured()
{
 	uint8_t currentSensor = millis()/(1000 * LCD_INTERVAL) % sensorsSize;
 	clearDisplay();
 
 	setCursor(0,0);	
 	setTextSize(1);
	
	char line[LCD_LINE_1_LENGTH];
	memset(line, '\0', LCD_LINE_1_LENGTH);
	
	Sensor* sensor = sensors[currentSensor];
	
	sensor->toString(line, LCD_LINE_1_LENGTH);
	println(line);
	
	for(uint8_t i = 0; i < sensor->getRulesCnt(); i++ )
	{
		memset(line, '\0', LCD_LINE_1_LENGTH);
		sensor->getRules()[i].output->toString(line, LCD_LINE_1_LENGTH);
		println(line);
	}
	
	
	// 	uint8_t i = 0;
	// 	for(i = 0; i< sensorsSize; i++)
	// 	{
	// 		sensors[i].
	// 	}
	
	//	fillRect(0, 0, width(), 16, BLACK);
	
	
	// 	setTextSize(2);
	// 	setTextColor(WHITE);
	// 	setCursor(0,1);
	// 	println("Info");
	//
	// 	setTextSize(1);
	// 	setTextColor(BLACK);
	// 	print("Puda:");
	// 	println(mLight);
	//	print("Plovak:");
	//	println((mSwitch == HIGH) ? "nahore" : "dole");
	display();
}
