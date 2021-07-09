unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;
String serverName = "http://192.168.8.123:5050/mail";

void init_mailer(){
   delay(4000);   //Delay needed before calling the WiFi.begin
 WiFi.begin(ssid, password);
  Serial.println("Connecting");
//  while(WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}


void send_report_mail(){
   //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + "?tank_level=" +String(tank_level) +
                                       "&out_moisture=" +String(out_moisture) +
                                       "&in_moisture="+ String(in_moisture) +
                                       "&out_temp="+ String(out_temp) +
                                       "&in_temp="+ String(in_temp) +
                                       "&flame="+ String(flame) +
                                       "&rain="+ String(rain) +
                                       "&land_pumb="+ String(land_pumb || out_pumb_by_moisture) +
                                       "&in_pumb=" +String(in_pumb || in_pumb_by_moisture) +
                                       "&in_pumb_timer="+ String(millis()- in_pumb_timer) + 
                                       "&land_pumb_timer="+ String(millis()- land_pumb_timer) ;      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }

}
