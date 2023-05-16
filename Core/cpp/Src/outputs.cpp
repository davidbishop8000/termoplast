/*
 * outputs.cpp
 *
 *  Created on: May 5, 2023
 *      Author: USER
 */


#include <outputs.h>
#include "termoplast_config.h"


extern IWDG_HandleTypeDef hiwdg;
extern GlobDataTypeDef globData;
extern TermoplastConfigTypeDef termoplastConfig;

//extern IWDG_HandleTypeDef hiwdg;


void StartOutputsTask(void *argument)
{
	for(;;)
	{
		HAL_IWDG_Refresh(&hiwdg);
		SetOutputs();
		if (globData.LEDB) LedBlink();
		osDelay(1);
	}
}

void SetOutputs()
{
	((globData.temp1 > MAX_TEMP) || (globData.temp1 > termoplastConfig.temp1)) ? Y00_OFF : Y00_ON;
	((globData.temp2 > MAX_TEMP) || (globData.temp2 > termoplastConfig.temp2)) ? Y01_OFF : Y01_ON;
	((globData.temp3 > MAX_TEMP) || (globData.temp3 > termoplastConfig.temp3)) ? Y02_OFF : Y02_ON;
}

void LedBlink() {
	static const uint32_t ledb_time[] = {
			0,
			20,  //LEDB_POWER_ON
			200, //LEDB_START
			100, //LEDB_COMPLETED
			10,  //LEDB_FLASH_OK
			200   //LEDB_ERROR
	};
	static const uint32_t ledb_rep[] = {
			0,
			1, //LEDB_POWER_ON
			1, //LEDB_START
			1, //LEDB_COMPLETED
			3,  //LEDB_FLASH_OK
			3   //LEDB_ERROR
	};

	static int32_t ledb_active_time = 0;
	static int32_t ledb_repeats = 0;
	ledb_repeats = ledb_rep[globData.LEDB];
	ledb_active_time = ledb_time[globData.LEDB];
	for (int i = 0; i < ledb_repeats; i++)
	{
		osDelay(ledb_active_time);
		Y05_ON;
		osDelay(ledb_active_time);
		Y05_OFF;
	}
	globData.LEDB = 0;
}
