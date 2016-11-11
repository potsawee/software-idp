#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include <delay.h>
#include <iomanip>
#include "header_try1.h"

using namespace std;

// The motor 1 is a 40 rpm motor; this is the right motor.
// The motor 2 is a 20 rpm motor; this is the left motor. if you want to go forward SET the highest bit.
// The speed is from 0-127
void go_forwards(int speed){

	rlink.command (RAMP_TIME,0);

	rlink.command(MOTOR_1_GO, speed/2); 
	rlink.command(MOTOR_2_GO, speed + 0x80); 
	
}
void go_backwards(int speed){

	rlink.command (RAMP_TIME,0);

	rlink.command(MOTOR_1_GO, (speed/2)+0x80);
	rlink.command(MOTOR_2_GO, speed);
	
}
void turn_right(){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 30 + 0x80);
	rlink.command(MOTOR_2_GO, 100 + 0x80);
	delay(3800);
};
void turn_left(){
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 50);
	rlink.command(MOTOR_2_GO, 60);
	delay(3800);
};
void stop(){
	rlink.command(MOTOR_1_GO, 0);
	rlink.command(MOTOR_2_GO, 0);
}
void stop_if_white(){
	while(true){
		int sensor_1 = rlink.request(READ_PORT_5)-0xf0;
		if( sensor_1 == 1){
			cout << "Detected White" << endl;
			break;
		}
	}
}
