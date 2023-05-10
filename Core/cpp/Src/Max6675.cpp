
#include "Max6675.h"

static uint8_t SPI_RxByte(SPI_HandleTypeDef *hspi)
{
  uint8_t dummy, data;
  dummy = 0xFF;
  data = 0;

  while ((HAL_SPI_GetState(hspi) != HAL_SPI_STATE_READY));
  HAL_SPI_TransmitReceive(hspi, &dummy, &data, 1, SPI_TIMEOUT);

  return data;
}

void ReadThermoCouple(ThermoCouple *Th)
{
	unsigned short data;

	HAL_GPIO_WritePin(Th->Thx_CS_Port, Th->Thx_CS_Pin, GPIO_PIN_RESET);

	data = SPI_RxByte(Th->hspi);
	data <<= 8;
	data |= SPI_RxByte(Th->hspi);

	HAL_GPIO_WritePin(Th->Thx_CS_Port, Th->Thx_CS_Pin, GPIO_PIN_SET);

	Th->Thx_rawdata = data;

	if (data & 4) Th->connected = 0;
	else Th->connected = 1;

	data  >>= 3;
	Th->Thx_celcius = data * 0.25;
}




