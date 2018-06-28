String eeprom_read_ssid()
{
  String eeprom_ssid="";
  int address = 0x20;
  byte value;
  EEPROM.begin(512);
  while (address < 0x40) {
    value = EEPROM.read(address);
    if(value==0xFF){
      break;
      }
    eeprom_ssid+=char(value);
    address = address + 1;
    delay(5);
  }
  delay(50);
  EEPROM.end();
  return eeprom_ssid;
}

String eeprom_read_psswd()
{
  String eeprom_psswd="";
  int address = 0x40;
  byte value;
  EEPROM.begin(512);
  while (address < 0x80) {
    value = EEPROM.read(address);
    if(value==0xFF){
      break;
      }
    eeprom_psswd+=char(value);
    address = address + 1;
    delay(5);
  }
  delay(50);
  EEPROM.end();
  return eeprom_psswd;
}
