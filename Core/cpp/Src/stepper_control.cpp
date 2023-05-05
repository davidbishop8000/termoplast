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
	//AccelStepper motor1(GPIOC, GPIO_PIN_9, GPIOD, GPIO_PIN_15, GPIOC, GPIO_PIN_6);
	AccelStepper motor1(GPIOC, GPIO_PIN_9, GPIOD, GPIO_PIN_15, GPIOC, GPIO_PIN_6);
	motor1.setMinPulseWidth(6);
	motor1.setMaxSpeed(1000.0);
	motor1.setAcceleration(500);
	motor1.setSpeed(1000.0);
	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	DWT_Init();
	unsigned long  en_timer = 0;
	int x = 0;
	motor1.moveTo(-1600);
	for(;;)
	{
		motor1.run();
		if((HAL_GetTick() - en_timer) > 10000) // интервал 1000мс = 1сек
		{
		   en_timer = HAL_GetTick();
		   x+=2400;
		   motor1.moveTo(x);
		   //HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_6);
		   //motor1.setSpeed(-2000.0);
		   //osDelay(10);
		   //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		}

		//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		//delay_us(100);
		//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
		//delay_us(100);
	}
}



