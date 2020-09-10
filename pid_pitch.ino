void proses_pid_pitch(){
  
  byte maxPitchSpeed = 200;
  if(nilai < 0){
    dir_pitch = 0; //turun
    maxPitchSpeed = 150;
  } else {
    dir_pitch =1; //naik
  }

  pitch_P = KP_PITCH * nilai;
//  float selisih_error = error - last_error;
  pitch_D = KD_PITCH * (nilai - last_nilai);
  pitch_I += (KI_pitch * nilai);
  
  if(-8.0f < nilai && nilai < 8.0f){
    if(pitch_I > 65) pitch_I = 60;
    else if(pitch_I < -65) pitch_I = -60;
    KI_pitch = 0.1;
  }
  else {
    KI_pitch = 0.2;
  }
  int16_t total_PID = pitch_P + pitch_I + pitch_D;

  if(total_PID < 0) total_PID *= -1;
  if(total_PID > maxPitchSpeed) total_PID = maxPitchSpeed;
  
  if(nilai == 0) total_PID = 0;
  
//  Serial.println("\tPIT: "+String(setPoint_pitch)
//                +"  Pot:"+  String(baca_potensio())
//                +"\tEr:"+String(nilai)
//                +"  P:"+String(pitch_P)
//                +"  I:"+String(pitch_I)
//                +"  D:"+String(pitch_D)
//                +"\tPWM:"+String(total_PID)+'\t'+String(dir_pitch));

  motor_pitch(dir_pitch, total_PID);

  last_nilai = nilai;
























  
//  if(nilai < 0){
//    dir_pitch = 0; // naik
//  } else if(nilai > 0) {
//    dir_pitch = 1; // turun
//  } else {
//    return;
//  }
//
//  errorP_pitch = abs(nilai);
//  if(errorP_pitch < 0) return;
//  
//  if(dir_pitch == 0)
//    errorI_pitch += errorP_pitch;
//  else
//    errorI_pitch -= errorP_pitch;
//  errorD_pitch = errorP_pitch - lastErrorD_pitch;
//
//  pwm_out_pitch = (KP_PITCH * errorP_pitch + KI_PITCH * errorI_pitch + KD_PITCH * errorD_pitch);
//  pwm_out_pitch = constrain(pwm_out_pitch, -255, 255);
//  pwm_out_pitch = abs(pwm_out_pitch);
//  if(pwm_out_pitch > 150) pwm_out_pitch = 150;
//                //                 set telemetri       potensio feedback    (      P              I                D         )              PWM O            
////  Serial.print("pitch : "+(String) setPoint_pitch+'\t'+baca_potensio()+"   PID: "+errorP_pitch+'\t'+errorI_pitch+'\t'+errorD_pitch+"\tOUT :"+pwm_out_pitch+"    "+dir_pitch);
//  motor_pitch(dir_pitch, pwm_out_pitch);
//  lastErrorD_pitch = errorD_pitch;
}
