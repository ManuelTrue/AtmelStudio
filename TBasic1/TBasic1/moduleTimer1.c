/*
 * moduleTimer1.c
 *
 * Created: 2019-07-08 09:47:19 a.m.
 *  Author: BladimirBaccaCortes
 */ 
#include <avr/io.h>
#include "moduleTimer1.h"

// Timer1 Configuration
void configTimer1()
{
	// Timer/Counter 1 initialization
	TCCR1B |= (1 << CS10);
	TCNT1 = 0;
	TIFR = 0x00;
}
