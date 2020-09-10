void baca_input(){
  if(Serial.available() > 0){
    String data = Serial.readStringUntil('\n');

    int indexComma = data.indexOf(',');
    setPoint_pitch = data.substring(0, indexComma).toFloat();
    setPoint_yaw = data.substring(indexComma + 1).toFloat();

    if(setPoint_pitch > 90) setPoint_pitch = 90;
    if(setPoint_pitch < 0) setPoint_pitch = 0;
    if(setPoint_yaw > 359) setPoint_yaw = 359;
    if(setPoint_yaw < 1) setPoint_yaw = 1;
  }
}
