void eeprom_write_ssid(String inWord)
{
  int address = 0x20;
  byte value;
  EEPROM.begin(512);
  for (int i = 0; i < inWord.length(); i++) {
    value = inWord.charAt(i);
    //Serial.print("Writing: "); Serial.print(value); Serial.print(" to addr: "); Serial.println(address);
    EEPROM.write(address, value);
    address = address + 1;
    delay(5);
  }
  while (address < 0x40) {
    EEPROM.write(address, 0xFF);
    address = address + 1;
    delay(5);
  }
  delay(500);
  EEPROM.commit();
  delay(50);
  EEPROM.end();
}

void eeprom_write_psswd(String inWord)
{
  int address = 0x40;
  byte value;
  EEPROM.begin(512);
  for (int i = 0; i < inWord.length(); i++) {
    value = inWord.charAt(i);
    //Serial.print("Writing: "); Serial.print(value); Serial.print(" to addr: "); Serial.println(address);
    EEPROM.write(address, value);
    address = address + 1;
    delay(5);
  }
  while (address < 0x80) {
    EEPROM.write(address, 0xFF);
    address = address + 1;
    delay(5);
  }
  delay(500);
  EEPROM.commit();
  delay(50);
  EEPROM.end();
}
