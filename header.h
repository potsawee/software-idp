#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
//// Functions in routes.cc ////


void go_assembling();
void go_DF();
void go_DH();
void go_back_to_S();
void go_to_P();
void go_back_to_start();

//// Functions in mechanisms.cc ////
void grab_object();   //to use actuator, front motors to grab an object, and thermistor , to detect whether it has a defect, to find the orientation, to measure if its temperature is more than 30 deg.
void place_object1(); //to assemble a casting into an engine.
void place_object2(); //to place a casting at either DF or DH.


//// Functions in line_following.cc ////
void ajust_initial_position();
void follow_line_count_when_pass_junc();
void follow_line_til_junc();
void follow_turn_right();
void follow_turn_left();

//// Functions in movements.cc ////

void go_forwards(int speed); // from 0 (lowest) to 126 (highest)
void go_backwards(int speed); // from 0 (lowest) to 126 (highest)
void turn_left();
void turn_right();
void stop();



//// Enums & Classes ////
enum casting_type {
	GOOD = 1,
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
		int junctions_passed;
                int no_of_complete_test;

};


///// Global Variables /////
extern robot_link rlink; 
extern stopwatch watch;
extern robot_status rstatus;



#endif