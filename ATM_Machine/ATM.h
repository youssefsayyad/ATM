/*************************************1*****************************************
 *
 * Module: ATM Machine
 *
 * File Name: ATM.h
 *
 * Description: Header file for the ATM Machine
 *
 * Author: Youssef ElSayyad
 *
 *******************************************************************************/

#ifndef ATM_H_
#define ATM_H_
#include "twi.h"
#include "spi.h"
#include "lcd.h"
#include "std_types.h"
#include "common_macros.h"
#include "external_eeprom.h"
#include "keypad.h"
#include "dc_motor.h"
#include <util/delay.h>
/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define IBAN_Recieve_INDEX 0x00
#define SaveIBAN_INDEX 0x01
#define User_Data_INDEX 0x02
#define Withdraw_Option_INDEX 0x03
#define Deposit_Option_INDEX 0x04
#define Request_Pin_INDEX 0x05
#define Save_Pin_INDEX 0x06
#define Check_Pin_INDEX 0x07
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/* Description : Function Receives IBAN from the Card ECU via SPI and in UserData Struct */
void IBAN_Recieve(void);
/* Description : Function displays the system features for the user*/
void User_Data(void);
/* Description : Function Saves IBAN in EEPROM */
void SaveIBAN(void);
/* Description : Function displays the system feature "Deposit" for the user and process
 * the desired amount  */
void DepositOption(void);
/* Description : Function displays the system feature "WithDraw" for the user and process
 * the desired amount  */
void WithdrawOption(void);
/* Description : Function Receives Card Pin from the user via keypad */
void RequestPin(void);
/* Description : Function Saves Card Pin in EEPROM */
void SavePin(void);
/* Description : Function to check between the received Card Pin and saved pin in EEPROM */
void CheckPin(void);
#endif /* ATM_H_ */
