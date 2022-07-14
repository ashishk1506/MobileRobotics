
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>

MPU6050 mpu6050(Wire);
Servo myservo;


int mode = 0;
# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2

#define RACK_A 7.5
#define RACK_B 22
#define RACK_C 30

const int frontEchoPin = 42;
const int frontTriggerPin = 43;
const int liftEchoPin = 44;
const int liftTriggerPin = 45;
const int leftEchoPin = 46;
const int leftTriggerPin = 47;
const int rightEchoPin = 48;
const int rightTriggerPin = 49;

const int ir0 = 36;
const int ir1 = 37;
const int ir2 = 38;
const int ir3 = 39;
const int ir4 = 40;

const int motor_a_p1 = 24;
const int motor_a_p2 = 22;
const int motor_a_en = 13;

const int motor_b_p1 = 26;
const int motor_b_p2 = 28;
const int motor_b_en = 12;

int motor_c_p1 = 51;
int motor_c_p2 = 50;

int encoder_a_front = 2;
int encoder_b_front = 3;

int red_led = 52;
int green_led = 53;

void bot_forward(int);
void bot_backward(int);
void bot_left(int);
void bot_right(int);
void bot_stop();
int bot_distance();
void motor_a_forward(int);
void motor_b_forward(int);
void motor_a_backward(int);
void motor_b_backward(int);
float calLiftDistance();
float calLeftDistance();
float calRightDistance();
void rotate_right_angle(int);
void rotate_left_angle(int);
void gripper_open(int);
void gripper_close(int);
void lift_up();
void lift_down();
void lift_stop();
void pick_cube(float);
void deliver_cube();
void detect_cube();

// ULTRASONIC
volatile float maxFrontDistance = 27.00, maxLeftDistance = 50.00, maxRightDistance = 50.00, maxLeftPadding = 10, maxRightPadding = 10;
volatile float frontDistance, leftDistance, rightDistance, liftDistance;
float wood_distance  = 3, back_wall = 13;  //distnace b/w cube and front ultrasonic sensor

//ENCODER  // 1CM = 6 TICKS
int bot_speed = 220;
volatile int left_count_front = 0, right_count_front = 0;
float radius = 3.5;
float left_front_distance = 0.00, right_front_distance = 0.00;
int ticks = 140, cm_to_ticks = 6;

//IR
int sensor_data[5] = {0,0,0,0,0};
int multiplier = 10;
int error = 0;

//MOTOR SPEED
int motor_a_speed = 215;  //215;
int motor_b_speed = 230; //230;
int turn_speed = 210;

//MPU
int error_angle = 10;  //error in MPU left/right turn
int deviation = 2;    //left and right deviation during forward backward motion forward/backward motion
int gyro_x_max = 2 , gyro_x_min = -2;

//LIFT
int min_base_height = 9.5;          //distnace of centre of cube from ground (grip at centre)
int black_to_cube = 10;           //distance from black line to cube to be picked
int cube_to_black = 20;         //distance from cube to away from black line
float lift_distance_error = 1.8; //distance from ultrasonic to base of gripper

//GRIPPER
int servo_min = 145, servo_max = 95, servo_initial = 100, pos = 0;
