#include "header.h"
using namespace std;

void go_forwards(int speed)   // from 0 (lowest) to 126 (highest)
{   rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, speed/2); 
	rlink.command(MOTOR_2_GO, speed + 0x80);
}

void go_backwards(int speed)  // from 0 (lowest) to 126 (highest)
{   rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (speed/2)+0x80);
	rlink.command(MOTOR_2_GO, speed);
}

void set_motors(int v1, int v2){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, v1/2); 
	rlink.command(MOTOR_2_GO, v2 + 0x80);
}

void set_motors_back(int v1, int v2){	
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (v1/2)+0x80);
	rlink.command(MOTOR_2_GO, v2);
}

void turn_left()
{   go_forwards(126);
	delay(170);
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (100/2));
	rlink.command(MOTOR_2_GO, 60);
	delay(3600);
}

void turn_right()
{   go_forwards(126);
	delay(170);
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (60/2) + 0x80);
	rlink.command(MOTOR_2_GO, 100 + 0x80);
	delay(3600);
}

void spin_left(){ // will be used in recovery but NEED to be calibrate
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 40);
	rlink.command(MOTOR_2_GO, 75);
}
void spin_right(){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 40+0x80);
	rlink.command(MOTOR_2_GO, 75+0x80);

}


void stop()
{	rlink.command(MOTOR_1_GO, 0);
	rlink.command(MOTOR_2_GO, 0);
}


