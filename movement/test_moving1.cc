#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#include <delay.h>
#include <iomanip>
#include "header_try1.h"

using namespace std;

#define ROBOT_NUM  16                         // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
stopwatch watch;

int main ()
{
int  val;                                // data from microprocessor

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

val = rlink.request (TEST_INSTRUCTION); 
if (val == TEST_INSTRUCTION_RESULT) {     // check result
	cout << "Test passed" << endl;                          // all OK, finish
}

go_forwards(120);

stop_if_white();

turn_right();
go_forwards(100);
delay(8500);
turn_left();

go_forwards(120);
delay(8500);
stop();

cout << "Congrats!" << endl;

char wanna_go_back;
cout << "Do you want me to get back? (y/n)  ";
cin >> wanna_go_back;
if(wanna_go_back == 'y'){
	go_backwards(120);
	delay(8500);
	turn_left();
	go_forwards(120);
	delay(8500);
	turn_left();
	go_forwards(120);
	delay(5000);
	
} else {
	cout << "Bye Bye" << endl;
}


return 0;  
}  

