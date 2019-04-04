/**
* The MySensors Arduino library handles the wireless radio link and protocol
* between your home built sensors/actuators and HA controller of choice.
* The sensors forms a self healing radio network with optional repeaters. Each
* repeater and gateway builds a routing tables in EEPROM which keeps track of the
* network topology allowing messages to be routed to nodes.
*
* Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
* Copyright (C) 2013-2019 Sensnology AB
* Full contributor list: https://github.com/mysensors/MySensors/graphs/contributors
*
* Documentation: http://www.mysensors.org
* Support Forum: http://forum.mysensors.org
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* version 2 as published by the Free Software Foundation.
*
*******************************
*
* DESCRIPTION
* The ArduinoGateway prints data received from sensors on the serial link.
* The gateway accepts input on serial which will be sent out on radio network.
*
* The GW code is designed for STM32F103C8T6
*
*/

// Enable debug prints to serial monitor
#define SERIAL_USB		// Оставляем Serial за USB, USART0-2 будут соответственно Serial1-3
#define MY_DEBUG
#define MY_SERIALDEVICE Serial1		// Указываем свой порт 

// Enable and select radio type attached
#define MY_RADIO_RF24
//#define MY_RADIO_NRF5_ESB
//#define MY_RADIO_RFM69
//#define MY_RADIO_RFM95

// По умолчанию будет задействован первый порт SPI
// на пинах - PA5, PA6, PA7

//(PB0, PA1, PA0);  // CE, CSN, IRQ pins
//Define this to change the chip enable pin from the default.
#define MY_RF24_CE_PIN PB0	// Управляет режимом радимодуля - приём или передача

//Define this to change the chip select pin from the default.
#define MY_RF24_CS_PIN PA1	// Пин для выбора устройства на шине SPI с которым мы хотим работать

//TODO: проверть IRQ
#define MY_RF24_IRQ_PIN PA0	// По идее нога для прерываний, но надо проверить, задействоана ли она вообще?

// Set LOW transmit power level as default, if you have an amplified NRF-module and
// power your radio separately with a good regulator you can turn up PA level.
#define MY_RF24_PA_LEVEL RF24_PA_LOW	// Устанавливаем мощьность передатчика

// Enable serial gateway
#define MY_GATEWAY_SERIAL	// тип шлюза

// Enable inclusion mode
//#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
//#define MY_INCLUSION_BUTTON_FEATURE

// Inverses behavior of inclusion button (if using external pullup)
//#define MY_INCLUSION_BUTTON_EXTERNAL_PULLUP

// Set inclusion mode duration (in seconds)
//#define MY_INCLUSION_MODE_DURATION 60
// Digital pin used for inclusion mode button
//#define MY_INCLUSION_MODE_BUTTON_PIN  3

// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Inverses the behavior of leds
//#define MY_WITH_LEDS_BLINKING_INVERSE

// Flash leds on rx/tx/err
// Uncomment to override default HW configurations
#define MY_DEFAULT_ERR_LED_PIN PC13  // Error led pin
#define MY_DEFAULT_RX_LED_PIN  PC13  // Receive led pin
#define MY_DEFAULT_TX_LED_PIN  PC13  // the PCB, on board LED

#include <MySensors.h>

//SPIClass SPI_2(2); // Для работы со вторым портом SPI надо править файл библиотеки - w5500.cpp

void setup()
{
	// Setup locally attached sensors
 Serial1.println("Gateway started");
}

void presentation()
{
	// Present locally attached sensors
}

void loop()
{
	// Send locally attached sensor data here
}
