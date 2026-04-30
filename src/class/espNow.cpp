#include "espNow.h"
#include "myCases.h"

extern struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData)); // Paket in die Struktur kopieren

  switch (myData.boardID) {
    case 1:
      case_1();
      break;
    case 2:
      case_2();
      break;
    case 3:
      case_3();
      break;
    default:
      Serial.println("Unknown board ID: " + String(myData.boardID));
      break;
  }
}

void initEspNow() {
  Serial.begin(115200);
  esp_now_init();
  esp_now_register_recv_cb(OnDataRecv); 
}

void case_1() {
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