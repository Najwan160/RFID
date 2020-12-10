#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 4
#define RST_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Put your card to the reader...");

}

void loop() {

  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  Serial.print("UID tag :");
  String content = "";
  byte letter;

  for(byte i = 0; i < mfrc.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    content.concat(String(mftc522.uid.uidByte[i], HEX);
  }

  Serial.println();
  Serial.print("Pesan : ");
  content.toUpperCase();

  if(content.substring(1) == "B9 5B AD BY"){
    Serial.println("Kartu cocok");
    Serial.println();
    delay(1000);
  }

  else if (content.substring(1) == "B9 5B AD BY"){
    Serial.println("Kartu cocok");
    Serial.println();
    delay(1000);
  }

  else{
    Serial.println("Kartu tidak cocok");
    delay(1000);
  }
  
 }

}
