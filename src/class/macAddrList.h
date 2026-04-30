#pragma once

#include <Arduino.h>

extern uint8_t espNowAddress[];
extern uint8_t senderAddress[];

namespace macAddr {
    void getMacAddress();
}