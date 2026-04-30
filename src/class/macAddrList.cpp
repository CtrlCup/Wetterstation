#pragma once

#include "macAddrList.h"
#include <WiFi.h>

uint8_t espNowAddress[] = {0x64, 0xE8, 0x33, 0xAC, 0xC3, 0x8C};
uint8_t senderAddress[] = {0x18, 0x8B, 0x0E, 0x31, 0x94, 0x5C};

void macAddr::getMacAddress() {
    Serial.println("ESP32-C3 MAC Address: " + WiFi.macAddress());
}