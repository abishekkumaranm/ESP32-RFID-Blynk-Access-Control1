#define BLYNK_TEMPLATE_ID "TMPL3uDzPjL7a"
#define BLYNK_TEMPLATE_NAME "RFID"
#define BLYNK_AUTH_TOKEN "7A44UqUzbYJq89od5Di0pJdmUDQFCbYz"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <MFRC522.h>

char ssid[] = "Janani";

char pass[] = "12345698";

#define SS_PIN 5
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN);

byte allowedUID[] = {0x63, 0x16, 0xD7, 0x05};

void setup()
{
  Serial.begin(115200);

  SPI.begin(18, 19, 23, 5);
  rfid.PCD_Init();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("RFID Ready");
}

void loop()
{
  Blynk.run();

  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  bool accessGranted = true;
  String uidString = "";

for (byte i = 0; i < rfid.uid.size; i++)
  {
    uidString += String(rfid.uid.uidByte[i], HEX);
    uidString += " ";

    if (rfid.uid.uidByte[i] != allowedUID[i])
      accessGranted = false;
  }

  uidString.toUpperCase();

  Blynk.virtualWrite(V0, uidString);

  if (accessGranted)
  {
    Serial.println("ACCESS ALLOWED");
    Blynk.virtualWrite(V1, "ACCESS ALLOWED");
  }
  else
  {
    Serial.println("ACCESS DENIED");
    Blynk.virtualWrite(V1, "ACCESS DENIED");
  }

  rfid.PICC_HaltA();

  delay(1000);
}
