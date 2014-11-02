/*
 * IncFile1.h
 *
 * Created: 18.1.2014 23:03:51
 *  Author: Bhiefer
 */ 


#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// IP config
static uint8_t DEVICE_MAC[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
static const uint8_t DEVICE_IP[] = { 192, 168, 1, 88 };
static const uint8_t SERVER_IP[] = { 192, 168, 1, 102};
static const uint8_t SERVER_PORT = 80;

// Sensors
static const uint8_t MAX_RULES_COUNT = 5;
static const uint8_t MAX_MEASUREMENTS_COUNT = 10;

// RESULT CODES
static const uint8_t RC_OK = 0;

static const uint8_t RC_OUT_OF_MEMORY_INSTANCE_FULL = 20;



#endif /* CONSTANTS_H_ */