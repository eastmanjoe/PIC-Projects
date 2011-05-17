//
// A loop in the pattern
//
//Created: 09/05/2010
//Created By: Joe Eastman
//Example: Chapter 2 in "Programming 16-bit Microcontrollers in C"
//Fosc = 32 MHz

#include "p24Fxxxx.h"

//Equation to calculate delay value
//Tdelay = (2/Fosc)*256*DELAY
//DELAY = Tdelay/[(2/Fosc)*256]
#define DELAY 6250
int Counter = 0;

main()
{
	//Init the Control Registers
	TRISA = 0xFF00;		//PortA pin 0-7 ON
	//Init Timer
	T1CONbits.TON = 1;
	T1CONbits.TCS = 0;
	T1CONbits.TCKPS0 = 1;
	T1CONbits.TCKPS1 = 1;
	T1CONbits.TGATE = 0;
	T1CONbits.TSYNC = 0;
	T1CONbits.TSIDL = 0;
//	T1CON = 0x8030;
	
	PORTA = 0x00; //Turn Pin 0-7 OFF
	
	//Application: Main Loop
	while(1)
	{
		TMR1 = 0;
		while(TMR1 < DELAY)
		{
		}
		
		Counter++;
		PORTA = Counter; //Increment PORTA Counter
		TMR1 = 0;		
	}//Main Loop
}//End of Main
