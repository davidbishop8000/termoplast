/*
 * temp_read.cpp
 *
 *  Created on: May 10, 2023
 *      Author: USER
 */


#include <temp_sensor.h>
#include <termoplast_config.h>

extern SPI_HandleTypeDef hspi2;
extern GlobDataTypeDef globData;
ThermoCouple sensor_th1;
ThermoCouple sensor_th2;
ThermoCouple sensor_th3;

void StartTempSensorTask(void *argument)
{
	InitThermocouple();

	for(;;)
	{
		ReadThermoCouple(&sensor_th1);
		globData.temp1 = sensor_th1.Thx_celcius;
		osDelay(500);
		//ReadThermoCouple(&sensor_th2);
		//osDelay(50);
		//ReadThermoCouple(&sensor_th3);
		//osDelay(50);
	}
}

void InitThermocouple(void)
{
	sensor_th1.Thx_CS_Pin = Th1_CS_Pin;
	sensor_th1.Thx_CS_Port = Th1_CS_GPIO_Port;
	sensor_th1.hspi = &hspi2;

	sensor_th2.Thx_CS_Pin = Th2_CS_Pin;
	sensor_th2.Thx_CS_Port = Th2_CS_GPIO_Port;
	sensor_th2.hspi = &hspi2;

	sensor_th3.Thx_CS_Pin = Th3_CS_Pin;
	sensor_th3.Thx_CS_Port = Th3_CS_GPIO_Port;
	sensor_th3.hspi = &hspi2;
}
