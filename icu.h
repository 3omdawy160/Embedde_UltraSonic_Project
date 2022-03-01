 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: header file for the icu driver
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_clock;


typedef enum{
	FALLING,RISING
}ICU_edgeType;

typedef struct{
	ICU_clock CLOCK;
	ICU_edgeType EDGE;
}ICU_configType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ICU_init(const ICU_configType *config_ptr);

void ICU_setCallBackFunction(void(*a_ptr)(void));

void ICU_setEdgeType(ICU_edgeType EDGE);

uint16 ICU_getInputCaptureValue();

void ICU_clearTimerValue();

void ICU_deInit();


#endif /* ICU_H_ */
