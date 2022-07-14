void read_sensors()
{
   sensor_data[0] = digitalRead(ir0);
   sensor_data[1] = digitalRead(ir1);
   sensor_data[2] = digitalRead(ir2);
   sensor_data[3] = digitalRead(ir3);
   sensor_data[4] = digitalRead(ir4);
   
  if(      (sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){ error = 0;  mode = FOLLOWING_LINE;}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){ error = -4; mode = FOLLOWING_LINE; Serial.println("2 : left");}
   else if((sensor_data[0]== 0 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){ error = -4; mode = FOLLOWING_LINE; Serial.println("1 : right");}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 0 )){ error = 4;  mode = FOLLOWING_LINE; Serial.println("x");}
   else if((sensor_data[0]== 0 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){ error = -4; mode = FOLLOWING_LINE; Serial.println("y");}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 1 )){ error = 4;  mode = FOLLOWING_LINE; Serial.println("z");}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 0 )){ error = 4;  mode = FOLLOWING_LINE; Serial.println("5 : right");}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 1 )){ error = 4;  mode = FOLLOWING_LINE; Serial.println("u");}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){ error = -4; mode = FOLLOWING_LINE; Serial.println("k");}
   else if((sensor_data[0]== 0 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){ error = -4; mode = FOLLOWING_LINE; Serial.println("p");}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 0 )){ error = 4;  mode = FOLLOWING_LINE; Serial.println("l");}
  
   else if((sensor_data[0]== 0 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 0 )){ error = 0; mode = NO_LINE;}
//   else if((sensor_data[0]== 0 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 0 )){ error = 0; mode = STOPPED;}
//   else if((sensor_data[0]== 0 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 1 )){ error = 0; mode = STOPPED;}
//   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 0 )&&(sensor_data[2]== 0 )&&(sensor_data[3]== 0 )&&(sensor_data[4]== 0 )){ error = 0; mode = STOPPED;}
   else if((sensor_data[0]== 1 )&&(sensor_data[1]== 1 )&&(sensor_data[2]== 1 )&&(sensor_data[3]== 1 )&&(sensor_data[4]== 1 )){  mode = STOPPED;}
   
}
