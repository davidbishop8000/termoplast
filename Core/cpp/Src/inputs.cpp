/*
 * inputs.cpp
 *
 *  Created on: May 5, 2023
 *      Author: USER
 */

#include <inputs.h>
#include "termoplast_config.h"
extern GlobDataTypeDef globData;

void StartInputsTask(void *argument)
{
	for(;;)
	{
		osDelay(1);
	}
}

void InputsRead() {
	IN_X02 ? (globData.sens.limit_sw1 = 0) : (globData.sens.limit_sw1 = 1);
	IN_X03 ? (globData.sens.limit_sw2 = 0) : (globData.sens.limit_sw2 = 1);
	IN_X04 ? (globData.sens.button1 = 0) : (globData.sens.button1 = 1);
	IN_X05 ? (globData.sens.button2 = 0) : (globData.sens.button2 = 1);
	IN_X06 ? (globData.sens.button3 = 0) : (globData.sens.button3 = 1);
	IN_X07 ? (globData.sens.button4 = 0) : (globData.sens.button4 = 1);
	IN_X08 ? (globData.sens.button5 = 0) : (globData.sens.button5 = 1);
	IN_X09 ? (globData.sens.button6 = 0) : (globData.sens.button6 = 1);
}
