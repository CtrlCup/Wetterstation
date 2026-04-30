#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <random>
#include "stuct.h"

void initSenderSensors();
void sendData(const uint8_t *macAddr, const struct_message &data);


