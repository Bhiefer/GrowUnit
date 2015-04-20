/*
* Pcd8544Viewer.cpp
*
* Created: 26.1.2014 17:34:41
* Author: Bhiefer
*/


#include "Pcd8544Viewer.h"
#include "Configuration.h"

Pcd8544Viewer::Pcd8544Viewer( uint8_t id, int8_t rst, int8_t ce, int8_t dc, int8_t din, int8_t clk ) : Viewer(id), Adafruit_PCD8544(clk, din, dc, ce, rst)
{
}

uint8_t Pcd8544Viewer::onCreate()
{
	begin();
	setContrast(50);
}

uint8_t Pcd8544Viewer::onMeasured()
{
	uint8_t currentSensor = millis()/(1000 * LCD_INTERVAL) % sensorsSize;
	clearDisplay();
	
	setTextSize(1);
	setTextColor(BLACK);
	print("Puda:");
	
// 	char line[LCD_LINE_1_LENGTH];
// 	memset(line, '\0', LCD_LINE_1_LENGTH);
// 	
// 	Sensor* sensor = sensors[currentSensor];
// 	
// 	sensor->toString(line, LCD_LINE_1_LENGTH);
// 	println(line);
// 	
// 	for(uint8_t i = 0; i < sensor->getRulesCnt(); i++ )
// 	{
// 		memset(line, '\0', LCD_LINE_1_LENGTH);
// 		sensor->getRules()[i].output->toString(line, LCD_LINE_1_LENGTH);
// 		println(line);
// 	}
	
	
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
