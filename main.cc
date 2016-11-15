#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include <delay.h>
#include <iomanip>
#include "header.h"
using namespace std;

#define ROBOT_NUM  16                         // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
stopwatch watch;
robot_status rstatus;
sensor_status rsensor;

int main (){
	
	cout << "rstatus = " << rstatus.destination << endl; 

	#ifdef __arm__
		if (!rlink.initialise ()) {          // setup for local hardware
			cout << "Cannot initialise link..robot case" << endl;
			rlink.print_errs("    ");
			return -1;
		}
	#else
		if (!rlink.initialise (ROBOT_NUM)) { // setup the link
			cout << "Cannot initialise link...pc case" << endl;
			rlink.print_errs("    ");
			return -1;
		}
	#endif
	int val = rlink.request (TEST_INSTRUCTION); 
	
	if (val == TEST_INSTRUCTION_RESULT) {     // check result
		cout << "Test passed" << endl;                          // all OK, finish
	}

// call function move_s_to_p();
// call function activate_actuator(); // this will grab an object this should return 1 if the object contains flashing; otherwise 0.
// call function use_thermistor(); // this should return 1 if hot, 0

// with 1. number good object delivered 2. is Hot 3. have flashing or not ==> generate the case need to perform

// switch(case) // execute route 1,2,3 etc

// now it arrives at the destination, call place_object()
// with information about the case, execute route_back 1,2,3 etc;
// if not done goes to the first command i.e. move_s_to_p

  
    

	return 0;  
}  


