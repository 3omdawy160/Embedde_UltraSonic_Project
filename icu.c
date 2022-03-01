/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.c
 *
 * Description: source file for the icu driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/


#include "icu.h"
#include "common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

static volatile void (*callBack_ptr)(void) = NULL_PTR;

void ICU_init(const ICU_configType *config_ptr)
{
	CLEAR_BIT(DDRD,PD6);
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);//Normal mode and non PWM
	TCCR1B =  (TCCR1B & ~(1<<ICES1)) | ((config_ptr->EDGE)<<ICES1);//Inserting the edge
	TCCR1B = (TCCR1B & 0xF8) | (config_ptr->CLOCK);//Inserting the clock
	TCNT1 = 0;//Initial Value for Timer1
	ICR1 = 0;// Initial Value for the input capture register
	SET_BIT(TIMSK,TICIE1);//Enabling the interrupt
}

ISR(TIMER1_CAPT_vect)
{
	if(callBack_ptr != NULL_PTR)//To make sure that nothing went wrong
	{
		callBack_ptr();//Calling the Call Back function in the application after the edge is detected
	}
}

void ICU_setCallBackFunction(void(*a_ptr)(void))
{
	callBack_ptr = a_ptr;//Saving the address of the Call back function in a global variable
}

void ICU_setEdgeType(ICU_edgeType EDGE)
{
	TCCR1B =  (TCCR1B & ~(1<<ICES1)) | (EDGE<<ICES1);//Inserting the edge
}

uint16 ICU_getInputCaptureValue()
{
	return ICR1;
}

void ICU_clearTimerValue()
{
	TCNT1 = 0;
}

void ICU_deInit()
{
	// Clear All Timer1 Registers
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	TIMSK &= ~(1<<TICIE1);//Disable the Input Capture interrupt
}
