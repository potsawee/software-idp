#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include <delay.h>
#include <iomanip>
#include "header.h"
#include <string>
using namespace std;  
 //LED off means ONE!!!
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
	cout << "This is test 2." << endl;
	
	watch.start();
	/*follow_forwards(4);
	go_forwards(126);
	delay(500);
	adjust_initial_position();
	turn_left();
	follow_forwards(1);
	follow_til_corner(3800);
	follow_curve(1);
	turn_right();
	adjust_initial_position();
	*/
	while(1){
	follow_forwards(1);

	adjust_initial_position();
	rotate180(ACW);
	
	follow_til_corner2(2500);
	follow_forwards(1);
	rotate180(ACW);
	
	follow_til_corner(2500);
	follow_forwards(1);
}
	go_backwards(100);
	while(0){
	cout << "motor 1 speed = " << rlink.request(MOTOR_1) << endl;
		cout << "motor 2 speed = " << rlink.request(MOTOR_2) << endl;	
	}

	return 0;  
}  



