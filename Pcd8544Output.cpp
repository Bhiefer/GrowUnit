/* 
* Pcd8544Output.cpp
*
* Created: 26.1.2014 17:34:41
* Author: Bhiefer
*/


#include "Pcd8544Output.h"

 Pcd8544Output::Pcd8544Output( int8_t rst, int8_t ce, int8_t dc, int8_t din, int8_t clk ) : Adafruit_PCD8544(clk, din, dc, ce, rst)
{
}

uint8_t Pcd8544Output::onCreate()
{
	 begin();
	 setContrast(50);
}

uint8_t Pcd8544Output::onReceive( int16_t value, Sensor * sensor )
{
	mLight = value;
}

uint8_t Pcd8544Output::onMeasured()
{
	clearDisplay();
	
	fillRect(0, 0, width(), 16, BLACK);
	
	
	setTextSize(2);
	setTextColor(WHITE);
	setCursor(0,1);
	println("Info");
	
	setTextSize(1);
	setTextColor(BLACK);
	print("Svetlo:");
	println(mLight);
	display();
}