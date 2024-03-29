/*************************************1*****************************************
 *
 * Module: Card
 *
 * File Name: Card.h
 *
 * Description: Header file for the ATM Card
 *
 * Author: Youssef ElSayyad
 *
 *******************************************************************************/
#ifndef CARD_H_
#define CARD_H_

#include "spi.h"
#include "usart.h"
#include "std_types.h"
#include "common_macros.h"
/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define SEND_IBAN 0x99

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for recieving the Card IBAN from the PC terminal.
 */
void IBAN_Recieve(uint8 *Str);

/*
 * Description :
 * The Function responsible for sending the Card IBAN to the ATM Machine.
 */
void IBAN_Send(uint8 *Str);

#endif /* CARD_H_ */
