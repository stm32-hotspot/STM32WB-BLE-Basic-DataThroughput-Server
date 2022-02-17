/**
  @page BLE_Basic_DataThroughput_Server      
  @verbatim
  ******************************************************************************
  * @file    BLE/BLE_Basic_DataThroughput_Server/readme.txt 
  * @author  MCD Application Team
  * @brief   Server implementation for max Data transfer via notification to client.
  *          
  ******************************************************************************
  *
  * Copyright (c) 2019-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

How to use data throughput via notification from GATT server to GATT client using BLE component.
Similar functionliaty as the STM32CubeWB BLE_DataThroughput example, only this example includes only the basic user code for performing the 
data transfers to the client via notification (note that it does not support Client functionality). It also includes all the configuration 
per section 7.6.8 of AN5289 Rev. 6 to maximize data throughput. 
  
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Connectivity, BLE, IPCC, HSEM, RTC, UART, PWR, BLE protocol, BLE pairing, BLE profile, Dual core

@par Directory contents 
  
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/stm32wbxx_hal_conf.h		HAL configuration file
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/stm32wbxx_it.h          	Interrupt handlers header file
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/main.h                  	Header for main.c module
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/app_ble.h                Header for app_ble.c module
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/app_common.h            	Header for all modules with common definition
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/app_conf.h              	Parameters configuration file of the application
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/app_entry.h                    Parameters configuration file of the application
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/ble_conf.h               BLE Services configuration
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/ble_dbg_conf.h           BLE Traces configuration of the BLE services
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/hw_conf.h           		Configuration file of the HW
  - BLE/BLE_Basic_DataThroughput_Server/Core/Inc/utilities_conf.h    		Configuration file of the utilities
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/custom_app.h             Header for Data Throughput Server Application implementation
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/custom_stm.h		Header for Data Throughput Service  implementation
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/stm32wbxx_it.c          	Interrupt handlers
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/main.c                  	Main program
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/system_stm32wbxx.c      	stm32wbxx system source file
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/app_ble.c      	        BLE Profile implementation
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/app_entry.c      		Initialization of the application
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/Target/hw_ipcc.c      	IPCC Driver
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/stm32_lpm_if.c			Low Power Manager Interface
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/hw_timerserver.c 		Timer Server based on RTC
  - BLE/BLE_Basic_DataThroughput_Server/Core/Src/hw_uart.c 			UART Driver
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/custom_app.c             Data Throughput Server Application implementation
  - BLE/BLE_Basic_DataThroughput_Server/STM32_WPAN/App/custom_stm.c		Data Throughput Service implementation
   
     
@par Hardware and Software environment

  - This example runs on STM32WB55xx devices.
  
  - This example has been tested with an STMicroelectronics STM32WB55xx-Nucleo
    board and can be easily tailored to any other supported device 
    and development board.

@par How to use it ? 

This application requires having the stm32wb5x_BLE_Stack_full_fw.bin binary flashed on the Wireless Coprocessor.
If it is not the case, you need to use STM32CubeProgrammer to load the appropriate binary.
All available binaries are located under /Projects/STM32_Copro_Wireless_Binaries directory of the official STM32CubeWB v1.13.1 
package (https://github.com/STMicroelectronics/STM32CubeWB/releases/tag/v1.13.1).
Refer to UM2237 to learn how to use/install STM32CubeProgrammer.
Refer to /Projects/STM32_Copro_Wireless_Binaries/ReleaseNote.html for the detailed procedure to change the
Wireless Coprocessor binary.  

In order to make the program work, you must do the following:
 - Open your preferred toolchain (IAR EWARM or STM32CubeIDE) 
 - Rebuild all files and load your image into target memory

One NUCLEO-WB55RG board is used, and it is configured as the GAP peripheral and GATT Server.
It supports Data transfer service with a transmission characteristic that supports notification.
Open a VT100 terminal on Peripheral side (ST Link Com Port, @115200 bauds).
At startup, the connection is established from a iOS or Android Smartphone Central Device (GATT Client) 
through an app like ST BLE Toolbox app.
 - The peripheral (Gap Peripheral) device starts advertising.
 - The Smartphone (Gap Cental) device scans and automatically connects to the peripheral. 
 - The client starts to search the data transfer service and characteristic.
 - The client enables the notification of the transmission characteristic.
On server side, the notification is started when the SW1 button is pushed (blue led is ON), 
The notification can be started and stopped from both sides.
On the Smartphone client receiving the current notification, the number of bytes can be logged.

Instead of connecting it to a Smartphone, it is also possible to connect it to another NUCLEO-WB55RG 
board, acting as the GATT Client. The GATT Client example is a different example and can be found in the 
STM32-Hotspot github as well (BLE_Basic_DataThroughput_Client). 
In this case, two NUCLEO-WB55RG boards are used, one central and one peripheral. 
They both support a Data transfer service with a transmission characteristic that supports notification.
One board is defined as GAP peripheral, the other board is defined as GAP central.
Open a VT100 terminal on Central and Peripheral side (ST Link Com Port, @115200 bauds).
At startup the connection is established.
 - The peripheral device starts advertising.
 - The central device scans when SW1 is pressed, and automatically connects to the peripheral. 
 - The client on each device starts to search the data transfer service and characteristic.
 - The client enables the notification of the transmission characteristic.
On server side, the notification is started when the SW1 button is pushed (blue led is ON), 
it stops when SW1 is pushed again (blue led is OFF).
The notification can be started and stopped from both sides.
On the client terminal receiving the current notification, the number of bytes per second is displayed.

On the NUCLEO-WB55RG board used as peripheral.
This board can be connected with a smartphone running an application like ST BLE Toolbox.
Start a scan and choose SERVER board to connect.
SW1 starts the notification data.
SW2 changes the PHY (1M or 2M). 

 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 
