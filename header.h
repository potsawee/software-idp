#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <string>
#include <fstream>
//// Functions in routes.cc ////

void go_assembling();
void go_DF();
void go_DH();
void go_back_to_S();
void go_to_P();
void go_back_to_start();
void go_back_to_P();
void go_to_P_from_S();

//// Functions in mechanisms.cc ////
void grab_object();   //to use actuator, front motors to grab an object, and thermistor , to detect whether it has a defect, to find the orientation, to measure if its temperature is more than 30 deg.
void assemble_casting(); //to assemble a casting into an engine.
void place_casting(); //to place a casting at either DF or DH.


//// Functions in line_following.cc ////
void adjust_initial_position();
void read_sensors();
void follow_forwards(int n); // stop at the n-th junction (1 means the first junction)
void follow_backwards(int n); // stop at the n-th junction
void follow_turn_right();
void follow_turn_left();

//// Functions in movements.cc ////

void go_forwards(int speed); // from 0 (lowest) to 126 (highest)
void go_backwards(int speed); // from 0 (lowest) to 126 (highest)
void turn_left();
void turn_right();
void stop();
void set_motors(int v1, int v2);

//// readfile.cc ////


//// Enums & Classes ////
enum casting_type {
	NONE = 0,
	GOOD,
	HOT,
	FLASHING
};
enum location {
	S = 0,
	D1,
	D2,
	D3,
	DF,
	DH,
	P
};

class robot_status {
	public:
		casting_type casting;
		int job_done;
		location destination;
		//constructor
		robot_status(){
			casting = NONE;
			job_done; // to be initialise in the main.cc
			destination = P;
		}
};

///// Global Variables /////
extern robot_link rlink; 
extern stopwatch watch;
extern robot_status rstatus;
extern int rsensor; 
//binary representation e.g. 0b111 // 1 means White // 0 means Black // Left is the highest bit.

#endif
