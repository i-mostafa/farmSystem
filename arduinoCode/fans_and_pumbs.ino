
void init_relay(){
  pinMode(FIRE_PUMB, OUTPUT);
  pinMode(LAND_PUMB, OUTPUT);
  pinMode(IN_PUMB, OUTPUT);
  pinMode(FANS, OUTPUT);

  digitalWrite(FIRE_PUMB, LOW);
  digitalWrite(LAND_PUMB, LOW);
  digitalWrite(IN_PUMB, LOW);
  digitalWrite(FANS, LOW);

  land_pumb_timer = millis();
  in_pumb_timer =    millis() - TIMERS_SHIFT * 1000;
  land_pumb = false;
  in_pumb = false;
  in_pumb_by_moisture = false;
  out_pumb_by_moisture = false;
  
}

void change_state(int pin, bool state){
  digitalWrite(pin, state);
}

void control_pumbs(){
   change_state(FIRE_PUMB, flame);
   control_with_moisture();
   run_land_pumb();
   run_in_pumb(); 
   control_with_moisture();    
}

void control_fans(){
  if(in_temp > MAX_IN_TEMP)  change_state(FANS, true);
  else  change_state(FANS, false);
}

void run_land_pumb(){
  if((millis() - land_pumb_timer) / 1000  > TIMER_PERIOD   && !land_pumb){
    change_state(LAND_PUMB, true);
    land_pumb = true;
    land_pumb_timer = millis();
  }else if( (millis() - land_pumb_timer) / 1000 > TIMER_IRR   && land_pumb){
    change_state(LAND_PUMB, false);
    land_pumb = false;
    land_pumb_timer = millis();
  }
}


void run_in_pumb(){
  if((millis() - in_pumb_timer) / 1000  > TIMER_PERIOD  && !in_pumb){
    change_state(IN_PUMB, true);
    in_pumb = true;
    in_pumb_timer = millis();
  }else if( (millis() - in_pumb_timer) / 1000 > TIMER_IRR   && in_pumb){
    change_state(IN_PUMB, false);
    in_pumb = false;
    in_pumb_timer =  TIMERS_SHIFT + millis();
  }
}

void control_with_moisture(){
  if(in_moisture < IN_MOISTURE_MIN && !in_pumb) {
    change_state(IN_PUMB, true); 
    in_pumb_by_moisture = true;
  }
  else if(in_moisture >= IN_MOISTURE_MIN && in_pumb_by_moisture){
     change_state(IN_PUMB, false); 
    in_pumb_by_moisture = false;
  }
  
  if(out_moisture < OUT_MOISTURE_MIN && !land_pumb) {
    change_state(LAND_PUMB, true); 
     out_pumb_by_moisture = true;
  }
  
  else if(out_moisture >= OUT_MOISTURE_MIN && out_pumb_by_moisture){
     change_state(LAND_PUMB, false); 
    out_pumb_by_moisture = false;
  }
}
