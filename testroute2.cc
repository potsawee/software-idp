
#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include <delay.h>
#include <iomanip>
#include "header.h"
#include <string>
using namespace std;  

#define ROBOT_NUM  16                         // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
stopwatch watch;
robot_status rstatus;
int lfsensor;
void ConvertToBinary(int n);


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
	if(1){
		follow_forwards(2);
		turn_left2();
		follow_forwards(1);

}

}  


