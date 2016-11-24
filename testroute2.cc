
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
	cout << "This is test route 2." << endl;
	
	watch.start();
	go_to_P_from_S();
	rstatus.good_casting_done=0;
	
	
	rstatus.destination = D1;
	cout << "Going to D1" << endl;
	go_assembling();
	cout << "Going to P" << endl;
	go_back_to_P();
	
	rstatus.destination = D2;
	cout << "Going to D2" << endl;
	go_assembling();
	cout << "Going to P" << endl;
	go_back_to_P();
	
	rstatus.destination = D3;
	cout << "Going to D3" << endl;
	go_assembling();
	cout << "Going to P" << endl;
	go_back_to_P();
	
	
	rstatus.destination = DH;
	cout << "Going to DH" << endl;
	go_assembling();
	cout << "Going to P" << endl;
	go_back_to_P();
	
	rstatus.destination = DF;
	cout << "Going to DF" << endl;
	go_assembling();
	cout << "Going to P" << endl;
	go_back_to_P();
 
}  


