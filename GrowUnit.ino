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
#include <Adafruit_SSD1306.h>
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
#include <EEPROMex.h>
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

	int16_t eeprom = 0;
	
	uint32_t hash = EEPROM.readLong(eeprom);
	eeprom += sizeof(uint32_t);
	
	bool hashValid = hash == getConfigurationHash();

	for(i = 0; i < viewersSize; i++)
	{
 		if(hashValid && viewers[i]->isUsingEeprom())
 		{
 			eeprom += viewers[i]->restoreFromEeprom(eeprom);
 		}
		
		res = viewers[i]->onCreate();
		
		if(res == RC_FATAL_FAILURE)
		{
			reset();
		}
	}
	
	for(i = 0; i < outputsSize; i++)
	{
		if(hashValid && outputs[i]->isUsingEeprom())
		{
			eeprom += outputs[i]->restoreFromEeprom(eeprom);
		}
		
		outputs[i]->onCreate();
	}
	
	for(i = 0; i < sensorsSize; i++)
	{
		if(hashValid && sensors[i]->isUsingEeprom())
		{
			eeprom += sensors[i]->restoreFromEeprom(eeprom);
		}
		
		sensors[i]->onCreate();
	}
	
	for(i = 0; i < conditionsSize; i++)
	{
		if(hashValid && conditions[i]->isUsingEeprom())
		{
			eeprom += conditions[i]->restoreFromEeprom(eeprom);
		}
	}
	
	for(i = 0; i < mappingSize; i++)
	{
		mapping[i].sensor->addRule(mapping[i].condition, mapping[i].output);
	}
}

void printHeader()
{
	time_t t = timer.currentLocal();
	
	Serial.print(day(t));
	Serial.print(F("."));
	Serial.print(month(t));
	Serial.print(F("."));
	Serial.print(year(t));
	Serial.print(F(" "));
	Serial.print(hour(t));
	printDigits(minute(t));
	printDigits(second(t));
	Serial.print(F(" - loop "));
	Serial.println(counter++);
}

void printDigits(int digits)
{
	// utility function for digital clock display: prints preceding colon and leading 0
	Serial.print(F(":"));
	if(digits < 10)
	Serial.print(F("0"));
	Serial.print(digits);
}

void loop()
{
	printHeader();
	
	int16_t eeprom = 0;
	
	EEPROM.updateLong(eeprom, getConfigurationHash());
	eeprom += sizeof(uint32_t);

	for(uint8_t i = 0; i < sensorsSize; i++)
	{
		sensors[i]->measure();
		
		if(sensors[i]->isUsingEeprom())
		{
			eeprom += sensors[i]->storeToEeprom(eeprom);
		}
	}
	
	for(uint8_t i = 0; i < outputsSize; i++)
	{
		outputs[i]->onMeasured();
		
		if(outputs[i]->isUsingEeprom())
		{
			eeprom += outputs[i]->storeToEeprom(eeprom);
		}
	}
	
	for(uint8_t i = 0; i < viewersSize; i++)
	{
		viewers[i]->onMeasured();
		
		if(viewers[i]->isUsingEeprom())
		{
			eeprom += viewers[i]->storeToEeprom(eeprom);
		}
	}
	
	for(uint8_t i = 0; i < conditionsSize; i++)
	{		
		if(conditions[i]->isUsingEeprom())
		{
			eeprom += conditions[i]->storeToEeprom(eeprom);
		}
	}
	
	Serial.println("----------------------------------------");
	delay(1000);
}

uint32_t getConfigurationHash()
{
	uint8_t i = 0;
	uint32_t h = 0;
	uint8_t size = 0;
	
	for(i = 0; i < viewersSize; i++)
	{
		if(viewers[i]->isUsingEeprom())
		{
			h = HASH_INT_MULTIPLIER * h + viewers[i]->getId();
			size++;
		}
	}
	
	for(i = 0; i < outputsSize; i++)
	{
		if(outputs[i]->isUsingEeprom())
		{
			h = HASH_INT_MULTIPLIER * h + outputs[i]->getId();
			size++;
		}
	}
	
	for(i = 0; i < conditionsSize; i++)
	{
		if(conditions[i]->isUsingEeprom())
		{
			h = HASH_INT_MULTIPLIER * h + conditions[i]->getId();
			size++;
		}
	}
	
	for(i = 0; i < sensorsSize; i++)
	{
		if(sensors[i]->isUsingEeprom())
		{
			h = HASH_INT_MULTIPLIER * h + sensors[i]->getId();
			size++;
		}
		
		if(sensors[i]->getPrecondition() != NULL)
		{
			if(sensors[i]->getPrecondition()->isUsingEeprom())
			{
				h = HASH_INT_MULTIPLIER * h + sensors[i]->getPrecondition()->getId();
				size++;
			}
		}
	}
	
	return h % size;
}
