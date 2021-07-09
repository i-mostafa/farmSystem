void readData (){
   tank_level = ( 100 * (TANK_HEIGHT  - read_ultrasonic()) )/ TANK_HEIGHT;
   flame = read_flame();
   rain = intToBool( read_water_level(), RAIN_MIDDLE);
   out_moisture = 400 - read_moisture(OUT_MOISTURE);
   in_moisture = 400 - read_moisture(IN_MOISTURE);
   in_temp = filter_temp(IN_TEMP_SENSOR) - TEMP_THRESHOLD;
   out_temp = filter_temp(OUT_TEMP_SENSOR) - TEMP_THRESHOLD;
}


void print_data(){
  Serial.print("tank level : " );
  Serial.print(tank_level );
  
  Serial.print(" - flame : " );
  Serial.print(flame );
  
  Serial.print(" - rain : " );
  Serial.print(rain );
  
  Serial.print(" - out_moisture : " );
  Serial.print(out_moisture );
  
  Serial.print(" - in_moisture : " );
  Serial.print(in_moisture );
  
  Serial.print(" - in_temp : " );
  Serial.print(in_temp );
  
  Serial.print(" - out_temp : " );
  Serial.print(out_temp );
  
  Serial.println();
}

void validate_data(){
  tank_level = validate(tank_level, 0, 100);
}

int validate(int amount, int min, int max){
  if(amount > max) return max;
  if(amount < min) return min;
  return amount;
}

bool intToBool(int amount , int middle){
  if(amount < middle) return false;
  return true;
}
