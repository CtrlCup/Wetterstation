#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <time.h>
#include "stuct.h"

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void initEspNow();
void case_1();