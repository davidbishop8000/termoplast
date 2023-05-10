#ifndef INC_MAX6675_H_
#define INC_MAX6675_H_

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define SPI_TIMEOUT 1000

typedef struct {
	SPI_HandleTypeDef *hspi;
	GPIO_TypeDef* Thx_CS_Port;
	uint16_t Thx_CS_Pin;
	uint16_t Thx_rawdata;
	float Thx_celcius;
	uint8_t connected;
} ThermoCouple;

void ReadThermoCouple(ThermoCouple *Th);

#ifdef __cplusplus
}
#endif

#endif /* INC_MAX6675_H_ */
