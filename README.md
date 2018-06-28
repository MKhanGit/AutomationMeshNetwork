# AutomationMeshNetwork
Collection of code for running an IoT Automation network on embedded devices, with our without a head.

## Base Station Firmware
The base station firmware is designed to run on the ESP8266 module,  utilizing the EEPROM for storing WiFi Access credentials and running an ad-hoc HTTP server which is used for interacting with the system. The module can be put into Access Point mode by pulling D1 to Ground, or conversely will be put into client mode if D1 is left open (in which case the interal pullup will pull D1 to 3.3v). Configuration for AP settings can be found in the main file.

| ![space-1.jpg](https://i.imgur.com/NvLAFBr.jpg) |
|:--:|
| *"NodeMCU", a popular dev board for implementing the ESP8266.* |
