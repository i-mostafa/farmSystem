#include <Wire.h> 
#include <WiFi.h>
#include <HTTPClient.h> 

#define ULTRA_SONIC_TRIGGER 26 //3 
#define ULTRA_SONIC_ECHO 27 //4

#define FLAME_SENSOR 14 //5

#define WATER_LEVEL_SIGNAL 34 //A0
#define WATER_LEVEL_POWER 12 //6


#define OUT_MOISTURE 35 //A1
#define IN_MOISTURE 33 //A2


#define IN_TEMP_SENSOR 32 //A3
#define OUT_TEMP_SENSOR 25 //A4

#define FIRE_PUMB 13 //7
#define LAND_PUMB 15 //8
#define IN_PUMB 2 //9
#define FANS 16 //10



#define SENSOR_MIN   0     // sensor minimum
#define SENSOR_MAX  1024   // sensor maximum

#define FLAME_MAX  5

#define TANK_HEIGHT 20

#define RAIN_MIDDLE 200

#define MAX_IN_TEMP 70

#define TIMER_PERIOD   20

#define TIMER_IRR   5

#define TIMERS_SHIFT   10

#define IN_MOISTURE_MIN 200

#define OUT_MOISTURE_MIN 200

#define TEMP_THRESHOLD 5

  /*
  init serial  => done
  init ultrasonic => done
  init flam sensor  => done
  init water level => done
  init lm35 =>done
  init moiture sensor => done
  init fans and bumbs 
  init rtc =>done
  */

const char* ssid = "SOULY";
const char* password =  "souly@1200757557";

float tank_level, out_moisture, in_moisture, out_temp, in_temp;
bool flame, rain, land_pumb, in_pumb, in_pumb_by_moisture, out_pumb_by_moisture; 
long land_pumb_timer = 0;
long in_pumb_timer = 0;


void setup() {
 init_serial(); 
 init_mailer();
 init_ultrasonic();
 init_flame();
 init_water_level();
 init_relay();
}

void loop() {
  run_program();

}
