/*
Project:	%ProjectName%
Board:		%BOARD_TAG%
MCU:		%BOARD_MCU%	
FRENQUENCY:	%BOARD_F%

Created using QtCreator
*/

#include <Arduino.h>
#include <avr/io.h>

#define LED_PIN     13
#define DELAY_MS    1000

int main()
{
    // Initialize Arduino Librairies
    init();

	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
    pinMode(LED_PIN, OUTPUT);

    while (1)
    {
	digitalWrite(LED_PIN, HIGH);   // set the LED on
	delay(DELAY_MS);              // wait for a second
	digitalWrite(LED_PIN, LOW);    // set the LED off
	delay(DELAY_MS);              // wait for a second
    }

}
