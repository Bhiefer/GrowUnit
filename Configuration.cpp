// 
// 
// 

#include "Configuration.h"

// SENSORS
#define LIGHT_SENSOR 0
#define SOIL_SENSOR 1
#define DIGITAL_SENSOR 2
#define DHT_HUM_SENSOR 3

// PRECONDITIONS
#define SHORT_TIME_PRECONDITION 0

// CONDITIONS
#define ALWAYS_CONDITION 0
#define LESS_THAN_800_CONDITION 1

// OUTPUTS
#define RELAY_OUTPUT 0

// VIEWERS
#define SERIAL_VIEWER 0
#define PLOTLY_VIEWER 1
#define LCD_VIEWER 2

TimePrecondition timePrecondition(SHORT_TIME_PRECONDITION, 60);

// LightSensor lightSensor(0);
SoilSensor soilSensor(SOIL_SENSOR, 0);
// DigitalSensor digiSensor(6);
//DhtHumSensor dhtSensor(DHT_HUM_SENSOR,12);

AlwaysCondition always(ALWAYS_CONDITION);
LessThanCondition lessThan(LESS_THAN_800_CONDITION,40);

// nejak 20 sekund na napusteni
RelayOutput relayOutput(RELAY_OUTPUT, 22, 19);

SerialViewer serialViewer(SERIAL_VIEWER);
PlotlyViewer plotlyViewer(PLOTLY_VIEWER);
//Pcd8544Viewer pcd8544Viewer(LCD_VIEWER, 2,3,4,5,6);
