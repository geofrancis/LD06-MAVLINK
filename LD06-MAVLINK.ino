
#include "mavlink/common/mavlink.h"  // Mavlink interface
#include "mavlink/common/mavlink_msg_obstacle_distance.h"
#include "mavlink/common/mavlink_msg_rc_channels.h"
#include "mavlink/common/mavlink_msg_servo_output_raw.h"
#include "mavlink/common/mavlink_msg_rc_channels_override.h"
#include "mavlink/common/mavlink_msg_statustext.h"
#include "mavlink/ardupilotmega/mavlink_msg_rangefinder.h"





unsigned long previousMillis = 0;
const long interval = 1000;

int lidarAngle = 0;
int messageAngle = 0;
uint16_t distances[72];
int target = 0;
unsigned char data_buffer[4] = { 0 };
int adjusted = 0;
int distance = 0;
int range = 0;
unsigned char CS;
uint8_t Index;
byte received;
char serial_buffer[15];

int steering = 1500;
int slide = 100;
int minturn =1000;
int maxturn =50;

int servo15;
int servo16;

float roll;
float pitch;

#include "ld06.h"
LD06 ld06(Serial1);  

void setup() {

  Serial.begin(115200);   // Start the Serial you want to display data
  ld06.init();            // Init Serial Lidar to 230400 Bauds and set lidar pwm pin mode if pwm pin is specified
  Serial2.begin(115200);  // 8,9
  request_datastream();
}

void loop() {
  MAP_MAVLINK();
 
  }


void setup1() {}


void loop1() {
    MAVLINK_HB();
    
    MavLink_receive();
  if (ld06.isNewScan()) {
    MAVLINK_PROX();


     SLIDE();
     WALL();
  }
}