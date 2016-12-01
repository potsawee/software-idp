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
		cout << "Starttttt!!!!!" << endl;                          // all OK, finish
	}


	read_job_done();
	cout << "Job done = " << rstatus.job_done << endl;

	watch.start();
	grabber_open();
	
	// go to the pick-up place
	go_to_P_from_S();

	do{
        align_pickup();
		grabber_closed();
		find_destination();
		go_assembling();
		
		stop();
		delay(2000);
		grabber_open();
		
		write_job_done();
		read_job_done();
		cout << "Job done = " << rstatus.job_done << endl;
		
		go_back_to_P();
		
	}while(rstatus.job_done < 4);
	
	align_pickup();
	grabber_closed();
	find_destination();
	go_assembling();
		
	stop();
	delay(2000);
	grabber_open();
	
	go_back_to_S();
	

	return 0;  
}  

