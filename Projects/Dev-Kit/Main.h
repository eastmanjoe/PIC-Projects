//**********************************************************************************************
//								BASIC INFORMATION ABOUT THIS PROGRAM
//***********************************************************************************************
//File name:	main.c
//Data:			04/02/2010
//Version:		01.00
//Company:		
//Details: 		Blink LED on Explorer 18 Development Board 
//				Language C: MCC18 compiler
//				Fosc=11.0592MHz, Tcy=362ns
//Author:		Joe Eastman	
//*****************************************************************************************************************
//										HEADER FILES
//*****************************************************************************************************************
//#include "p18cxxx.h"	//Include to allow selection of device
//#include "main.h"
//#include "i2c.h"
//#include "delays.h"
//#include "usart.h"
//#include "stdlib.h"

//********************************************************************
//						Configuration Bits
//********************************************************************
#if defined (_18F87J11)
	#pragma config WDTEN=OFF
	#pragma config STVREN=OFF
	#pragma config XINST=OFF
	#pragma config CP0=OFF
	#pragma config FOSC=HSPLL
	#pragma config FCMEN=OFF
	#pragma config IESO=OFF
	#pragma config MSSPMSK=MSK7
	#pragma config DEBUG=ON
#endif

//*********************************************************************
//		   				Prototypes
//*********************************************************************
void PICInit(void);
//void LCDInit(void);
