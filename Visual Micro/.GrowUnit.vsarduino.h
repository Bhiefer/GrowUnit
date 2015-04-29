/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Mega w/ ATmega2560 (Mega 2560), Platform=avr, Package=arduino
*/

#define __AVR_ATmega2560__
#define ARDUINO 155
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

void reset();
//
void printHeader();
void printDigits(int digits);
//

#include "c:\Development\Arduino\arduino-1.5.5\hardware\arduino\avr\variants\mega\pins_arduino.h" 
#include "c:\Development\Arduino\arduino-1.5.5\hardware\arduino\avr\cores\arduino\arduino.h"
#include <GrowUnit.ino>
#include <AlwaysCondition.cpp>
#include <AlwaysCondition.h>
#include <AnalogSensor.cpp>
#include <AnalogSensor.h>
#include <AndCondition.cpp>
#include <AndCondition.h>
#include <Condition.cpp>
#include <Condition.h>
#include <Configuration.cpp>
#include <Configuration.h>
#include <Constants.h>
#include <DHT.cpp>
#include <DHT.h>
#include <Data.cpp>
#include <Data.h>
#include <DayTimeCondition.cpp>
#include <DayTimeCondition.h>
#include <DhtHumSensor.cpp>
#include <DhtHumSensor.h>
#include <DhtSensor.cpp>
#include <DhtSensor.h>
#include <DhtTempSensor.cpp>
#include <DhtTempSensor.h>
#include <DigitalSensor.cpp>
#include <DigitalSensor.h>
#include <EthernetOutput.cpp>
#include <EthernetOutput.h>
#include <ICondition.h>
#include <IObject.h>
#include <IOutput.h>
#include <IPrecondition.h>
#include <ISensor.h>
#include <IValueProcessor.h>
#include <IViewer.h>
#include <LessThanCondition.cpp>
#include <LessThanCondition.h>
#include <LightSensor.cpp>
#include <LightSensor.h>
#include <Medianator.cpp>
#include <Medianator.h>
#include <MemoryFree.cpp>
#include <MemoryFree.h>
#include <NoSensor.h>
#include <Object.cpp>
#include <Object.h>
#include <Output.cpp>
#include <Output.h>
#include <Pcd8544Viewer.cpp>
#include <Pcd8544Viewer.h>
#include <PlotlyViewer.cpp>
#include <PlotlyViewer.h>
#include <Precondition.cpp>
#include <Precondition.h>
#include <RelayOutput.cpp>
#include <RelayOutput.h>
#include <Sensor.cpp>
#include <Sensor.h>
#include <SerialViewer.cpp>
#include <SerialViewer.h>
#include <SoilSensor.cpp>
#include <SoilSensor.h>
#include <Structs.h>
#include <TimePrecondition.cpp>
#include <TimePrecondition.h>
#include <Timer.cpp>
#include <Timer.h>
#include <ValueProcessor.cpp>
#include <ValueProcessor.h>
#include <Viewer.cpp>
#include <Viewer.h>
#include <plotly_streaming_ethernet.cpp>
#include <plotly_streaming_ethernet.h>
