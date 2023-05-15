/*
 * outputs.cpp
 *
 *  Created on: May 5, 2023
 *      Author: USER
 */


#include <outputs.h>
#include "termoplast_config.h"

extern GlobDataTypeDef globData;

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
	(globData.temp1 > 30.0) ? Y00_OFF : Y00_ON;
	(globData.temp2 > 30.0) ? Y01_OFF : Y01_ON;
	(globData.temp3 > 30.0) ? Y02_OFF : Y02_ON;
}
