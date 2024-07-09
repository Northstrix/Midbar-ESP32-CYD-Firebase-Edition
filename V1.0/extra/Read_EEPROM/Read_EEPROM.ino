/*
Midbar ESP32 CYD Firebase Edition
Distributed under the MIT License
© Copyright Maxim Bortnikov 2024
For more information please visit
https://github.com/Northstrix/Midbar-ESP32-CYD-Firebase-Edition
https://sourceforge.net/projects/midbar-esp32-cyd-firebase/
Required libraries:
https://github.com/Northstrix/AES_in_CBC_mode_for_microcontrollers
https://github.com/peterferrie/serpent
https://github.com/ulwanski/sha512
https://github.com/Bodmer/TFT_eSPI
https://github.com/intrbiz/arduino-crypto
https://github.com/techpaul/PS2KeyAdvanced
https://github.com/techpaul/PS2KeyMap
https://github.com/mobizt/Firebase-ESP32
*/
#include <EEPROM.h>

#define EEPROM_SIZE 511

void setup() {
  Serial.begin(115200);
  Serial.println();
  EEPROM.begin(EEPROM_SIZE);
  for (int i = 0; i < EEPROM_SIZE; i++) {
    Serial.print("[");
    Serial.print(i);
    Serial.print("]");
    if (EEPROM.read(i) < 16)
      Serial.print("0");
    Serial.println(EEPROM.read(i), HEX);
  }
  EEPROM.end();
}

void loop() {}
