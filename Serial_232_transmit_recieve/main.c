/*
 * Serial_232_transmit_recieve.c
 *
 * Created: 26/05/2020 11:39:18
 * Author : bee
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART_M328P.h"
uint8_t buffer;
volatile uint8_t StrRX_flag = 0;

ISR(USART_RX_vect){
	buffer= UDR0;
	StrRX_flag = 1;
}

int main(void)
{
    DDRB = 0b11111100;
	USART0Init();
	sei();
	USART_putstring("A");
	PORTB |= (1<<PORTB4);
    while (1) 
    {	
		if (StrRX_flag ==1){
			
			//turn off light
			if (buffer==89){ 
				PORTB |= (1<<PORTB4);//red
				
				
			}
			//turn off light
			else if (buffer==88){
				PORTB &=~ (1<<PORTB4);
			}
			StrRX_flag =0;
		}
	
	}//end while
}//end main

