# STM32-Hotspot/BLE-Basic-DataThroughput-Server MCU Firmware Package, based on STM32CubeWB Release v1.13.1

![latest tag](https://img.shields.io/github/v/tag/STMicroelectronics/STM32CubeWB.svg?color=brightgreen)

## Example

This Hotspot FW package includes:
* Application example under "Projects\P-NUCLEO-WB55.Nucleo\Applications\BLE" called BLE_Basic_DataThroughput_Server.     
   * This example implements a basic BLE GATT Server for data throughput application via notification to a GATT Client using the BLE component. 
   * The Client can be either another STM32WB55xx device or an iOS or Android Smartphone running a generic app like ST BLE Toolbox or LightBlue. 
   * The Server device transmits a stream of Notification packets, and the Client device receives these packets. 
   * The example also aims to demonstrate to the user how to configure the system (pinout, clocks, peripherals, utilities) and BLE WPAN middleware from STM32CubeMX to properly configure the BLE stack, and show how to schedule data transfers via Notifications from the user application to maximize throughput.       
   * Development tools, toolchains/compilers: STM32CubeMX v6.4.0, IAR EWARM V9.20.x
   * Supported Devices and hardware boards: NUCLEO-WB55RG
   * Known limitations: None

## Boards Needed

  * Two NUCLEO-WB55RG
    * [NUCLEO-WB55RG](https://www.st.com/en/evaluation-tools/nucleo-wb55rg.html)

## Troubleshooting

**Caution** : Issues and the pull-requests are **not supported** to submit problems or suggestions related to the software delivered in this repository. The BLE_Basic_DataThroughput_Server example is being delivered as-is, and not necessarily supported by ST.

**For any other question** related to the product, the hardware performance or characteristics, the tools, the environment, you can submit it to the **ST Community** on the STM32 MCUs related [page](https://community.st.com/s/topic/0TO0X000000BSqSWAW/stm32-mcus).
