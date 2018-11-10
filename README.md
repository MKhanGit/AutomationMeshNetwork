# AutomationMeshNetwork
Collection of code for running an IoT Automation network on embedded devices, with our without a head.

## Base Station Firmware
The base station firmware is designed to run on the ESP8266 module,  utilizing the EEPROM for storing WiFi Access credentials and running an ad-hoc HTTP server which is used for interacting with the system. The module can be put into Access Point mode by pulling D1 to Ground, or conversely will be put into client mode if D1 is left open (in which case the interal pullup will pull D1 to 3.3v). Configuration for AP settings can be found in the main file.

| ![space-1.jpg](https://i.imgur.com/NvLAFBr.jpg) |
|:--:|
| *"NodeMCU", a popular dev board for implementing the ESP8266.* |


# Initial Setup
After you load this firmware for the first time, you must start the device in AP mode in order to save the WiFi credentials for your home network in the EEPROM of the ESP8266. This way the device can automatically connect to your home network every time it powers on.

To start the device in AP mode and setup the WiFi:
1. First connect D1 (GPIO5) to GND, *then* apply power to the module.
2. Connect to the WiFi network that the device generates (using the SSID/PSSWD set in _BaseStationFirmware.ino_).
3. Once you are connected to the ESP8266 access point, navigate to [http://10.10.10.1](http://10.10.10.1), this will bring up the control panel.
4. Click on "Change WiFi Settings" and enter your home network SSID and password, then click Save.

5. Remove the D1 (GPIO5) connection to GND.

6. Connect the device to a serial terminal and then reboot it.
7. The terminal should print a success message once it connects to your home network. It will then display it's own IP address on the network. This IP address is important to take note of. (You can optionally set this IP in your router's DCHP reservation table if you want your ESP8266 to always have the same IP.)

8. You can now access the ESP8266 and control it's GPIO pins by opening that IP address in a browser window.

The device will now remember your home wifi network even if you cycle power!
