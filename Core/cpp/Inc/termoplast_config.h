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
	unsigned char limit_sw1		:1;
	unsigned char limit_sw2		:1;
	unsigned char button1		:1;
	unsigned char button2		:1;
	unsigned char button3		:1;
	unsigned char button4		:1;
	unsigned char button5		:1;
	unsigned char button6		:1;
	unsigned char r0		:1;
	unsigned char r1		:1;
	unsigned char r2		:1;
	unsigned char r3		:1;
	unsigned char r4		:1;
	unsigned char r5		:1;
	unsigned char r6		:1;
	unsigned char r7		:1;
} SensorsTypeDef;

typedef struct {
	unsigned char err0  :1;
	unsigned char err1  :1;
	unsigned char err2  :1;
	unsigned char err3  :1;
	unsigned char err4  :1;
	unsigned char err5  :1;
	unsigned char err6  :1;
	unsigned char err7  :1;
	unsigned char err8  :1;
	unsigned char err9  :1;
	unsigned char err10 :1;
	unsigned char err11 :1;
	unsigned char err12 :1;
	unsigned char err13 :1;
	unsigned char err14 :1;
	unsigned char err15 :1;
} ErrorMsgTypeDef;

typedef struct {
	uint8_t current_status;
	uint8_t wifi_status;
	uint8_t current_move_comm;
	uint8_t cs_err;
	float temp1;
	float temp2;
	float temp3;
	SensorsTypeDef sens;
	ErrorMsgTypeDef error;
} GlobDataTypeDef;

typedef struct {
	uint8_t start_msg0;
	uint8_t start_msg1;
	uint8_t control_id;
	uint8_t msg_id;
	float temp1;
	float temp2;
	float temp3;
	SensorsTypeDef sens;
	ErrorMsgTypeDef error;
	uint32_t cycles_count;
	uint32_t cycles_set;
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
