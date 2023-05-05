/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "outputs.h"
#include "inputs.h"
#include "stepper_control.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
uint32_t defaultTaskBuffer[ 128 ];
osStaticThreadDef_t defaultTaskControlBlock;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .cb_mem = &defaultTaskControlBlock,
  .cb_size = sizeof(defaultTaskControlBlock),
  .stack_mem = &defaultTaskBuffer[0],
  .stack_size = sizeof(defaultTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for OutputsTask */
osThreadId_t OutputsTaskHandle;
uint32_t OutputsTaskBuffer[ 128 ];
osStaticThreadDef_t OutputsTaskControlBlock;
const osThreadAttr_t OutputsTask_attributes = {
  .name = "OutputsTask",
  .cb_mem = &OutputsTaskControlBlock,
  .cb_size = sizeof(OutputsTaskControlBlock),
  .stack_mem = &OutputsTaskBuffer[0],
  .stack_size = sizeof(OutputsTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for InputsTask */
osThreadId_t InputsTaskHandle;
uint32_t InputsTaskBuffer[ 128 ];
osStaticThreadDef_t InputsTaskControlBlock;
const osThreadAttr_t InputsTask_attributes = {
  .name = "InputsTask",
  .cb_mem = &InputsTaskControlBlock,
  .cb_size = sizeof(InputsTaskControlBlock),
  .stack_mem = &InputsTaskBuffer[0],
  .stack_size = sizeof(InputsTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for SteppersTast */
osThreadId_t SteppersTastHandle;
uint32_t SteppersTastBuffer[ 128 ];
osStaticThreadDef_t SteppersTastControlBlock;
const osThreadAttr_t SteppersTast_attributes = {
  .name = "SteppersTast",
  .cb_mem = &SteppersTastControlBlock,
  .cb_size = sizeof(SteppersTastControlBlock),
  .stack_mem = &SteppersTastBuffer[0],
  .stack_size = sizeof(SteppersTastBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void StartOutputsTask(void *argument);
extern void StartInputsTask(void *argument);
extern void StartSteppersTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of OutputsTask */
  OutputsTaskHandle = osThreadNew(StartOutputsTask, NULL, &OutputsTask_attributes);

  /* creation of InputsTask */
  InputsTaskHandle = osThreadNew(StartInputsTask, NULL, &InputsTask_attributes);

  /* creation of SteppersTast */
  SteppersTastHandle = osThreadNew(StartSteppersTask, NULL, &SteppersTast_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

