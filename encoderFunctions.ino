int bot_distance(){
    int d = left_count_front+right_count_front;
    d = d/2;
    int distance = 6.282*radius*(d);
        distance /= ticks;
    Serial.print("distance"); Serial.println(distance);
    return distance;
}


int cal_left_front_distance()
{
     left_front_distance = 6.282*radius*(left_count_front);
     left_front_distance /= ticks;
     Serial.print("left_front");Serial.println(left_front_distance);
     return left_front_distance;
}

int cal_right_front_distance()
{
     right_front_distance = 6.282*radius*(right_count_front);
     right_front_distance /= ticks;
     Serial.print("right_front");Serial.println(right_front_distance);
     return right_front_distance;
}


      
//     left_count = 0; right_count = 0;
//     bot_stop();
//     while(cal_left_distance()<= x && cal_right_distance()<=x){
//          bot_forward(bot_speed);
//          Serial.println("moving bot forward");
//     }
//     bot_stop();
//     while(cal_right_distance()<=x){
//          cal_left_distance();
//          motor_b_forward(bot_speed);
//          Serial.println("moving B");
//     }
//     bot_stop();
//     while(cal_left_distance()<=x){
//          cal_right_distance();
//          motor_a_forward(bot_speed);
//          Serial.println("moving A");
//     }
//     bot_stop();
