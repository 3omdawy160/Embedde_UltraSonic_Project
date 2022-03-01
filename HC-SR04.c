/******************************************************************************
 *
 * Module: HC-SR04
 *
 * File Name: HC-SR04.c
 *
 * Description: source file for the HC-SR04 driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#include "icu.h"
#include "gpio.h"
#include "common_macros.h"
#include "HC-SR04.h"
#include <util/delay.h>


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
uint8 g_counter = 0;
uint16 g_Time = 0;


/*******************************************************************************
                       Functions Definitions
 *******************************************************************************/

void Ultrasonic_init()
{
	/*Setting the configure struct for the ICU*/
	ICU_configType config = {F_CPU_8,RISING};

	ICU_init(&config);

	/*Setting the call back function*/
	ICU_setCallBackFunction(Ultrasonic_edgeProcessing);

	/*Making the Trigger pin an output pin*/
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,PIN_OUTPUT);
}

void Ultrasonic_Trigger()
{
	/* Transmit trigger pulse of at least 10 us to the Trigger Pin */
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOGIC_HIGH);
	/*Waiting for the 8 sound waves made by the ultrasonic*/
	_delay_us(15);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance()
{
	uint16 distance = 0;

	/*Starting the ultrasonic*/
	Ultrasonic_Trigger();

	/* Wait until the time is calculated */
	while(g_counter < 2);

	/* Clear the edge counter to start the measurement again */
	g_counter = 0;

	/*Calculating the measured distance by the ultrasonic in cm*/
	distance = g_Time / 58.8 ;


	return distance;
}

void Ultrasonic_edgeProcessing()
{
	g_counter++;
	if(g_counter == 1)
	{
		/*Clearing the timer to start counting from 0*/
		ICU_clearTimerValue();

		/* Start detecting the falling edge */
		ICU_setEdgeType(FALLING);
	}
	else if(g_counter == 2)
	{
		/*Inserting the timer count in a global variable to measure the distance*/
		g_Time = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		/* Detect rising edge */
		ICU_setEdgeType(RISING);
	}
}
