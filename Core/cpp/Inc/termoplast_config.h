/*
 * term_config.h
 *
 *  Created on: May 10, 2023
 *      Author: USER
 */

#ifndef CPP_INC_TERMOPLAST_CONFIG_H_
#define CPP_INC_TERMOPLAST_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define DEBUG_MODE 0

#define WIFI_UART huart1
#define WIFI_UART_DMA hdma_usart1_rx
#define WIFI_UART_Ins USART1

#define FLASH_INIT 0x44

////////Control//////////
#define START_MSG0 0x84
#define START_MSG1 0x53
#define WIFI_CONTROL_ID 0x64

typedef struct {
	uint8_t current_status;
	uint8_t wifi_status;
	uint8_t current_move_comm;
	uint8_t cs_err;
	float temp1;
	float temp2;
	float temp3;
} GlobDataTypeDef;

typedef struct {
	uint8_t start_msg0;
	uint8_t start_msg1;
	uint8_t control_id;
	uint8_t msg_id;
	float temp1;
	float temp2;
	float temp3;
	uint16_t sensors;
	uint16_t errors;
	uint8_t status;
	uint8_t cs_errors;
	uint8_t reserv1;
	uint8_t CS;
} StatusMsgTypeDef;

enum WIFI_MSG_ID {
	WIFI_NONE = 0,
	WIFI_GET_STATUS = 1,
	WIFI_SET_MANUAL_COM,
	WIFI_RESERV1,
	WIFI_RESERV2,
	WIFI_RESERV3,
	WIFI_RESERV4,
	WIFI_MSG_MAX,
};

#ifdef __cplusplus
}
#endif

#endif /* CPP_INC_TERMOPLAST_CONFIG_H_ */
