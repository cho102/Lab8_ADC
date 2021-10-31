/*	Author:Cindy Ho
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://drive.google.com/file/d/1C2WXWfHPXGxEuLrxdcYjPIdgOP44UpC-/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}




int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0x03; PORTD = 0xFC;
	ADC_init();
	short MAX_VAL = 0xBB;
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


