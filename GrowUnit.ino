/*
Web client

This sketch connects to a website (http://www.google.com)
using an Arduino Wiznet Ethernet shield.

Circuit:
* Ethernet shield attached to pins 10, 11, 12, 13

created 18 Dec 2009
modified 9 Apr 2012
by David A. Mellis

*/

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SPI.h>
#include <Ethernet.h>
#include <DS3231RTC.h>
#include <Wire.h>
#include <Time.h>
#include <ArduinoJson.h>
#include <JsonGenerator.h>
#include <RunningMedian.h>
#include <RunningAverage.h>
#include "Configuration.h"
#include "Timer.h"


static int16_t counter;

void reset()
{
//	digitalWrite(RESET_PIN, LOW);
}

void setup()
{
// 	digitalWrite(RESET_PIN, HIGH);
// 	delay(2000);
// 	pinMode(RESET_PIN, OUTPUT);     
	
	counter = 0;
	uint8_t i = 0;
	uint8_t res = RC_OK;
	
	// SET CLOCK
// 	DS3231RTC t;
// 	t.set(1429698480);

	for(i = 0; i < viewersSize; i++)
	{
		res = viewers[i]->onCreate();
		
		if(res == RC_FATAL_FAILURE)
		{
			reset();
		}
	}
	
	for(i = 0; i < outputsSize; i++)
	{
		outputs[i]->onCreate();
	}
	
	for(i = 0; i < sensorsSize; i++)
	{
		sensors[i]->onCreate();
	}
	
// 	for(i = 0; i < preconditionMappingSize; i++)
// 	{
// 		preconditionMapping[i].sensor->setPrecondition(preconditionMapping[i].precondition);
// 	}
	
	for(i = 0; i < mappingSize; i++)
	{
		mapping[i].sensor->addRule(mapping[i].condition, mapping[i].output);
	}
}

void printHeader()
{
	time_t t = timer.currentLocal();
	
	Serial.print(day(t));
	Serial.print('.');
	Serial.print(month(t));
	Serial.print('.');
	Serial.print(year(t));
	Serial.print(' ');
	Serial.print(hour(t));
	printDigits(minute(t));
	printDigits(second(t));
	Serial.print(" - loop ");
	Serial.println(counter++);
}

void printDigits(int digits)
{
	// utility function for digital clock display: prints preceding colon and leading 0
	Serial.print(":");
	if(digits < 10)
	Serial.print('0');
	Serial.print(digits);
}

void loop()
{
	printHeader();

	for(uint8_t i = 0; i < sensorsSize; i++)
	{
		sensors[i]->measure();
	}
	
	for(uint8_t i = 0; i < outputsSize; i++)
	{
		outputs[i]->onMeasured();
	}
	
	for(uint8_t i = 0; i < viewersSize; i++)
	{
		viewers[i]->onMeasured();
	}
	
	Serial.println("----------------------------------------");
	delay(1000);
}
