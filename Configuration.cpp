// 
// 
// 

#include "Configuration.h"

#include "LessThanCondition.h"
#include "Medianator.h"
#include "Averager.h"

// SENSORS
#define LIGHT_SENSOR 0
#define SOIL_SENSOR 1
#define DIGITAL_SENSOR 2
#define DHT_HUM_SENSOR 3
#define NOTHING 4

// PRECONDITIONS
#define MINUTE_DELAY_PRECONDITION 0
#define PLOTLY_DELAY_PRECONDITION 1

// VALUE_PROCESSORS
#define MEDIANATOR_5 0
#define AVERAGER_5 1

// CONDITIONS
#define ALWAYS_CONDITION 0
#define SOIL_DRY_CONDITION 1
#define DAY_CONDITION 2
#define FLOOD_CONDITION 3
#define MORNING_CONDITION 4
#define AFTERNOON_CONDITION 5

// OUTPUTS
#define AIRPUMP_RELAY_OUTPUT 0
#define WATERPUMP_RELAY_OUTPUT 1

// VIEWERS
#define SERIAL_VIEWER 0
#define PLOTLY_VIEWER 1
#define LCD_VIEWER 2

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
DayTimeCondition dayTimeCondition(DAY_CONDITION, 7, 18);
AndCondition floodCondition(FLOOD_CONDITION, &dayTimeCondition, &soilDryCondition);
HourCondition morningCondition(MORNING_CONDITION, 9);
HourCondition afternoonCondition(AFTERNOON_CONDITION, 16);

// nejak 19 sekund na napusteni
RelayOutput waterPumpRelayOutput(WATERPUMP_RELAY_OUTPUT, 22, 19*ONE_SECOND);
RelayOutput airPumpRelayOutput(AIRPUMP_RELAY_OUTPUT, 23, ONE_HOUR);

SerialViewer serialViewer(SERIAL_VIEWER);
PlotlyViewer plotlyViewer(PLOTLY_VIEWER);
//Pcd8544Viewer pcd8544Viewer(LCD_VIEWER, 2,3,4,5,6);
