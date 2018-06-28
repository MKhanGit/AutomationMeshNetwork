void changeWifiSettings() {
  String currentssid=eeprom_read_ssid();
  String htmlStr =  "<html>"
                    "<head>"
                    "<!-- Latest compiled and minified CSS -->"
                    ""
                    "<title>Change Wifi Settings</title>"
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
                    "function goback()"
                    "{"
                    "  window.history.back();"
                    "}"
                    "</script>"

                    "</head>"
                    "<body>"
                    "<h3>NodeMCUControl Panel</h3>"
                    "<pre>Currently configured for network '"+currentssid+"'</pre>"
                    "<pre id='inq'>Please enter the new connection info below</pre>"
                    "<div class='container-fluid'>"
                    ""
                    "<div class='form-group row'>"
                    "<div class='col-lg-6'>"
                    "<form action=/changewifi method=POST>"
                    "<input class='form-control input-lg' type=textbox placeholder='WiFi Name' name=wname id=ssid>"
                    "<input class='form-control input-lg' type=password placeholder='Wifi Password' name=wpass id=psswd>"
                    "</div>"
                    "<div class='col-lg-6'>"
                    "<input type=submit class='btn btn-lg btn-block btn-success' value='Update WiFi'><br/>"
                    "<button type='button' class='btn btn-lg btn-block btn-warning' onclick='goback()'>Go Back</button>"
                    "</div>"
                    "</form>"
                    "</div>"
                    ""
                    "</div>"
                    ""
                    ""
                    "</html>";
  server.send(200, "text/html", htmlStr);
}

void POST_ssid_update() {

  String ssid = server.arg("wname");
  String ssidkey = server.arg("wpass");

  Serial.println(ssid);
  Serial.println(ssidkey);

  eeprom_write_ssid(ssid);
  eeprom_write_psswd(ssidkey);
  
  String htmlStr =  "<html>"
                    "<head>"
                    "<title>Change Wifi Settings</title>"
                    "<meta charset='utf-8'>"
                    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                    "<meta http-equiv='refresh' content='0; url=/'>"
                    "<script type='text/javascript'>"
                    "window.location.href = '/'"
                    "</script>"
                    "</head>"
                    "<body>"
                    "</body>"
                    "</html>";
  server.send(200, "text/html", htmlStr);
}
