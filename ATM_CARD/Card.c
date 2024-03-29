/*************************************1*****************************************
 *
 * Module: ATM Card
 *
 * File Name: Card.c
 *
 * Description: Source file for the ATM Card
 *
 * Author: Youssef ElSayyad
 *
 *******************************************************************************/
#include "Card.h"
#include"lcd.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* Description : Function Receives IBAN from the PC terminal via UART */
void IBAN_Recieve(uint8 *IBAN) {
	for (uint8 charIndex = 0; charIndex < 5; charIndex++) {
		IBAN[charIndex] = USART_recieveByte();
	}
}
/* Description : Function sends the IBAN to ATM Machine ECU via SPI */
void IBAN_Send(uint8 *IBAN) {
	for (uint8 charIndex = 0; charIndex < 10; charIndex++) {
		SPI_sendReceiveByte(IBAN[charIndex]);
	}
}
int main() {
	/*Array to receive the IBAN from PC terminal*/
	uint8 IBAN[5];
	/*USART Structure Configuration
	 * Mode:ASYNCHRONZIED
	 * Parity:DISABLED
	 * STOP_BIT: ONEBIT
	 * BIT-DATA: 8BITS
	 * BAUD RATE:9600			*/
	USART_ConfigType Config_Ptr = { ASYNCH, DISABLED, ONEBIT, EIGHTBITS, 9600 };

	/*Initializing the USART*/
	USART_init(&Config_Ptr);
	/*Initializing the MCU as SPI Master*/
	SPI_initMaster();
	/*Receiving the IBAN from PC Terminal*/
/*	IBAN_Recieve(IBAN);
	/*Sending the IBAN to PC ATM Machine*/
	/*IBAN_Send(IBAN);*/
	while (1) {
		IBAN_Recieve(IBAN);
		/*Sending the IBAN to PC ATM Machine*/
		IBAN_Send(IBAN);
	}
}
