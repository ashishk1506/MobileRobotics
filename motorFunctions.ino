//BOT FORWARD
void bot_forward(int motor_a_speed, int motor_b_speed){
  motor_a_forward(motor_a_speed);
  motor_b_forward(motor_b_speed);
  green_led_glow();
}
//BOT BACKWARD
void bot_backward(int motor_a_speed, int motor_b_speed){
  motor_a_backward(motor_a_speed);
  motor_b_backward(motor_b_speed);
  green_led_glow();
}
//BOT LEFT
void bot_left(int motor_a_speed, int motor_b_speed){
  motor_a_backward(motor_a_speed);
  motor_b_forward(motor_b_speed);
  green_led_glow();
}
//BOT RIGHT
void bot_right(int motor_a_speed, int motor_b_speed){
  motor_a_forward(motor_a_speed);
  motor_b_backward(motor_b_speed);
  green_led_glow();
}
//BOT STOP
void bot_stop(){
  digitalWrite(motor_a_p1,LOW);
  digitalWrite(motor_a_p2,LOW);
  digitalWrite(motor_b_p1,LOW);
  digitalWrite(motor_b_p2,LOW);
  red_led_glow();
}
//BOT COMPLETE ROTATION
void bot_complete_rotation(int motor_a_speed, int motor_b_speed){
  motor_a_forward(motor_a_speed);
  motor_b_backward(motor_b_speed);
  green_led_glow();
}

//BOT SMOOTH FORWARD
void bot_forward_smooth(int motor_a_speed, int motor_b_speed){ 
  digitalWrite(motor_a_p1, HIGH);
  digitalWrite(motor_a_p2, LOW); 
  digitalWrite(motor_b_p1, HIGH);
  digitalWrite(motor_b_p2, LOW);
  green_led_glow();
  for(int i=0; i<= motor_a_speed; i=i+1)
  {
     analogWrite(motor_a_en, i);  
     analogWrite(motor_b_en, i); 
     delay(1);
  }
  analogWrite(motor_a_en, motor_a_speed);  
  analogWrite(motor_b_en, motor_b_speed); 
}
//BOT SMOOTH BACKWARD
void bot_backward_smooth(int motor_a_speed, int motor_b_speed){ 
  digitalWrite(motor_a_p1, LOW);
  digitalWrite(motor_a_p2, HIGH);
  digitalWrite(motor_b_p1, LOW);
  digitalWrite(motor_b_p2, HIGH);
  green_led_glow();
  for(int i=0; i<= motor_a_speed; i=i+1)
  {
     analogWrite(motor_a_en, i);  
     analogWrite(motor_b_en, i); 
     delay(1);
  }
  analogWrite(motor_a_en, motor_a_speed);  
  analogWrite(motor_b_en, motor_b_speed);
}
//BOT SMOOTH LEFT
void bot_left_smooth(int motor_a_speed, int motor_b_speed){ 
  digitalWrite(motor_a_p1, LOW);
  digitalWrite(motor_a_p2, HIGH);
  digitalWrite(motor_b_p1, HIGH);
  digitalWrite(motor_b_p2, LOW);
  green_led_glow();
  for(int i=0; i<= motor_a_speed; i=i+1)
  {
     analogWrite(motor_b_en, i);  
     analogWrite(motor_a_en, i);  
     delay(1);
  }
  analogWrite(motor_b_en, motor_b_speed);  
  analogWrite(motor_a_en, motor_a_speed); 
}
//BOT SMOOTH RIGHT
void bot_right_smooth(int motor_a_speed, int motor_b_speed){
  digitalWrite(motor_a_p1, HIGH);
  digitalWrite(motor_a_p2, LOW);
  digitalWrite(motor_b_p1, LOW);
  digitalWrite(motor_b_p2, HIGH);
  green_led_glow();
  for(int i=0; i<=motor_a_speed; i=i+1)
  {
     analogWrite(motor_b_en, i);  
     analogWrite(motor_a_en, i);  
     delay(1);
  }
   analogWrite(motor_b_en, motor_b_speed);  
   analogWrite(motor_a_en, motor_a_speed); 
}
//BOT SMOOTH STOP
void bot_stop_smooth(int motor_a_speed, int motor_b_speed){
   red_led_glow();
  for(int i=motor_a_speed; i>=0; i--){
     analogWrite(motor_a_en, i);  
     analogWrite(motor_b_en, i); 
     delay(1);
  }
  digitalWrite(motor_a_p1,LOW);
  digitalWrite(motor_a_p2,LOW);
  digitalWrite(motor_b_p1,LOW);
  digitalWrite(motor_b_p2,LOW);
}


//MOTOR A 
void motor_a_forward(int motor_a_speed){
  analogWrite(motor_a_en, motor_a_speed);  
  digitalWrite(motor_a_p1, HIGH);
  digitalWrite(motor_a_p2, LOW);
}
void motor_a_backward(int motor_a_speed){
  analogWrite(motor_a_en, motor_a_speed);  
  digitalWrite(motor_a_p1, LOW);
  digitalWrite(motor_a_p2, HIGH);
}
//MOTOR B
void motor_b_forward(int motor_b_speed){
  analogWrite(motor_b_en, motor_b_speed);  
  digitalWrite(motor_b_p1, HIGH);
  digitalWrite(motor_b_p2, LOW);
}
void motor_b_backward(int motor_b_speed){
  analogWrite(motor_b_en, motor_b_speed);
  digitalWrite(motor_b_p1, LOW);
  digitalWrite(motor_b_p2, HIGH);
}


//LED
void green_led_glow(){
  digitalWrite(green_led, HIGH);
  digitalWrite(red_led, LOW);
}
void red_led_glow(){
  digitalWrite(green_led, LOW);
  digitalWrite(red_led, HIGH);
}
void led_fade(){
  digitalWrite(green_led, LOW);
  digitalWrite(red_led, LOW);
}
