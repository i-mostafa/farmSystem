void init_flame(){
   pinMode ( FLAME_SENSOR , INPUT ); // declaring sensor pin as input pin for Arduino
}


int read_flame(){
  return !digitalRead(FLAME_SENSOR);
}
