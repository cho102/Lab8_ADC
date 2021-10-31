/*	Author:Cindy Ho
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: 
 *	Shining a light on the photoresistor, I got the value (MAX): 0x3F
 *	Convering the photoresistor with my hand, I got the value (MIN): 0x127
 *
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif




void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | ( 1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	ADC_init();
    while (1) {
	unsigned short my_short = ADC;
	unsigned char my_char = (char)my_short;
	unsigned char my_char1 = (char)(my_char >> 8);
	PORTB = my_char;
	PORTD = my_char1 & 0x03;

    }
    return 1;
}
