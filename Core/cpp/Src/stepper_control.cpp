/*
 * stepper_control.cpp
 *
 *  Created on: May 5, 2023
 *      Author: USER
 */

#include "stepper_control.h"
#include "accelStepper.h"

void StartSteppersTask(void *argument)
{
	AccelStepper motor1(GPIOC, GPIO_PIN_9, GPIOD, GPIO_PIN_15, GPIOA, GPIO_PIN_5);
	motor1.setMaxSpeed(1000.0);
	//motor1.setAcceleration(10);
	motor1.setSpeed(900.0);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	DWT_Init();
	for(;;)
	{
		motor1.runSpeed();

		//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		//delay_us(100);
		//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
		//delay_us(100);
	}
}



