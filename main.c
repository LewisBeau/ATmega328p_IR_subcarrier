/*
 * eANTS_subcarrierArduino.c
 *
 * Created: 06/12/2017 20:10:14
 * Author : lewis
 */ 


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include "avr/interrupt.h"
#include "avr/delay.h"


int dutyCycle = 0;


int main(void)
{
    /*This program creates a PWM signal on PORTD6 at 38kHz for using as a subcarrier */

	//PWM on PORTD6
	DDRD = (1 << PORTD6);

	TCCR0A = (1 << COM0A0); //Enable OCA0 for PWM, HIGH between bottom and OC0A value
	TCCR0A = (1 << WGM02) | (1<< WGM01) | (1 << WGM00); //Setup waveform mode for fast PWM, reset on OCRA value

	OCR0A = 127;
	TIMSK0 = (1 << TOIE0); //Interrupt on overflow

	sei(); //Set interrupts flag
	TCCR0B = (1 << CS00); //No prescaler, start timer

    while (1) {

    }
}

//Interrupt routine, called each cycle, left empty
ISR(TIMER0_OVF_vect){

}