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

void turn_left()
{   rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 50);
	rlink.command(MOTOR_2_GO, 60);
	delay(3800);
}

void turn_right()
{   rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 30 + 0x80);
	rlink.command(MOTOR_2_GO, 100 + 0x80);
	delay(3800);
}
void stop()
{	rlink.command(MOTOR_1_GO, 0);
	rlink.command(MOTOR_2_GO, 0);
}

void set_motors(int v1, int v2)
{
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, v1/2); 
	rlink.command(MOTOR_2_GO, v2 + 0x80);
}
