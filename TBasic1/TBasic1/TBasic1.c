/*
 * TBasic1.c
 *
 * Created: 01/10/2013 20:31:38
 *  Author: eBlady
 */ 


#include <avr/io.h>
#include "lcd.h"

int main(void)
{
	unsigned char lsbValue;
	unsigned char msbValue;
	unsigned char lcdMsg[16];
	
	// Config timer
	configTimer1();
	
	// Port initialization as inputs.
	PORTA=0x00;		// TCNT1L
	DDRA=0x01;
	
	PORTB=0x00;		// TCNT1H
	DDRB=0x00;
		
	PORTD=0xff;
	DDRD=0xff;
	
	PORTD = PINB;
	
	//Inits
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();
	lcd_home();
	
    while(1)
    {
        //TODO:: Please write your application code 
		lsbValue = PINA;
		msbValue = PINB;
		
		if (TIFR & (1 << TOV1))
		{
			TIFR |= (1 << TOV1);
			
			TCNT1L = lsbValue;
			TCNT1H = msbValue;
			
			PORTA ^= 0x01;
		}
		
		// LCD
		lcd_clrscr();
		lcd_home();
		sprintf(lcdMsg, "T1: %x %x", msbValue, lsbValue);
		lcd_puts(lcdMsg);
    }
}