/*
 * stepper_control.h
 *
 *  Created on: May 5, 2023
 *      Author: USER
 */

#ifndef CPP_INC_STEPPER_CONTROL_H_
#define CPP_INC_STEPPER_CONTROL_H_

#include "main.h"
#include "cmsis_os2.h"
#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif
void StartSteppersTask(void *argument);
#ifdef __cplusplus
}
#endif

#endif /* CPP_INC_STEPPER_CONTROL_H_ */
