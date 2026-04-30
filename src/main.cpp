#include "class/espNow.h"
#include "class/sender.h"
#include "class/macAddrList.h"
#include <esp_wifi.h>
#include <random>

struct_message myData;
int boardID = 1; // Eindeutige ID für jede Wetterstation
bool isSender = false;

/* 
Wenn isSender == true, dann wird das ESP als Wetterstation verwendet, 
wenn isSender == false, dann wird das ESP als Empfänger verwendet.

Bitte die MAC-Adresse in der class/macAddrList.cpp anpassen, damit die Geräte miteinander 
kommunizieren können.

senderAddress ist die MAC-Adresse des Senders (Wetterstation)
espNowAddress ist die MAC-Adresse des Empfängers.
 */

void setup() {
  WiFi.mode(WIFI_STA);
  uint8_t mac[6];
  esp_wifi_get_mac(WIFI_IF_STA, mac);

  if (memcmp(mac, senderAddress, 6) == 0) {
      isSender = true;
  }

  if (isSender) {
    initSenderSensors();
  } else {
    initEspNow();
  }
}

void loop() {
  if (isSender) {
    myData.boardID = boardID;
    myData.pressure = random(9500, 10501) / 10.0;
    myData.temperature = random(-100, 401) / 10.0;
    myData.humidity = random(0, 101);

    // Senden
    sendData(espNowAddress, myData);
    myData = struct_message{}; // Alle Werte zurücksetzen
    delay(3000);
  } else {
    // Empfänger muss nichts tun, da die Daten im Callback verarbeitet werden
    delay(1000000); // Verhindert, dass die Schleife zu schnell läuft
  }
}
