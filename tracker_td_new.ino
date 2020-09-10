#include <Wire.h>
#include <LSM303.h>

LSM303 compass;

/* PID */
#define KP_YAW 2
//#define KI_YAW 0.2
#define KD_YAW 2
float KI_yaw = 0;

#define KP_PITCH 1.8

//#define KI_PITCH 0
#define KD_PITCH 1
float KI_pitch = 0;

// yaw
//uint8_t pwm_out_yaw = 0;
float last_error = 0;
float nilai_P = 0;
float nilai_I = 0;
float nilai_D = 0;
float setPoint_yaw = 1;
bool dir_yaw = 0;
//pitch
//uint8_t pwm_out_pitch = 0;
float last_nilai = 0;
float pitch_P = 0;
float pitch_I = 0;
float pitch_D = 0;
float setPoint_pitch = 0;
bool dir_pitch = 0;

/* Konfigurasi pin motor shield */
#define pin_motor_a_pitch 4
#define pin_motor_b_pitch 5
#define pin_pwm_pitch 6
#define pin_motor_a_yaw 8
#define pin_motor_b_yaw 9
#define pin_pwm_yaw 10

float error = 0, nilai = 0;
void setup(void) 
{
  Serial.begin(115200);
//  Serial.setTimeout(100);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){-512, -407, -270};
  compass.m_max = (LSM303::vector<int16_t>){+446, +376, +671};

  /* inisialisasi motor */
  pinMode(pin_motor_a_pitch, OUTPUT);
  pinMode(pin_motor_b_pitch, OUTPUT);
  pinMode(pin_pwm_pitch, OUTPUT);
  pinMode(pin_motor_a_yaw, OUTPUT);
  pinMode(pin_motor_b_yaw, OUTPUT);
  pinMode(pin_pwm_yaw, OUTPUT);

  nilai = setPoint_pitch - baca_potensio();
}

unsigned long lastmicros = 0, lastmill = 0;
float dataHeading=0,dataPitch = 0;
void loop(void) 
{
  compass.read();
  dataHeading = compass.heading();
  dataPitch = baca_potensio();
  if(dataHeading == 0.0f) {
    Serial.println("INVALID"); return;
  }
  error = setPoint_yaw - dataHeading;
  nilai = setPoint_pitch - dataPitch;
  baca_input();
  if(micros() - lastmicros > 16){
    lastmicros = micros();
  proses_pid_yaw();
  proses_pid_pitch();
  }

  if(millis() - lastmill > 80){
    lastmill = millis();
    output_data_toSerial(dataPitch, dataHeading);
  }
  
//  Serial.println((String) "setpoint pitch: " + setPoint_pitch + ", setpoint yaw: " + setPoint_yaw);
//  Serial.println((String) "real pitch: " + 0 + ", real yaw: " + baca_heading());
//  delay(200);
}

void output_data_toSerial(float pitch, float yaw){
  Serial.println(String(pitch)+","+String(yaw));
}

