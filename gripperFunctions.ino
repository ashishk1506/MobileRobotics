////SERVO
void gripper_open(int angle){
  while(angle--){
    pos = (pos-1);
    myservo.write(pos);
    delay(5);
  }
  Serial.print("Opening"); Serial.println(pos);
}
void gripper_close(int angle){
    while(angle--){
    servo_initial = (servo_initial+1);
    myservo.write(pos);
    delay(5);
  }
  Serial.print("Closing"); Serial.println(pos);
}

//GRIPPER
void lift_up(){
  digitalWrite(motor_c_p1, HIGH);
  digitalWrite(motor_c_p2, LOW);
  green_led_glow();
}
void lift_down(){
  digitalWrite(motor_c_p1, LOW);
  digitalWrite(motor_c_p2, HIGH);
  green_led_glow();
}
void lift_stop(){
  digitalWrite(motor_c_p1, LOW);
  digitalWrite(motor_c_p2, LOW);
  green_led_glow();
}
