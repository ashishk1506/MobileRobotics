
#include "botDefines.h"

void Left_ISR_front()
{
     left_count_front++;
//     Serial.println(left_count_front);
}
void Right_ISR_front()
{
     right_count_front++;
//     delay(1);
//     Serial.print("right");Serial.println(right_count_front);
}


void setup() {

   
    Serial.begin(9600);
    Serial.println("Serial Monitor..");
  //MPU 6050
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
    
  //MOTOR
    pinMode(motor_a_en, OUTPUT);
    pinMode(motor_b_en, OUTPUT);
    pinMode(motor_a_p1, OUTPUT);
    pinMode(motor_a_p2, OUTPUT);
    pinMode(motor_b_p1, OUTPUT);
    pinMode(motor_b_p2, OUTPUT);
    pinMode(motor_c_p1, OUTPUT);
    pinMode(motor_c_p2, OUTPUT);
    
  // ultrasonic
    pinMode(frontTriggerPin, OUTPUT);
    pinMode(frontEchoPin, INPUT);
    pinMode(leftTriggerPin, OUTPUT);
    pinMode(leftEchoPin, INPUT);
    pinMode(rightTriggerPin, OUTPUT);
    pinMode(rightEchoPin, INPUT);
    pinMode(liftTriggerPin, OUTPUT);
    pinMode(liftEchoPin, INPUT);
   
   //INFRARED
    pinMode(ir0, INPUT);
    pinMode(ir1, INPUT);
    pinMode(ir2, INPUT);
    pinMode(ir3, INPUT);
    pinMode(ir4, INPUT);

    
 //ENCODER
    pinMode(encoder_a_front, INPUT_PULLUP);
//    pinMode(encoder_b_front, INPUT_PULLUP);
    attachInterrupt( digitalPinToInterrupt(encoder_a_front),Left_ISR_front, RISING);
    //attachInterrupt( digitalPinToInterrupt(encoder_b_front),Right_ISR_front, RISING);

 //SERVO
    myservo.attach(9);
    
}

int bot_status = 1;

void loop() {

         //CUBE A  RED
         move_distance_forward(130);
         delay(1000);
         rotate_left_angle(180);
         delay(1000);
         pick_cube(RACK_A);
         rotate_left_angle(180);
         move_distance_forward(80);
         rotate_right_angle(175);
         move_distance_forward(10);
         deliver_cube();
//
//         //CUBE B BLUE
         rotate_right_angle(180);
         move_distance_forward(80);
         rotate_left_angle(180);
         delay(1000);
         pick_cube(RACK_B);
         rotate_left_angle(170);
         move_distance_forward(170);
         rotate_right_angle(180);
         move_distance_forward(85);
         deliver_cube();

         delay(5000);
//
//         rotate_right_angle(180);
//         move_distance_forward(60);
//         pick_cube(RACK_B);

         
         
//         delay(5000);
//          delay(2000);
//          lift_stop();

 }
