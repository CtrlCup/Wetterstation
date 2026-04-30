#include "espNow.h"

extern struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData)); // Paket in die Struktur kopieren
  
  Serial.print("------------------------------\n");
  Serial.print("Received data from: ");
  Serial.println(myData.boardID);
  Serial.print("Temperature: ");
  Serial.print(myData.temperature);
  Serial.print(" °C \nHumidity: ");
  Serial.print(myData.humidity);
  Serial.print(" %\nPressure: ");
  Serial.print(myData.pressure);
  Serial.print(" hPa\n------------------------------\n");
}

void initEspNow() {
  Serial.begin(115200);
  esp_now_init();
  esp_now_register_recv_cb(OnDataRecv); 
}
