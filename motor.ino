// arah kanan = 0
void motor_yaw(bool arah, uint8_t pwm){
  analogWrite(pin_pwm_yaw, pwm);
  switch(arah){
    case 0:
      digitalWrite(pin_motor_a_yaw, HIGH);
      digitalWrite(pin_motor_b_yaw, LOW);
      break;
    case 1:
      digitalWrite(pin_motor_a_yaw, LOW);
      digitalWrite(pin_motor_b_yaw, HIGH);
      break;
  }
}

void motor_pitch(bool arah, uint8_t pwm){
  analogWrite(pin_pwm_pitch, pwm);
  switch(arah){
    case 0:
      digitalWrite(pin_motor_a_pitch, HIGH);
      digitalWrite(pin_motor_b_pitch, LOW);


      break;
    case 1:

      digitalWrite(pin_motor_a_pitch, LOW);
      digitalWrite(pin_motor_b_pitch, HIGH);


      break;
  }
}
