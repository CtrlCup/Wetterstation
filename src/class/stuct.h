#pragma once

#include <Arduino.h>

typedef struct __attribute__((packed)) {
    // System-Info
    int boardID = 0;
    
    // BME280 Daten
    float temperature = NAN;   // °C
    float humidity = NAN;      // %
    float pressure = NAN;      // hPa
    
    // ENS160 + AHT21 Daten
    uint16_t eco2 = 0;       // Äquivalentes CO2 in ppm
    uint16_t tvoc = 0;       // Flüchtige org. Verbindungen in ppb
    uint8_t aqi = 0;         // Air Quality Index (1-5)
    
    // LTR390 Daten
    float lux = NAN;           // Helligkeit
    float uvIndex = NAN;       // UV-Belastung
    
    // Mikrofon (INMP441)
    float noiseLevel = NAN;    // Durchschnittlicher Pegel in dB

    float batteryVoltage = NAN; // Batteriestatus in Volt

    // Bodenfeuchtigkeit
    uint8_t moistureLevel = 255;   // Bodenfeuchtigkeit in %

} struct_message;