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

TimePrecondition timePrecondition(SHORT_TIME_PRECONDITION, 5);

// LightSensor lightSensor(0);
SoilSensor soilSensor(SOIL_SENSOR,0);
// DigitalSensor digiSensor(6);
//DhtHumSensor dhtSensor(DHT_HUM_SENSOR,12);

AlwaysCondition always(ALWAYS_CONDITION);
LessThanCondition lessThan(LESS_THAN_800_CONDITION,800);

RelayOutput relayOutput(RELAY_OUTPUT, 10, 3);

SerialViewer serialViewer(SERIAL_VIEWER);
PlotlyViewer plotlyViewer(PLOTLY_VIEWER);
//Pcd8544Output pcd8544Viewer(12,11,10,9,8);
