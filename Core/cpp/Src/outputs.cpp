/*
 * outputs.cpp
 *
 *  Created on: May 5, 2023
 *      Author: USER
 */


#include <outputs.h>

//extern IWDG_HandleTypeDef hiwdg;


void StartOutputsTask(void *argument)
{
	for(;;)
	{
		SetOutputs();
		osDelay(1);
	}
}

void SetOutputs()
{
	//HAL_IWDG_Refresh(&hiwdg);
	Y00_ON;
	HAL_Delay(100);
	Y00_OFF;
	HAL_Delay(100);
}
