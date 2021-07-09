float read_moisture(int sensor_pin){
  int sensor_analog = analogRead(sensor_pin);
  return map(sensor_analog,0,1024,0,100);
 }
