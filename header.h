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
enum rotation {
	CW = 0,
	ACW
};

class robot_status {
	public:
		casting_type casting;
		int job_done;
        int good_casting_done;
		location destination;
		int last_white;
		int defect_indicator; //it is 1 when the casting has defect.
        int tsensor;       // themistor, it is 1 when the casting is too hot.
		//constructor
		robot_status(){
                       
			casting = NONE;
			// to job_done be initialise in the main.cc
			destination = P;
			last_white = 0; // 1 means LEFT = last white // 2 means RIGHT
                        tsensor=0;
                        defect_indicator=0;
		}
};

//// Functions in routes.cc ////
void find_destination();
void go_to_P_from_S();
void go_assembling();
void go_DF();
void go_DH();
void go_back_to_P();


//// Functions in mechanisms.cc ////
void read_thermistor();
void defect_testing();
void grab_object();   //to use actuator, front motors to grab an object, and thermistor , to detect whether it has a defect, to find the orientation, to measure if its temperature is more than 30 deg.
void assemble_casting(); //to assemble a casting into an engine.
void place_casting(); //to place a casting at either DF or DH.


//// Functions in line_following.cc ////
void adjust_initial_position();
void read_sensors();
void follow_forwards(int n); // stop at the n-th junction (1 means the first junction)
void follow_backwards(int n); // stop at the n-th junction
/*void follow_turn_right();// maybe just use turn_right instead of this function!
void follow_turn_left();*/
void follow_til_corner(int T);
void follow_til_corner2(int T);
void follow_curve(int n); //it will stop at the n-th junction after the curve
void follow_curve_back(); //from the start of the curve to P
void rotate180(rotation R);
void recovery1();
void recovery2();


//// Functions in movements.cc ////

void go_forwards(int speed); // from 0 (lowest) to 126 (highest)
void go_backwards(int speed); // from 0 (lowest) to 126 (highest)
void turn_left();
void turn_right();
void stop();
void set_motors(int v1, int v2);
void set_motors_back(int v1, int v2);
void spin_left();
void spin_right();

//// rwfile.cc //// read/write
void read_job_done();
void write_job_done();

///// Global Variables /////
extern robot_link rlink; 
extern stopwatch watch;
extern robot_status rstatus;
extern int lfsensor; //binary representation e.g. 0b111 // 1 means White // 0 means Black // Left is the highest bit.



#endif
