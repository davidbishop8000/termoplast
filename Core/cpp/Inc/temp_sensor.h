/*
 * temp_read.h
 *
 *  Created on: May 10, 2023
 *      Author: USER
 */

#ifndef CPP_INC_TEMP_SENSOR_H_
#define CPP_INC_TEMP_SENSOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"
#include "cmsis_os2.h"
#include "Max6675.h"

#define Th1_CS_Pin GPIO_PIN_10
#define Th1_CS_GPIO_Port GPIOB

#define Th2_CS_Pin GPIO_PIN_11
#define Th2_CS_GPIO_Port GPIOB

#define Th3_CS_Pin GPIO_PIN_12
#define Th3_CS_GPIO_Port GPIOB

void StartTempSensorTask(void *argument);
void InitThermocouple(void);

#ifdef __cplusplus
}
#endif

#endif /* CPP_INC_TEMP_SENSOR_H_ */
