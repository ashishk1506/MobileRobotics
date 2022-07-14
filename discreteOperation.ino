void move_distance_forward(int x)
{   
      x = x*cm_to_ticks;
      left_count_front = 0, right_count_front = 0;
      bot_stop();
      Serial.print("moving distnace");
      int max_right = mpu6050.getAngleZ()+ deviation;
      int max_left = mpu6050.getAngleZ() - deviation;
      analogWrite(motor_a_en, motor_a_speed);  
      analogWrite(motor_b_en, motor_b_speed); 
      green_led_glow();
      while(left_count_front<=x){
           mpu6050.update();
           while(mpu6050.getAngleZ()>max_right){
              digitalWrite(motor_a_p1, LOW);
              digitalWrite(motor_a_p2, HIGH);
              digitalWrite(motor_b_p1, HIGH);
              digitalWrite(motor_b_p2, LOW);
              Serial.println("left");
              delay(5);
              mpu6050.update();
          }
          while(mpu6050.getAngleZ()<max_left){
              digitalWrite(motor_a_p1, HIGH);
              digitalWrite(motor_a_p2, LOW);
              digitalWrite(motor_b_p1, LOW);
              digitalWrite(motor_b_p2, HIGH);
              Serial.println("right");
              delay(5);
              mpu6050.update();
          }
          digitalWrite(motor_b_p1, HIGH);
          digitalWrite(motor_b_p2, LOW);
          digitalWrite(motor_a_p1, HIGH);
          digitalWrite(motor_a_p2, LOW);
          Serial.println("forward");
          
      }
      Serial.print("moved"); Serial.println(x);
      bot_stop();

//        while(left_count_front<=x && right_count_front<=x){
//          analogWrite(motor_a_en, motor_a_speed);  
//          analogWrite(motor_b_en, motor_b_speed);  
//      }
//      Serial.println("1st stop");
//      Serial.println(left_count_front);
//      Serial.println(right_count_front);
//          analogWrite(motor_a_en, 0);  
//          analogWrite(motor_b_en, 0); 
//      while(left_count_front<=x){
//          analogWrite(motor_a_en, motor_a_speed);  
//      }
//           
//      Serial.println("2nd stop");
//      Serial.println(left_count_front);
//      Serial.println(right_count_front);
//          analogWrite(motor_a_en, 0);  
//      while(right_count_front<=x){
//          analogWrite(motor_b_en, motor_b_speed);  
//      }
//          analogWrite(motor_b_en, 0);  
//      Serial.println("bot_stopped");
//      Serial.println(left_count_front);
//      Serial.println(right_count_front);
//      bot_stop();
      
}


void move_distance_backward(int x)
{   
      x = x*cm_to_ticks;
      left_count_front = 0, right_count_front = 0;
      bot_stop();
      Serial.print("moving distnace");
      int max_right = mpu6050.getAngleZ()+ deviation;
      int max_left = mpu6050.getAngleZ() - deviation;
      analogWrite(motor_a_en, motor_a_speed);  
      analogWrite(motor_b_en, motor_b_speed); 
      green_led_glow();
      while(left_count_front<=x){
           mpu6050.update();
           while(mpu6050.getAngleZ()>max_right){
              digitalWrite(motor_a_p1, LOW);
              digitalWrite(motor_a_p2, HIGH);
              digitalWrite(motor_b_p1, HIGH);
              digitalWrite(motor_b_p2, LOW);
              Serial.println("right");
              delay(5);
              mpu6050.update();
          }
          while(mpu6050.getAngleZ()<max_left){
              digitalWrite(motor_a_p1, HIGH);
              digitalWrite(motor_a_p2, LOW);
              digitalWrite(motor_b_p1, LOW);
              digitalWrite(motor_b_p2, HIGH);
              Serial.println("left");
              delay(5);
              mpu6050.update();
          }
          digitalWrite(motor_b_p1, LOW);
          digitalWrite(motor_b_p2, HIGH);
          digitalWrite(motor_a_p1, LOW);
          digitalWrite(motor_a_p2, HIGH);
          Serial.println("forward"); 
      }
      
      bot_stop();
  
//      left_count_front = 0, right_count_front = 0;
//      bot_stop();
//      digitalWrite(motor_b_p1, LOW);
//      digitalWrite(motor_b_p2, HIGH);
//      digitalWrite(motor_a_p1, LOW);
//      digitalWrite(motor_a_p2, HIGH);
//      while(left_count_front<=x && right_count_front<=x){
//          analogWrite(motor_a_en, motor_a_speed);  
//          analogWrite(motor_b_en, motor_b_speed);  
//      }
//      Serial.println("1st stop");
//      Serial.println(left_count_front);
//      Serial.println(right_count_front);
//          analogWrite(motor_a_en, 0);  
//          analogWrite(motor_b_en, 0); 
//      while(left_count_front<=x){
//          analogWrite(motor_a_en, motor_a_speed);  
//      }
//           
//      Serial.println("2nd stop");
//      Serial.println(left_count_front);
//      Serial.println(right_count_front);
//          analogWrite(motor_a_en, 0);  
//      while(right_count_front<=x){
//          analogWrite(motor_b_en, motor_b_speed);  
//      }
//          analogWrite(motor_b_en, 0);  
//      Serial.println("bot_stopped");
//      Serial.println(left_count_front);
//      Serial.println(right_count_front);
//      bot_stop();
}


void rotate_right_angle(int angle){
    mpu6050.update();
    int initial = mpu6050.getAngleZ()-error_angle;
    Serial.print("initial");Serial.println(initial);
    analogWrite(motor_a_en, 255);  
    analogWrite(motor_b_en, 255); 
    green_led_glow();
    while((mpu6050.getAngleZ()-initial)<angle){
           digitalWrite(motor_a_p1, HIGH);
           digitalWrite(motor_a_p2, LOW);
           digitalWrite(motor_b_p1, LOW);
           digitalWrite(motor_b_p2, HIGH);
           mpu6050.update();
           Serial.println(mpu6050.getAngleZ()-initial);
    }
    Serial.println("bot_stop");
    Serial.println(mpu6050.getAngleZ()-initial);
    bot_stop();
}

void rotate_left_angle(int angle){
    mpu6050.update();
    int initial = mpu6050.getAngleZ()+error_angle;
    Serial.print("initial");Serial.println(initial);
    analogWrite(motor_a_en, 255);  
    analogWrite(motor_b_en, 255); 
    green_led_glow();
    while(initial-(mpu6050.getAngleZ())<angle){
           digitalWrite(motor_a_p1, LOW);
           digitalWrite(motor_a_p2, HIGH);
           digitalWrite(motor_b_p1, HIGH);
           digitalWrite(motor_b_p2, LOW);
           mpu6050.update();
           Serial.println(mpu6050.getAngleZ()-initial);
    }
    Serial.println("bot_stop");
    Serial.println(mpu6050.getAngleZ()-initial);
    bot_stop();
}

void ramp_follower(){
      bot_stop();
      analogWrite(motor_a_en, 255);  
      analogWrite(motor_b_en, 255);
      green_led_glow();
      while(calLeftDistance() < maxLeftDistance && calRightDistance() < maxRightDistance){
              
            if(mpu6050.getGyroAngleX() > gyro_x_max){
               analogWrite(motor_a_en, 255);  
               analogWrite(motor_b_en, 255);
            }else if(mpu6050.getGyroAngleX() < gyro_x_min){
               analogWrite(motor_a_en, 100);  
               analogWrite(motor_b_en, 100);
            }else{
               analogWrite(motor_a_en, 150);  
               analogWrite(motor_b_en, 150);
            }
            if(calLeftDistance() < maxLeftPadding){
                 digitalWrite(motor_a_p1, HIGH);
                 digitalWrite(motor_a_p2, LOW);
                 digitalWrite(motor_b_p1, LOW);
                 digitalWrite(motor_b_p2, HIGH);
                 Serial.println("right");
                 Serial.println("bot_right");
                 delay(100);
//                 bot_stop();
                 bot_forward(150, 150);
            }else if( calRightDistance()<maxRightPadding){
                 //bot_left(turn_speed);
                 digitalWrite(motor_a_p1, LOW);
                 digitalWrite(motor_a_p2, HIGH);
                 digitalWrite(motor_b_p1, HIGH);
                 digitalWrite(motor_b_p2, LOW);
                 Serial.println("left");
                 Serial.println("bot_left");
                 delay(110);
//                 bot_stop();
                 bot_forward(150, 150);
            }else{
//                bot_forward(bot_speed);
                digitalWrite(motor_b_p1, HIGH);
                digitalWrite(motor_b_p2, LOW);
                digitalWrite(motor_a_p1, HIGH);
                digitalWrite(motor_a_p2, LOW);
                Serial.println("bot_forward");
            }
      }
      //bot_stop();
          red_led_glow();
          for(int i=140; i>=0; i--){
             analogWrite(motor_a_en, i);  
             analogWrite(motor_b_en, i); 
             delay(1);
          }
          bot_stop();
          Serial.println("bot_stop");
}

void pick_cube(float x){
      
      //adjust lift height
      lift_stop();
      while(calLiftDistance()> x){
           lift_down();
           Serial.println("lift down");
      }
      lift_stop();
      while(calLiftDistance()< x){
           lift_up();
           Serial.println("lift up");
      }
      lift_stop();
      delay(500);
  
      //adjust gripper
      myservo.write(servo_max); 
      
  
      //move towards cube
      move_distance_forward(black_to_cube);
      Serial.println("towards cube");
      delay(500);
  
      //grab cube
       myservo.write(servo_min);
  
      //move object slighly up
//      while(calLiftDistance()< x+1){
//           lift_up();
//            Serial.println("lift sslight up");
//      }
//      lift_stop();
      delay(500);
      
      //move away from cube
      move_distance_backward(cube_to_black);
      bot_stop();
       
}

void deliver_cube(){
      //adjust lift height
      lift_stop();
      while(calLiftDistance()> min_base_height){
           lift_down();
           Serial.println("lift down");
      }
      lift_stop();
      while(calLiftDistance()< min_base_height){
           lift_up();
           Serial.println("lift up");
      }
      lift_stop();
      delay(500);
      
      //move towards rack
      move_distance_forward(black_to_cube);
//      Serial.println("towards cube");
      delay(500);

      //gripper open
      myservo.write(servo_initial); 
      
      //gripper_close
      delay(500);
      //move away from cube
      move_distance_backward(cube_to_black);
      bot_stop();
   
}


void detect_cube(){
      //adjust lift height
      lift_stop();
      while(calLiftDistance()> RACK_A){
           lift_down();
           Serial.println("lift down");
      }
      lift_stop();
      while(calLiftDistance()< RACK_A){
           lift_up();
           Serial.println("lift up");
      }
      lift_stop();  //LEVEL A
      if((wood_distance < calFrontDistance()) && (calFrontDistance() < back_wall)){
           Serial.println("Objcet detected A");
           green_led_glow();
           pick_cube(RACK_A);
           led_fade();
           return;
      }
      while(calLiftDistance()< RACK_B){
           lift_up();
           Serial.println("lift up");
      }
      lift_stop(); //LEVEL B
      if((wood_distance < calFrontDistance()) && (calFrontDistance() < back_wall)){
           Serial.println("Objcet detected B");
           green_led_glow();
           pick_cube(RACK_B);
           led_fade();
           return;
      }
       while(calLiftDistance()< RACK_C){
           lift_up();
           Serial.println("lift up");
      }
      lift_stop(); //LEVEL C
      if((wood_distance < calFrontDistance()) && (calFrontDistance() < back_wall)){
           Serial.println("Objcet detected B");
           green_led_glow();
           pick_cube(RACK_C);
           led_fade();
           return;
      }
    
}
