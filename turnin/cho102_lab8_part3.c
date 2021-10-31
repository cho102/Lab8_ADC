/*	Author:Cindy Ho
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}




int main(void) {
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0x03; PORTD = 0xFC;
	ADC_init();
	short MAX_VAL = 0;
	while (1) {
		short my_short = ADC;
		if (my_short > MAX_VAL) { 
			MAX_VAL = my_short; 
		}
		if (my_short >= MAX_VAL/2) { 
			PORTB = 0x01; 
		}
		else if (my_short < MAX_VAL/2) { 
			PORTB = 0x00; 
		}
    	}	
    	return 1;
}


