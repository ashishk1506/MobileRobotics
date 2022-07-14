float calFrontDistance() {
  digitalWrite(frontTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(frontTriggerPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(frontTriggerPin, LOW);
  float frontDuration = pulseIn(frontEchoPin, HIGH);  
  frontDistance = frontDuration * 10 / 292 / 2;  
  Serial.print(" Front Distance: ");
  Serial.print(frontDistance);
  Serial.println(" cm  ");
return frontDistance;
}

float calLeftDistance() {
  digitalWrite(leftTriggerPin, LOW);
  delayMicroseconds(4);
  digitalWrite(leftTriggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(leftTriggerPin, LOW);
  float leftDuration = pulseIn(leftEchoPin, HIGH);  
  leftDistance = leftDuration * 10 / 292 / 2;  
  Serial.print("Left distance: ");
  Serial.print(leftDistance);
  Serial.println(" cm  ");
return leftDistance;
}

float calRightDistance() {
  digitalWrite(rightTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(rightTriggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(rightTriggerPin, LOW);
  float rightDuration = pulseIn(rightEchoPin, HIGH);  
  rightDistance = rightDuration * 10 / 292 / 2; 
  Serial.print("Right distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm  ");
return rightDistance;
}


float calLiftDistance() {
  digitalWrite(liftTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(liftTriggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(liftTriggerPin, LOW);
  float liftDuration = pulseIn(liftEchoPin, HIGH);  
  liftDistance = (liftDuration * 10 / 292 / 2) - lift_distance_error; 
  Serial.print("Lift Height: ");
  Serial.print(liftDistance);
  Serial.println(" cm  ");
return liftDistance;
}

void debug_sensors()
{
//  calLeftDistance();
  calFrontDistance();
//  calRightDistance();
  calLiftDistance();
  Serial.println(" " );
  delay(2000);
}
