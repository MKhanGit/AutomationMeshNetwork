//Strings
String output = "System is turned OFF";
String SPACE_STR = "        ";
//extern "C" {
//#include<user_interface.h>
//}
//#include "./DNSServer.h"
//const byte        DNS_PORT = 53;          // Capture DNS requests on port 53

//DNSServer         dnsServer;              // Create the DNS object


void handleRoot() {
  String systemState=systemStatus();
  String htmlStr =  "<html>"
                    "<head>"
                    "<!-- Latest compiled and minified CSS -->"
                    ""
                    "<title>NodePanel</title>"
                    "<meta charset='utf-8'>"
                    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                    "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>"
                    "<!-- jQuery library -->"
                    "<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>"
                    "<!-- Latest compiled JavaScript -->"
                    "<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>"
                    ""
                    ""
                    "<style>"
                    ".col-lg-6{"
                    "padding-top: 4px;"
                    "padding-bottom: 4px;"
                    "}"
                    "</style>"
                    "<script>"
                    "function toggle()"
                    "{"
                    "  $.post( '/led', {} );"
                    "  $('#inq').load('/LINQ');"
                    "}"
                    "function L_On()"
                    "{"
                    "  $.post( '/LON', {} );"
                    "  $('#inq').load('/LINQ');"
                    "}"
                    "function L_Off()"
                    "{"
                    "  $.post( '/LOFF', {} );"
                    "  $('#inq').load('/LINQ');"
                    "}"
                    "function L_Inquire()"
                    "{"
                    "  $('#inq').load('/LINQ');"
                    "}"
                    "function editsettings()"
                    "{"
                    "  window.location.href = '/EDITSETTINGS';"
                    "}"
                    "</script>"

                    "</head>"
                    "<body>"
                    "<h3>NodeMCUControl Panel</h3><pre id='inq'>"+systemState+"</pre>"
                    "<!--<div class='container'>-->"
                    ""
                    "<div class='container-fluid'>"
                    ""
                    "<div class='row'>"
                    "<div class='col-lg-6'><button type='button' class='btn btn-lg btn-block btn-info' onclick=L_Inquire()>Check Water Status</button></div>"
                    "<div class='col-lg-6'>&nbsp;</div>"
                    "</div>"
                    ""
                    "<div class='row'>"
                    "<div class='col-lg-6'><button type='button' class='btn btn-lg btn-block btn-success' onclick=L_On()>Water ON</button></div>"
                    "<div class='col-lg-6'><button type='button' class='btn btn-lg btn-block btn-danger' onclick=L_Off()>Water OFF</button></div>"
                    "</div>"
                    ""
                    "<div class='row'>"
                    "<div class='col-lg-6'><button type='button' class='btn btn-lg btn-block btn-primary' onclick=toggle()>Toggle System Status</button></div>"
                    "<div class='col-lg-6'><button type='button' class='btn btn-lg btn-block btn-secondary' onclick='editsettings()'>Change WiFi Settings</button></div>"
                    "</div>"
                    ""
                    "</div>"
                    ""
                    "</body>"
                    "</html>";
  server.send(200, "text/html", htmlStr);
}


void RedirectRoot() {

  String htmlStr =  "<html>"
                    "<head>"
                    "<title>GoTo Index</title>"
                    "<meta charset='utf-8'>"
                    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                    "<meta http-equiv='refresh' content='0; url=http://10.10.10.1/'>"
                    "<script type='text/javascript'>"
                    "window.location.href = 'http://10.10.10.1/'"
                    "</script>"
                    "</head>"
                    "<body>"
                    "</body>"
                    "</html>";
  server.send(200, "text/html", htmlStr);
}

String systemStatus() {
  ledstate = digitalRead(LED_BUILTIN);
  if (ledstate) {
    output = "System is Turned ON";
  }
  else {
    output = "System is Turned OFF";
  }
  return output;
}

void ledToggle() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  ledstate = digitalRead(LED_BUILTIN);
  server.send(200, "text/html", "<h1>LED has been toggled to " + String(ledstate) + "</h1>");
}

void ledON() {
  digitalWrite(LED_BUILTIN, HIGH);
  ledstate = digitalRead(LED_BUILTIN);
  server.send(200, "text/html", "<h1>LED has been toggled to " + String(ledstate) + "</h1>");
}

void ledOFF() {
  digitalWrite(LED_BUILTIN, LOW);
  ledstate = digitalRead(LED_BUILTIN);
  server.send(200, "text/html", "<h1>LED has been toggled to " + String(ledstate) + "</h1>");
}

void ledInq() {
  output=systemStatus();
  server.send(200, "text/html", output);
}
