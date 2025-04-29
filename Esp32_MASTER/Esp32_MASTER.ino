#include "LoRa_E22.h"

LoRa_E22 lora(&Serial2);  

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600,SERIAL_8N1,18,19); // Rx: 18 tx: 19
  lora.begin();

}

void loop() {

  for(int i = 5; i < 176;i+=5){

    int ServoAci = i;

    String gidenVeri = String(ServoAci);

    ResponseStatus rs = lora.sendMessage(gidenVeri);

    Serial.println(rs.getResponseDescription());
    Serial.println("Giden Veri: " + gidenVeri);
    Serial.println("--------------");

    delay(85);

  }

  



}
