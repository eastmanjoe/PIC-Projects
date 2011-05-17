//**********************************************************************************************
//								BASIC INFORMATION ABOUT THIS PROGRAM
//***********************************************************************************************
//File name:	main.c
//Data:			MM/DD/YYYY
//Version:		01.00
//Company:		
//Details: 		 
//				Language C: MPLAB C30 compiler
//				Fosc=11.0592MHz, Tcy=362ns
//Author:		Joe Eastman	
//*****************************************************************************************************************
//										HEADER FILES
//*****************************************************************************************************************
#include "p24Fxxxx.h"	//Include to allow selection of device

//*****************************************************************************************************************
//									CONFIGURATION BITS
//*****************************************************************************************************************
//#if defined (__PIC24FJ128GA010)
	_CONFIG1(JTAGEN_OFF & FWDTEN_OFF);
	//_CONFIG2();
//#endif

//*****************************************************************************************************************
//									DEFINES
//*****************************************************************************************************************
#define CLEAR 0
#define ENABLE 1
#define period 25000

//*****************************************************************************************************************
//									VARIABLES
//*****************************************************************************************************************
int dSec = 0;
int Sec = 0;
int Min = 0;
//*****************************************************************************************************************
//									Interrupt Service Routines
//*****************************************************************************************************************
void _ISR _T1Interrupt(void)
{
	dSec++;		//Increment tenths of a second counter
	if (dSec > 9)
	{
		dSec = 0;
		Sec++;		//Increment Seconds Counter
		
		if(Sec > 59)
		{
			Sec = 0;
			Min++;		//Increment Minute Counter
			
			if(Min > 59)
			{
				Min = 0;
			}//Hours
		}//Minutes
	}//Seconds
	
	_T1IF = CLEAR;		//Clear Timer1 Interrupt Flag
}//End of T1Interrupt

//*****************************************************************************************************************
//									MAIN
//*****************************************************************************************************************
void main(void)
{
	//Initialize
	_T1IP = 4;			//Set Timer1 Priority
	TMR1 = CLEAR;			//Clear Timer1
	PR1 = period - 1;	//Set period register [period * 64 * 1cycle (62.5ns) = timer1 interrupt]
	TRISA = 0xFF00;		//Set PORTA lsb as outputs
	
	//Init Timer 1
	T1CONbits.TON = 1;		//Start 16-bit timer
	T1CONbits.TSIDL = 0;	//Stop in Idle Mode
	T1CONbits.TGATE = 0;	//Gated Time Accumulation Enable
	T1CONbits.TCKPS1 = 1;	//Prescale Select Bit 1
	T1CONbits.TCKPS0 = 0;	//Prescale Select Bit 0
	T1CONbits.TSYNC = 0;	//External Clock Input Synchronization Select
	T1CONbits.TCS = 0;		//Clock Source Select
	
	_T1IF = CLEAR;		//Clear Interrupt Flag
	_T1IE = ENABLE;		//Enable Timer1 Interrupt Source
	
	_IPL = 0;		//Set processor priority level
	
	while(1)
	{
		PORTA = Sec;
	}// End of While Loop	
}//End of Main
