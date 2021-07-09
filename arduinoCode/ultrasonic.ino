 void init_ultrasonic(){
  pinMode(ULTRA_SONIC_TRIGGER, OUTPUT); // Sets the ULTRA_SONIC_TRIGGER as an OUTPUT
  pinMode(ULTRA_SONIC_ECHO, INPUT); // Sets the ULTRA_SONIC_ECHO as an INPUT
  Serial.println("ultrasonic configured sucessfully");
 }


 int read_ultrasonic(){
  long duration; // variable for the duration of sound wave travel
  int distance; // variable for the distance measurement

   // Clears the ULTRA_SONIC_TRIGGER condition
  digitalWrite(ULTRA_SONIC_TRIGGER, LOW);
  delayMicroseconds(2);
  // Sets the ULTRA_SONIC_TRIGGER HIGH (ACTIVE) for 10 microseconds
  digitalWrite(ULTRA_SONIC_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_SONIC_TRIGGER, LOW);
  // Reads the ULTRA_SONIC_ECHO, returns the sound wave travel time in microseconds
  duration = pulseIn(ULTRA_SONIC_ECHO, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");
  return distance;
 }
      
