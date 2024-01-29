/*************************************1*****************************************
 *
 * Module: ATM Machine
 *
 * File Name: ATM.c
 *
 * Description: Source file for the ATM Machine
 *
 * Author: Youssef ElSayyad
 *
 *******************************************************************************/
#include"ATM.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* Description : Function Receives IBAN from the Card ECU via SPI */
void IBAN_Recieve(uint8 *IBAN) {
	for (uint8 charIndex = 0; charIndex < 10; charIndex++) {
		IBAN[charIndex] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}
}
int main() {
	uint8 IBAN[5] = "abcde";
	LCD_init();
	SPI_initSlave();
	LCD_displayString(IBAN);
	LCD_moveCursor(1, 0);
	IBAN_Recieve(IBAN);
	while (1) {
		LCD_displayString(IBAN);
		LCD_clearScreen();
	}
}
