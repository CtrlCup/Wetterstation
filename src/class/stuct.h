#pragma once

#include <Arduino.h>

typedef struct __attribute__((packed)) {
    // System-Info
    int boardID;
    
    // BME280 Daten
    float temperature;   // °C
    float humidity;      // %
    float pressure;      // hPa
    
    // ENS160 + AHT21 Daten
    uint16_t eco2;       // Äquivalentes CO2 in ppm
    uint16_t tvoc;       // Flüchtige org. Verbindungen in ppb
    uint8_t aqi;         // Air Quality Index (1-5)
    
    // LTR390 Daten
    float lux;           // Helligkeit
    float uvIndex;       // UV-Belastung
    
    // Mikrofon (INMP441)
    float noiseLevel;    // Durchschnittlicher Pegel in dB
} struct_message;