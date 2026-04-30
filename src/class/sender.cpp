#include "sender.h"
#include "stuct.h"
#include "macAddrList.h"

extern struct_message myData;

void initSenderSensors() {    
    Serial.begin(115200);
    delay(1000);
    Serial.println("ESP32-C3 Weather Station");

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_now_peer_info_t peerInfo;
    memset(&peerInfo, 0, sizeof(peerInfo));  // ← wichtig!
    memcpy(peerInfo.peer_addr, espNowAddress, 6);
    peerInfo.channel = 0;
    peerInfo.ifidx = WIFI_IF_STA;           // ← für C3 empfohlen
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }
}

void sendData(const uint8_t *macAddr, const struct_message &data) {
  esp_err_t result = esp_now_send(macAddr, (uint8_t *) &data, sizeof(data));
  
  // Optional: Feedback in der Konsole
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }
}
