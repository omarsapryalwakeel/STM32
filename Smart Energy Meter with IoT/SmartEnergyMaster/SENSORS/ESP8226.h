/*
 * ESP8226.h
 *
 *  Created on: Mar 19, 2025
 *      Author: omar
 */

#ifndef ESP8226_H_
#define ESP8226_H_

#ifndef ESP8266_H
#define ESP8266_H

#include "main.h"  // Change based on your STM32 series
#include <string.h>
#include <stdio.h>

#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASS "your_wifi_password"
#define SERVER_IP "your_server.com"
#define SERVER_PORT "80" // Change to 1883 for MQTT

typedef enum {
    ESP8266_OK = 0,         // Operation successful
    ESP8266_ERROR,          // General error
    ESP8266_TIMEOUT,        // Response timeout
    ESP8266_NOT_CONNECTED,  // Not connected to Wi-Fi
    ESP8266_CONNECTED,      // Connected to Wi-Fi
    ESP8266_SEND_FAILED,    // Data sending failed
} ESP8266_Status;

ESP8266_Status ESP8266_Init(UART_HandleTypeDef *huart);
ESP8266_Status ESP8266_SendCommand(char *command, char *expected_response, uint32_t timeout);
ESP8266_Status ESP8266_ConnectWiFi(void);
ESP8266_Status ESP8266_SendData(char *data);
ESP8266_Status ESP8266_CloseConnection(void);
ESP8266_Status ESP8266_CheckConnection(void);

#endif // ESP8266_H


#endif /* ESP8226_H_ */
