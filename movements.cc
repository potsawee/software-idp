#include "header.h"
using namespace std;

void go_forwards(int speed)   // from 0 (lowest) to 126 (highest)
{   rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, speed - 4); 
	rlink.command(MOTOR_3_GO, speed + 0x80);
}

void go_backwards(int speed)  // from 0 (lowest) to 126 (highest)
{   rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (speed)+0x80);
	rlink.command(MOTOR_3_GO, speed);
}

void set_motors(int v1, int v2){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, v1); 
	rlink.command(MOTOR_3_GO, v2 + 0x80);
}

void set_motors_back(int v1, int v2){	
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (v1)+0x80);
	rlink.command(MOTOR_3_GO, v2);
}

void turn_left()
{   go_forwards(126);
	delay(70); //180
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (100));
	rlink.command(MOTOR_3_GO, 80);
	delay(1450);//found this issue on Tues week 3  //3550
}

void turn_right()
{   go_forwards(126);
	delay(90);//100
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (65) + 0x80);
	rlink.command(MOTOR_3_GO, 90 + 0x80);
	delay(1750);//3250
}

void spin_left(){ // will be used in recovery but NEED to be calibrate
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 62);
	rlink.command(MOTOR_3_GO, 60);
}
void spin_right(){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 80+0x80);
	rlink.command(MOTOR_3_GO, 75+0x80);

}


void stop(){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 0);
	rlink.command(MOTOR_3_GO, 0);
}


