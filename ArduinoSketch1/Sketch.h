/*
 * Main.cpp
 *
 * Created: 11/14/2013 4:19:31 PM
 *  Author: zdene_000
 */


#ifndef SKETCH_H_
#define SKETCH_H_

#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef UTILITY_MACROS_H_
#include "Utility\UtilityMacros.h"
#endif

#ifndef BUILDINFO_H_
#include "Utility/Buildinfo.h"
#endif

/* LED Output */
const uint8_t LED = 13;

/* Delay between blinks */
const unsigned long DELAY_LENGTH = 250;

/* Serial Speed */
const unsigned long SERIAL_SPEED = 9600;

/* Serial Message */
const char* MESSAGE = "Hello World! - ";

void setup();
void loop();



#endif /* SKETCH_H_ */