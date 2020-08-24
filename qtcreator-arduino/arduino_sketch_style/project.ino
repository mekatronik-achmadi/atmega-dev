/*
Project:	%ProjectName%
Board:		%BOARD_TAG%
MCU:		%BOARD_MCU%	
FRENQUENCY:	%BOARD_F%

Created using Qt Creator
*/

#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

//******************************
//* SETUP AND LOOP SECTION
//* Always leave setup() and loop() functions at the end of file
void setup() {                
	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
	pinMode(13, OUTPUT);     
}

void loop() {
	digitalWrite(13, HIGH);   // set the LED on
	delay(1000);              // wait for a second
	digitalWrite(13, LOW);    // set the LED off
	delay(1000);              // wait for a second
}

