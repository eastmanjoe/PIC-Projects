//**********************************************************************************************
//								BASIC INFORMATION ABOUT THIS PROGRAM
//***********************************************************************************************
//File name:	main.c
//Data:			05/27/2010
//Version:		01.00
//Company:		
//Details: 		Execise Functions on Explorer 18 Development Board 
//				Language C: MCC18 compiler
//				Fosc=11.0592MHz, Tcy=362ns
//Author:		Joe Eastman	
////*****************************************************************************************************************
////										HEADER FILES
////*****************************************************************************************************************
#include "p18cxxx.h"	//Include to allow selection of device
#include "main.h"
#include "i2c.h"
#include "delays.h"
#include "usart.h"
#include "stdlib.h"
#include "pwm.h"
#include "timers.h"
//*********************************************************************
//		   				GLOBAL VARIABLES	
//*********************************************************************

//********************************************************************
//						Main Program
//********************************************************************
void main (void)
{
	PICInit();
//	LCDInit();
	OpenTimer2(TIMER_INT_OFF);
	OpenPWM1(0x70);

while(1)
{
	if(PORTBbits.RB0)
	{
		if (PORTDbits.RD1)
		{
			PORTDbits.RD1 = 0;
			PORTDbits.RD2 = 0;
		}	
		else
		{
			PORTDbits.RD1 = 1;
			PORTDbits.RD2 = 0;
		}
//		Delay10KTCYx(100);
	}
	else
	{
		if (PORTDbits.RD2)
		{
			PORTDbits.RD2 = 0;
			PORTDbits.RD1 = 0;
		}	
		else
		{
			PORTDbits.RD2 = 1;
			PORTDbits.RD1 = 0;
		}
//		Delay10KTCYx(100);
	}
	Delay10KTCYx(100);
}
}//End of Main

void PICInit(void)
{
//********************** Initialize I/O *******************
	OSCTUNEbits.PLLEN = 1;					//Turn on Phase Locked Loop for HSPLL Oscillation Mode
	TRISDbits.TRISD1 = 0;					//Set Port D bit 1 as output
	TRISDbits.TRISD2 = 0;					//Set Port D bit 2 as output
	PORTDbits.RD1 = 0;						//Turn on Status LED
	PORTDbits.RD2 = 0;						//Turn on Status LED
//	TRISBbits.TRISB0 = 1;					//Set Port B bit 0 as input

//********************** Initialize UART *******************
	// BAUD_RATE_GEN
	#define BAUD_RATE_GEN 51					//19200 Baud
//-------------------------configure USART ----------------------
    // API configures USART for desired parameters:
    //  - TX/RX interrupts turned OFF
    //  - Asynchronous mode
    //  - 8 bits
    //  - Continuous Receive Enabled
    //  - High speed baud rate generator mode
    //	- 16-bit baud generation rate
    //	- Clock idle state is LOW
    Open1USART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT 
    						& USART_CONT_RX & USART_BRGH_HIGH, BAUD_RATE_GEN);
    baud1USART(BAUD_IDLE_CLK_LOW & BAUD_16_BIT_RATE & BAUD_WAKEUP_OFF & BAUD_AUTO_OFF);

//********************** Initialize PWM *******************
	
}

//void LCDInit (void)
//{
//
//	CloseSPI1();
//	OpenSPI1(SPI_FOSC__16, MODE_00, SMPEND);
//}
