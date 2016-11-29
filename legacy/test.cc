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
	cout << "HELLLLLOOOO" << endl;
	
	watch.start();

	
	/*follow_forwards(1);
	go_backwards(126);
	delay(1000);
    rotate180();
    follow_forwards(1);*/
	
	//go_forwards(126);
	/*while(true){
	cout << "t = " << watch.read()-t1 << endl;
	}*/
	
	/*
	follow_forwards(1);
	follow_corner();
	go_forwards(126);
  	delay(3000);
  	read_sensors();
  	while(lfsensor == 0b000){
		read_sensors();
	}
 
	follow_forwards(3);
	follow_turn_left();
	follow_forwards(1);
	follow_turn_right();
    */
    
    
       /*follow_turn_right();
    follow_forwards(2);
    follow_turn_right();
    follow_forwards(2);
    follow_turn_right();
       follow_forwards(2);


    follow_forwards(2);*/

    
    
    /*while (1)
    {read_sensors();
     ConvertToBinary(lfsensor);
     cout<<endl;	
	delay(500);
     }*/
    
    
    follow_forwards(1);
    follow_turn_left();
    follow_forwards(1);
    follow_turn_left();
    follow_forwards(1);
    follow_turn_left();
    follow_forwards(1);
    follow_turn_left();
    
    

	return 0;  
}  

void ConvertToBinary(int n) /*Alex says: Good to use unsigned int if u can*/
{
    if (n / 2 != 0) {
        ConvertToBinary(n / 2);
    }
    printf("%d", n % 2);
}

