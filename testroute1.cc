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
	cout << "This is test route1 ." << endl;
	
	watch.start();

	//this is from S to P to D1 and back to P
while(1){
	//S to P
	follow_forwards(2);
	
	//p to D1
	adjust_initial_position();
	turn_left();
	follow_forwards(1);
	follow_til_corner(3800);
	follow_curve(1);
	turn_right();
	
	//D1 back
	adjust_initial_position();
	rotate180(ACW);
	follow_til_corner2(4700);
	follow_forwards(1);
	
	//
	turn_left();
	follow_til_corner2(8500);
	turn_right();
	follow_forwards(2);
	turn_left(); //at P
	
	//back to S
	adjust_initial_position();
	rotate180(ACW);
	follow_forwards(2);
	
	//next loop
	rotate180(ACW);

}

}  


