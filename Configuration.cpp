// 
// 
// 

#include "Configuration.h"

#include "LessThanCondition.h"
#include "Medianator.h"
#include "Averager.h"

// SENSORS
#define LIGHT_SENSOR 0x01
#define SOIL_SENSOR 0x02
#define DIGITAL_SENSOR 0x03
#define DHT_HUM_SENSOR 0x04
#define NOTHING 0x05

// PRECONDITIONS
#define MINUTE_DELAY_PRECONDITION 0x11
#define PLOTLY_DELAY_PRECONDITION 0x12

// VALUE_PROCESSORS
#define MEDIANATOR_5 0x21
#define AVERAGER_5 0x22

// CONDITIONS
#define ALWAYS_CONDITION 0x31
#define SOIL_DRY_CONDITION 0x32
#define DAY_CONDITION 0x33
#define FLOOD_CONDITION 0x34
#define MORNING_CONDITION 0x35
#define AFTERNOON_CONDITION 0x36

// OUTPUTS
#define AIRPUMP_RELAY_OUTPUT 0x41
#define WATERPUMP_RELAY_OUTPUT 0x42

// VIEWERS
#define SERIAL_VIEWER 0x51
#define PLOTLY_VIEWER 0x52
#define LCD_VIEWER 0x53

TimePrecondition minutePrecondition(MINUTE_DELAY_PRECONDITION, 60);
TimePrecondition plotlyDelayPrecondition(PLOTLY_DELAY_PRECONDITION, PLOTLY_INTERVAL);

// Medianator medianator(MEDIANATOR_5, 5);
Averager averager(AVERAGER_5, 3);

// LightSensor lightSensor(0);
SoilSensor soilSensor(SOIL_SENSOR, 0, &plotlyDelayPrecondition, NULL);
NoSensor noSensor(NOTHING, &minutePrecondition);
// DigitalSensor digiSensor(6);
// DhtHumSensor dhtSensor(DHT_HUM_SENSOR,12);

// AlwaysCondition always(ALWAYS_CONDITION);
LessThanCondition soilDryCondition(SOIL_DRY_CONDITION, 420);
DayTimeCondition dayTimeCondition(DAY_CONDITION, 0, -1);
AndCondition floodCondition(FLOOD_CONDITION, &dayTimeCondition, &soilDryCondition);
HourCondition morningCondition(MORNING_CONDITION, 9);
HourCondition afternoonCondition(AFTERNOON_CONDITION, 16);

// nejak 19 sekund na napusteni
RelayOutput waterPumpRelayOutput(WATERPUMP_RELAY_OUTPUT, 22, 19*ONE_SECOND);
RelayOutput airPumpRelayOutput(AIRPUMP_RELAY_OUTPUT, 23, ONE_HOUR);

SerialViewer serialViewer(SERIAL_VIEWER);
PlotlyViewer plotlyViewer(PLOTLY_VIEWER);
Ssd1306Viewer ssd1306Viewer(LCD_VIEWER, 28,29,30,31,32);
//Pcd8544Viewer pcd8544Viewer(LCD_VIEWER, 2,3,4,5,6);
