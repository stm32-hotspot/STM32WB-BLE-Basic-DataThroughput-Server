/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_app.c
  * @author  MCD Application Team
  * @brief   Custom Example Application (Server)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "main.h"
#include "app_common.h"
#include "dbg_trace.h"
#include "ble.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  /* My_P2P_Server */
  uint8_t               Srvtoclient_Notification_Status;
  /* USER CODE BEGIN CUSTOM_APP_Context_t */

  /* USER CODE END CUSTOM_APP_Context_t */

  uint16_t              ConnectionHandle;
} Custom_App_Context_t;

/* USER CODE BEGIN PTD */
//[JT]
uint16_t *packet_idx;
extern uint8_t TimerMeasurement_Id;   
extern TP_Flow_Status_t TpFlowStatus;  

/* USER CODE END PTD */

/* Private defines ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macros -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/**
 * START of Section BLE_APP_CONTEXT
 */

PLACE_IN_SECTION("BLE_APP_CONTEXT") static Custom_App_Context_t Custom_App_Context;

/**
 * END of Section BLE_APP_CONTEXT
 */

/* USER CODE BEGIN PV */
uint8_t UpdateCharData[247];
uint8_t NotifyCharData[247];

uint8_t SecureReadData;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
  /* My_P2P_Server */
static void Custom_Srvtoclient_Update_Char(void);
static void Custom_Srvtoclient_Send_Notification(void);

/* USER CODE BEGIN PFP */
static void P2PS_Send_Notification(void);   //[JT]
static void Button2_Trigger_Received(void); //[JT]
/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_1 */

  /* USER CODE END CUSTOM_STM_App_Notification_1 */
  switch(pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* USER CODE END CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

  /* My_P2P_Server */
    case CUSTOM_STM_TEST_START_READ_EVT:
      /* USER CODE BEGIN CUSTOM_STM_TEST_START_READ_EVT */

      /* USER CODE END CUSTOM_STM_TEST_START_READ_EVT */
      break;

    case CUSTOM_STM_TEST_START_WRITE_NO_RESP_EVT:
      /* USER CODE BEGIN CUSTOM_STM_TEST_START_WRITE_NO_RESP_EVT */
      //[JT]
      APP_DBG_MSG("\r\n\r** CUSTOM_STM_TEST_START_WRITE_NO_RESP_EVT \n");
      APP_DBG_MSG("\r\n\r** Write Data: 0x%02X \n", pNotification->DataTransfered.pPayload[0]);
      if (pNotification->DataTransfered.pPayload[0] == 0)
      {
        /* Stop Notifications */
        // To Do
      }
      else if (pNotification->DataTransfered.pPayload[0] == 1)
      {
        /* Start Notifications */        
        // To Do         
      }
      
      /* USER CODE END CUSTOM_STM_TEST_START_WRITE_NO_RESP_EVT */
      break;

    case CUSTOM_STM_SRVTOCLIENT_WRITE_NO_RESP_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SRVTOCLIENT_WRITE_NO_RESP_EVT */

      /* USER CODE END CUSTOM_STM_SRVTOCLIENT_WRITE_NO_RESP_EVT */
      break;

    case CUSTOM_STM_SRVTOCLIENT_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SRVTOCLIENT_NOTIFY_ENABLED_EVT */
      //[JT] - Notifications enabled
      APP_DBG_MSG("\r\n\r** CUSTOM_STM_BUTTON_C_NOTIFY_ENABLED_EVT \n");
      Custom_App_Context.Srvtoclient_Notification_Status = 1;        /* My_Switch_Char notification status has been enabled */

      /* USER CODE END CUSTOM_STM_SRVTOCLIENT_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_SRVTOCLIENT_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_SRVTOCLIENT_NOTIFY_DISABLED_EVT */
        //[JT] - Notifications disabled
      APP_DBG_MSG("\r\n\r** CUSTOM_STM_BUTTON_C_NOTIFY_DISABLED_EVT \n");
      Custom_App_Context.Srvtoclient_Notification_Status = 0;        /* My_Switch_Char notification status has been disabled */
      HAL_GPIO_WritePin(BLUE_LED1_GPIO_Port, BLUE_LED1_Pin, GPIO_PIN_RESET);        
      /* USER CODE END CUSTOM_STM_SRVTOCLIENT_NOTIFY_DISABLED_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_STM_App_Notification_default */

      /* USER CODE END CUSTOM_STM_App_Notification_default */
      break;
  }
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_2 */

  /* USER CODE END CUSTOM_STM_App_Notification_2 */
  return;
}

void Custom_APP_Notification(Custom_App_ConnHandle_Not_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_APP_Notification_1 */

  /* USER CODE END CUSTOM_APP_Notification_1 */

  switch(pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_APP_Notification_Custom_Evt_Opcode */

    /* USER CODE END P2PS_CUSTOM_Notification_Custom_Evt_Opcode */
    case CUSTOM_CONN_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_CONN_HANDLE_EVT */

      /* USER CODE END CUSTOM_CONN_HANDLE_EVT */
      break;

    case CUSTOM_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_DISCON_HANDLE_EVT */

      /* USER CODE END CUSTOM_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_APP_Notification_default */

      /* USER CODE END CUSTOM_APP_Notification_default */
      break;
  }

  /* USER CODE BEGIN CUSTOM_APP_Notification_2 */

  /* USER CODE END CUSTOM_APP_Notification_2 */

  return;
}

void Custom_APP_Init(void)
{
  /* USER CODE BEGIN CUSTOM_APP_Init */
  uint32_t i;
  
  //[JT] 
  /* Register Tasks for Notifications and user buttons */
  UTIL_SEQ_RegTask( 1<< CFG_TASK_START_NOTIFICATIONS_ID, UTIL_SEQ_RFU, P2PS_Send_Notification );
  UTIL_SEQ_RegTask( 1<< CFG_TASK_SW2_BUTTON_PUSHED_ID, UTIL_SEQ_RFU, Button2_Trigger_Received );
  
  /* Init flags, variables, and buffers */ 
  Custom_App_Context.Srvtoclient_Notification_Status=0;                  

  for (i=0; i<BYTES_PER_PACKET; i++)
  {
    NotifyCharData[i+2] = i;  /* First two bytes are for the packet index */
  }  
  
  /* USER CODE END CUSTOM_APP_Init */
  return;
}

/* USER CODE BEGIN FD */

/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/

  /* My_P2P_Server */
void Custom_Srvtoclient_Update_Char(void) /* Property Read */
{
  Custom_STM_App_Update_Char(CUSTOM_STM_SRVTOCLIENT, (uint8_t *)UpdateCharData);
  /* USER CODE BEGIN Srvtoclient_UC*/

  /* USER CODE END Srvtoclient_UC*/
  return;
}

void Custom_Srvtoclient_Send_Notification(void) /* Property Notification */
 {
  if(Custom_App_Context.Srvtoclient_Notification_Status)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_SRVTOCLIENT, (uint8_t *)NotifyCharData);
    /* USER CODE BEGIN Srvtoclient_NS*/

    /* USER CODE END Srvtoclient_NS*/
  }
  else
  {
    APP_DBG_MSG("-- CUSTOM APPLICATION : CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
  }
  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/
//[JT]
void P2PS_APP_SW1_Button_Action(void)
{
  //APP_DBG_MSG("Start Notifications to Client\n ");    
  UTIL_SEQ_SetTask( 1<<CFG_TASK_START_NOTIFICATIONS_ID, CFG_SCH_PRIO_0);

  return;
}


//[JT]
static void Button2_Trigger_Received(void)
{
  PHY_Configuration();
}

   


void P2PS_Send_Notification(void)
{
     
  packet_idx = (uint16_t*)NotifyCharData;
  *packet_idx += 1; /* packet index increment in first two element in payload */
         
  if(Custom_App_Context.Srvtoclient_Notification_Status){
    HAL_GPIO_WritePin(BLUE_LED1_GPIO_Port, BLUE_LED1_Pin, GPIO_PIN_SET);
  
    APP_DBG_MSG("%04d \n ", *packet_idx);

    if(TpFlowStatus == TP_FLOW_ON)
    {
      
      Custom_Srvtoclient_Send_Notification();
      
      if (TpFlowStatus == TP_FLOW_OFF)
      {
        *packet_idx -= 1; /* Decrement the packet index, so it can be retried since the transmission failed */    
      }
      else
      {
        UTIL_SEQ_SetTask( 1<<CFG_TASK_START_NOTIFICATIONS_ID, CFG_SCH_PRIO_0);
      }
    }  
   } 
   else {
     APP_DBG_MSG("-- CAN'T INFORM CLIENT -  NOTIFICATION DISABLED\n ");
   }

  return;  
}

void Enable_Flow()
{
  TpFlowStatus = TP_FLOW_ON; //[JT] - Application can try sending data again
  UTIL_SEQ_SetTask( 1<<CFG_TASK_START_NOTIFICATIONS_ID, CFG_SCH_PRIO_0);
}

/* USER CODE END FD_LOCAL_FUNCTIONS*/
