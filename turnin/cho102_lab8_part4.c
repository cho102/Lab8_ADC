/*	Author:Cindy Ho
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link:
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
	ADC_init();
	short MAX_VAL = 0;
	while (1) {
		short my_short = ADC;
		if (my_short > MAX_VAL) { 
			MAX_VAL = my_short; 
		}
		if (my_short < (MAX_VAL/8)*1) { 
			PORTB = 0xFF; 
		}
		else if (my_short < (MAX_VAL/8)*2) { 
			PORTB = 0x7F; 
		}
		else if (my_short < (MAX_VAL/8)*3) { 
			PORTB = 0x3F; 
		}
		else if (my_short < (MAX_VAL/8)*4) { 
			PORTB = 0x1F; 
		}
		else if (my_short < (MAX_VAL/8)*5) { 
			PORTB = 0x0F; 
		}
		else if (my_short < (MAX_VAL/8)*6) { 
			PORTB = 0x07; 
		}
		else if (my_short < (MAX_VAL/8)*7) { 
			PORTB = 0x03; 
		}
		else if (my_short < (MAX_VAL/8)*8) { 
			PORTB = 0x01; 
		}
    	}	
    	return 1;
}


