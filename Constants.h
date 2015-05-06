/*
 * IncFile1.h
 *
 * Created: 18.1.2014 23:03:51
 *  Author: Bhiefer
 */ 


#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "Arduino.h"

// IP config
static uint8_t DEVICE_MAC[] = { 0xDE, 0xAD, 0xCE, 0xEF, 0xFE, 0xED };
static const uint8_t DEVICE_IP[] = { 192, 168, 0, 194 };
static const uint8_t SERVER_IP[] = { 192, 168, 0, 102};
// static const uint8_t SERVER_PORT = 80;

// #define DEVICE_MAC {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}
// #define DEVICE_IP {192, 168, 0, 194}
// #define SERVER_IP {192, 168, 1, 102}
#define SERVER_PORT 80

// System
#define RESET_PIN 12

#define ONE_SECOND 1
#define ONE_MINUTE 60
#define ONE_HOUR 3600

#define TIMEZONE_SHIFT 2
#define TIMEZONE_SHIFT_SECONDS (TIMEZONE_SHIFT*ONE_HOUR)

// Plotly
#define PLOTLY_USERNAME "Bhiefer"
#define PLOTLY_API_KEY "r01kk61tqn"
#define PLOTLY_FILENAME "Chillies"
#define PLOTLY_TOKENS_SIZE 2
static char * PLOTLY_TOKENS[PLOTLY_TOKENS_SIZE] = {"3fk2esiajr", "fphyo0oeoh"};
#define PLOTLY_INTERVAL 20 // in seconds
#define PLOTLY_PLOT_SIZE 8 // in hours

// LCD
#define LCD_INTERVAL 5
#define LCD_LINE_1_LENGTH 25

// Serial
#define SERIAL_INTERVAL 10
#define SERIAL_SPEED 9600

// Sensors
#define MAX_RULES_COUNT 3
#define MAX_MEASUREMENTS_COUNT 10

// RESULT CODES
#define RC_OK 0

#define RC_OUT_OF_MEMORY_INSTANCE_FULL 20

#define RC_PRECONDITION_NOT_MET 30

#define RC_FATAL_FAILURE 40



#endif /* CONSTANTS_H_ */