void init_water_level(){
  // Set WATER_LEVEL_POIWER as an OUTPUT
  pinMode(WATER_LEVEL_POWER, OUTPUT);
  
  // Set to LOW so no power flows through the sensor
  digitalWrite(WATER_LEVEL_POWER, LOW);
  
}

int read_water_level(){
  digitalWrite(WATER_LEVEL_POWER, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  int val = analogRead(WATER_LEVEL_SIGNAL);    // Read the analog value form sensor
  digitalWrite(WATER_LEVEL_POWER, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}
