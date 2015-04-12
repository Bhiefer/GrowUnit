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
#define SERIAL_OUTPUT 0
#define RELAY_OUTPUT 1

// LightSensor lightSensor(0);
//SoilSensor soilSensor(0);
// DigitalSensor digiSensor(6);
DhtHumSensor dhtSensor(DHT_HUM_SENSOR,12);

AlwaysCondition always(ALWAYS_CONDITION);
LessThanCondition lessThan(LESS_THAN_800_CONDITION,800);

TimePrecondition timePrecondition(SHORT_TIME_PRECONDITION, 5);

RelayOutput relayOutput(RELAY_OUTPUT, 10, 3);
SerialOutput serialOutput(SERIAL_OUTPUT);
//Pcd8544Output pcd8544Output(12,11,10,9,8);
