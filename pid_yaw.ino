void proses_pid_yaw(){ 
  
//  if(error == setPoint_yaw) return;
  if(dataHeading > 265 && setPoint_yaw < 95){
    error += 359;
//    error *= -1;
  }else if (dataHeading < 95 && setPoint_yaw > 265) {
    error += 359;
    error *= -1;
  }
  if(error < 0){
    dir_yaw = 1;
  } else {
    dir_yaw =0;
  }

  nilai_P = KP_YAW * error;
//  float selisih_error = error - last_error;
  nilai_D = KD_YAW * (error - last_error);
  nilai_I += (KI_yaw * error);
  
  if(-5.0f < error && error < 5.0f){
    if(nilai_I > 50) nilai_I = 48;
    else if(nilai_I < -50) nilai_I = -48;
    if(-2.0f < error && error < 2.0f) KI_yaw = 0.1;
    else(KI_yaw = 0.2);
  }
  else {
    KI_yaw = 0.3;
  }
  int16_t total_PID = nilai_P + nilai_I + nilai_D;
//  if (total_PID < 0) {
//    dir_yaw = 1;
//    total_PID *= -1;
//  } else {
//    dir_yaw = 0;
//  }

  if(total_PID < 0) total_PID *= -1;
  if(total_PID > 200) total_PID = 200;
  
  if(-1.0f < error && error < 1.0f) total_PID = 0;
//  Serial.println("\tYAW: "+String(setPoint_yaw)
//                +"  H:"+  String(baca_heading())
//                +"\tEr:"+String(error)
//                +"  P:"+String(nilai_P)
//                +"  I:"+String(nilai_I)
//                +"  D:"+String(nilai_D)
//                +"\tPWM:"+String(total_PID)+'\t'+String(dir_yaw));
  
  motor_yaw(dir_yaw, total_PID);

  last_error = error;

















  
//  if(nilai < 0 && baca_heading() < (setPoint_yaw + 180)){
//    dir_yaw = 0; // arah kanan
//    errorP_yaw = baca_heading() - setPoint_yaw;
//  }
//  else if(nilai < 0 && baca_heading() > (setPoint_yaw + 180)){
//    dir_yaw = 1; // arah kiri
//    errorP_yaw = 360 - (baca_heading() - setPoint_yaw);
//  }
//  else if(nilai > 0 && baca_heading() > (setPoint_yaw - 180)){
//    dir_yaw = 1;
//    errorP_yaw = nilai;
//  }
//  else if(nilai > 0 && baca_heading() < (setPoint_yaw - 180)){
//    dir_yaw = 0;
//    errorP_yaw = 360 - nilai;
//  }
//  else if(errorP_yaw > 180 || errorP_yaw < 0) return;
//  else return;

//  Serial.println((String) "dir: " + (dir_yaw == 0 ? "kanan" : "kiri") + ", errorP_yaw: " + errorP_yaw);

//  errorD_yaw = errorP_yaw - lastErrorD_yaw;
//  errorI_yaw = errorI_yaw + (float)((errorP_yaw+errorD_yaw) * .01);
//  if (errorI_yaw > 20) errorI_yaw = 20;
//  if (errorI_yaw < -20) errorI_yaw = -20;
//
//  pwm_out_yaw = (KP_YAW * errorP_yaw + KD_YAW * errorD_yaw + KI_YAW * errorI_yaw);
//  errorD_yaw = errorP_yaw - lastErrorD_yaw;
//  if(dir_yaw == 0)
//    errorI_yaw += errorP_yaw;
//  else
//    errorI_yaw -= errorP_yaw;
//
//  pwm_out_yaw = ((KP_YAW * errorP_yaw) + (KD_YAW * errorD_yaw) + (KI_YAW * errorI_yaw))/3;
//  if (pwm_out_yaw > 150) pwm_out_yaw = 150; // limit kecepatan motor maksimal ke 150
    //                               set telemetri        kompas feedback    (      P              I                D         )       PWM O          
//  Serial.println("  yaw : "+(String) setPoint_yaw +'\t'+  baca_heading() +'\t'+nilai+'\t'+(KP_YAW * errorP_yaw)+'\t'+(KI_YAW * errorI_yaw)+'\t'+(KD_YAW * errorD_yaw)+'\t'+pwm_out_yaw+'\t'+dir_yaw);
//  motor_yaw(dir_yaw, pwm_out_yaw);
//  lastErrorD_yaw = errorD_yaw;
}
