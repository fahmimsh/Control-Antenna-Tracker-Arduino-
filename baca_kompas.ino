#define Pi PI
float baca_heading(){
  /* Get a new sensor event */ 
  compass.read();
//  
//  // Calculate the angle of the vector y,x
//  float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
//  
//  // Normalize to 0-360
//  if (heading < 0)
//  {
//    heading = 360 + heading;
//  }
//  return heading;
  return compass.heading();
}

float baca_potensio() {
//  return analogRead(A0);
  int analog = analogRead(A0);
  if(analog > 670) analog = 670;
  return analog*(180.0f/670.0f);
}
