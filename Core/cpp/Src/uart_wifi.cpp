/*
 * uart_wifi.cpp
 *
 *  Created on: May 10, 2023
 *      Author: USER
 */

#include <uart_wifi.h>
#include <string.h>
#include "termoplast_config.h"

#include <stdio.h> //for test

extern UART_HandleTypeDef WIFI_UART;
extern DMA_HandleTypeDef WIFI_UART_DMA;

extern GlobDataTypeDef globData;
uint8_t new_wifi_data = 0;
uint8_t wifi_uart_buff[100];
StatusMsgTypeDef statusMsg;

void StartUartWiFiTask(void *argument)
{
	for(;;)
	{
		static uint32_t release_button_tick = 0;
		static uint32_t cs_err = 0;

		if ((new_wifi_data && wifi_uart_buff[2] == WIFI_CONTROL_ID)
				&& wifi_uart_buff[0] == START_MSG0 && wifi_uart_buff[1] == START_MSG1) {
			enum WIFI_MSG_ID MSG_ID = (WIFI_MSG_ID)wifi_uart_buff[3];
			if (MSG_ID == WIFI_GET_STATUS) {
				if (wifi_uart_buff[RECEV_MSG_CS_BYTE_NUM]
						!= calculateCS(wifi_uart_buff, RECEV_MSG_CS_BYTE_NUM)) {
					cs_err++;
				}
				else {
					SendStatus();
				}
			}
			else if (MSG_ID == WIFI_SET_MANUAL_COM) {
				if (wifi_uart_buff[RECEV_MSG_CS_BYTE_NUM]
						!= calculateCS(wifi_uart_buff, RECEV_MSG_CS_BYTE_NUM)) {
					cs_err++;
				}
				else {
					release_button_tick = HAL_GetTick();
					SetManual();
				}
			}
			new_wifi_data = 0;
			memset(wifi_uart_buff, 0, 100);
		}
		/*if (globData.current_status == STATUS_MANUAL && (globData.current_move_comm != 0 || globData.current_lift_comm != 0)) {
			if (HAL_GetTick() - release_button_tick > 500) {
				globData.current_move_comm = MOVE_STOP;
			}
			if (HAL_GetTick() - release_button_tick > 5000) {
				globData.current_lift_comm = LIFT_STOP;
			}
		}*/

		osDelay(1000);
		SendStatus(); //for test
	}
}

void SendStatus()
{
	statusMsg.start_msg0 = START_MSG0;
	statusMsg.start_msg1 = START_MSG1;
	statusMsg.control_id = WIFI_CONTROL_ID;
	statusMsg.msg_id = WIFI_GET_STATUS;
	statusMsg.cs_errors = globData.cs_err;
	statusMsg.temp1 = globData.temp1;
	statusMsg.temp1 = globData.temp2;
	statusMsg.temp1 = globData.temp3;
	statusMsg.CS = calculateCS((uint8_t *)&statusMsg, sizeof(statusMsg)-1);

	//for test//////
	/*
	float Th1_temp =0;
	int intpart, fracpart;
	char txt1[11];

	Th1_temp = statusMsg.temp1;
	intpart = (int)Th1_temp;
	fracpart = (int)((Th1_temp - intpart) * 100);
	snprintf(txt1, 11, "%3d.%02d", intpart, fracpart);
	HAL_UART_Transmit(&WIFI_UART, (uint8_t*)&txt1, sizeof(txt1), 100);
	*/
	//////////////////////////


	HAL_UART_Transmit(&WIFI_UART, (uint8_t*)&statusMsg, sizeof(statusMsg), 100);
}

void SetManual()
{

}

uint8_t calculateCS(uint8_t *msg, int msg_size) {
  uint8_t cs = 0;
  for (int i=0; i<msg_size; i++)
  {
    cs+=msg[i];
  }
  return cs;
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	uint32_t er = HAL_UART_GetError(&huart1);
	switch (er) {
		case HAL_UART_ERROR_PE: // ошибка четности
			__HAL_UART_CLEAR_PEFLAG(&huart1);
			huart->ErrorCode = HAL_UART_ERROR_NONE;
			break;
		case HAL_UART_ERROR_NE:  // шум на линии
			__HAL_UART_CLEAR_NEFLAG(&huart1);
			huart->ErrorCode = HAL_UART_ERROR_NONE;
			break;
		case HAL_UART_ERROR_FE:  // ошибка фрейма
			__HAL_UART_CLEAR_FEFLAG(&huart1);
			huart->ErrorCode = HAL_UART_ERROR_NONE;
			break;
		case HAL_UART_ERROR_ORE:  // overrun error
			__HAL_UART_CLEAR_OREFLAG(huart);
			huart->ErrorCode = HAL_UART_ERROR_NONE;
			break;
		case HAL_UART_ERROR_DMA:  // ошибка DMA
			huart->ErrorCode = HAL_UART_ERROR_NONE;
			break;
		default:
			break;
	}
	if (huart->Instance == WIFI_UART_Ins) {
		new_wifi_data = 1;
		HAL_UARTEx_ReceiveToIdle_DMA(&WIFI_UART, wifi_uart_buff,
				sizeof(wifi_uart_buff));
		__HAL_DMA_DISABLE_IT(&WIFI_UART_DMA, DMA_IT_HT);
	}
}


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (huart->Instance == WIFI_UART_Ins) {
		new_wifi_data = 1;
		HAL_UARTEx_ReceiveToIdle_DMA(&WIFI_UART, wifi_uart_buff, sizeof(wifi_uart_buff));
		__HAL_DMA_DISABLE_IT(&WIFI_UART_DMA, DMA_IT_HT);
	}
}
