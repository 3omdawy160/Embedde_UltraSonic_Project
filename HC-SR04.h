/******************************************************************************
 *
 * Module: HC-SR04
 *
 * File Name: HC-SR04.h
 *
 * Description: header file for the HC-SR04 driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#ifndef HC_SR04_H_
#define HC_SR04_H_

#include "std_types.h"


/*******************************************************************************
                                 Some Definitions
 *******************************************************************************/
#define ULTRASONIC_TRIGGER_PORT PORTB_ID
#define ULTRASONIC_ECHO_PIN PIN6_ID
#define ULTRASONIC_TRIGGER_PIN PIN5_ID


/*******************************************************************************
                       Functions Prototypes
 *******************************************************************************/
void Ultrasonic_init();
void Ultrasonic_Trigger();
uint16 Ultrasonic_readDistance();
void Ultrasonic_edgeProcessing();


#endif /* HC_SR04_H_ */
