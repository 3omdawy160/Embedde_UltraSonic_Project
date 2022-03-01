/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: UltraSonic Project
 *
 * Author: Mohamed Emad El-Dien
 *
 *******************************************************************************/

#include "HC-SR04.h"
#include "lcd.h"
#include <avr/io.h>


int main()
{
	/*Declaring the distance variable and enabling the global interrupt flag*/
	uint16 distance = 0;
	SREG |= (1<<7);

	/*Initializing the LCD and the UltraSonic*/
	LCD_init();
	Ultrasonic_init();

	/*Displaying a string and moving the cursor to display the measured data*/
	LCD_displayString("Distance =    cm");

	for(;;)
	{
		/*Continuously measuring the distance*/
		distance =  Ultrasonic_readDistance() + 2;
		LCD_moveCursor(0,11);

		if(distance >= 100)
		{
			LCD_integerToString(distance);
		}
		else
		{
			LCD_integerToString(distance);
			/* In case the value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}
