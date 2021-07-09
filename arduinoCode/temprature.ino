float read_temp(int temp_sensor){
  int  val = analogRead(temp_sensor);
  float mv = ( val/2048.0)*3300;
  float cel = mv/10;
   
//  Serial.print("TEMPRATURE = ");
//  Serial.print(cel);
//  Serial.print("*C");
//  Serial.println();
  return cel;
 }


float filter_temp (int temp_sensor){
  float sum = 0;
  for(int i = 0; i< 50 ; i++){
    sum += read_temp(temp_sensor);
    delay(10);
  }
  return sum/50.0;
}
