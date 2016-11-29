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

void use_actuator();

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
	cout << "first demo." << endl;
	
	//use_actuator();
	cout << "use_actuator" << endl;
	
	while(1){
		int r = rlink.request(READ_PORT_2);
		//int a = r bitand 0b1000000; // closest distance  7th
		//int b = r bitand 0b100000; // 2nd most           6th
		int c = r bitand 0b10000;
		
		cout << "c = " << c << endl; 
		delay(500);
	}
	

}  

void use_actuator(){
	rlink.command (WRITE_PORT_2, 0b10000000);        //   8th
	delay(1000);
	rlink.command (WRITE_PORT_2, 0b000);
	delay(1000);
	//most significant bit at 010
}

