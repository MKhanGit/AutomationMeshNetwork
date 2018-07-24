5
/* Create a web server on either an existing interface or on an AP. */
/* ssid and password are stored in EEPROM addresses 0x20 (32) and 0x40 (64) respectively */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

String ssid;
String password;
int ledstate;
boolean client_mode;

ESP8266WebServer server(80);
IPAddress         apIP(10, 10, 10, 1);    // Private network for server

/* Set these to your desired credentials. */
const char *APssid = "AutoMeshNetwork";
const char *APpsswd = "YourPsswdHere";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  client_mode = digitalRead(D1);
  if (client_mode) {
    ssid = eeprom_read_ssid();
    password = eeprom_read_psswd();
    Serial.print("Configuring client access...");
    WiFi.begin(ssid.c_str(), password.c_str());

    while (WiFi.status() != WL_CONNECTED ) {
      delay(500);
      Serial.print(".");
    }

    Serial.println();
    Serial.println("Wifi connection success!");
  }

  else {
    Serial.print("Configuring as AP...");
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    boolean result = WiFi.softAP(APssid, APpsswd);
    if (result == true) {
      Serial.println("Wifi AP success!");
      IPAddress myIP = WiFi.softAPIP();
      //dnsServer.start(DNS_PORT, "*", apIP);
      Serial.print("AP IP address: ");
      Serial.println(myIP);

    }
    else {
      Serial.println("Wifi AP Failed!");
    }
  }

  Serial.print("Node MCU Address : ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led", ledToggle);
  server.on("/LON", ledON);
  server.on("/LOFF", ledOFF);
  server.on("/LINQ", ledInq);
  server.on("/EDITSETTINGS", changeWifiSettings);
  server.on("/changewifi", POST_ssid_update);
  //server.onNotFound(RedirectRoot);
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(" ");

  if (client_mode) {
    delay(500);
    Serial.print(ssid); Serial.print(SPACE_STR); Serial.println(WiFi.localIP());
  }
  else {
    delay(500);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP:"); Serial.print(APssid); Serial.print(SPACE_STR); Serial.println(myIP);
  }
}

void loop() {
  if (!digitalRead(D2)) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("System Turned ON by button");
    delay(500);
  }
  if (!digitalRead(D3)) {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("System Turned OFF by button");
    delay(500);
  }

   if (!digitalRead(D4)) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Serial.println("System Toggled by button");
    delay(500);
  }
server.handleClient();
}
