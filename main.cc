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
int lfsensor;
int tsensor;

int main (){
	
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

	// go to the pick-up place
	go_to_P_from_S();

	do{
        align_pickup();
		grab_object();	 // now rstatus should have the updated values.
		find_destination();
		go_assembling();
        align_assemble();
		assemble_casting();
		go_back_to_P();
	}while(rstatus.job_done < 5);
	
// now it arrives at the destination, call place_object()
	
// with information about the case, execute route_back 1,2,3 etc;
// if not done goes to the first command i.e. move_s_to_p

  
	return 0;  
}  


