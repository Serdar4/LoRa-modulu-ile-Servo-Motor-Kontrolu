// Veri Alacak Esp32 

#include <LoRa_E22.h>
#include <ESP32Servo.h>

Servo servo;

const byte ServoPin = 12;

LoRa_E22 lora(&Serial2);



void setup() {
  Serial2.begin(9600,SERIAL_8N1,22,23); // Rx: 22 Tx: 23
  Serial.begin(115200);
  lora.begin();
  servo.attach(ServoPin);

}

void loop() {

  if(lora.available()){

    ResponseContainer rc = lora.receiveMessage();

    String gelenVeri = rc.data;

    int servoAci = gelenVeri.toInt();

    servo.write(servoAci);

    Serial.print("Gelen Veri: ");
    Serial.println(gelenVeri);


  }



}
