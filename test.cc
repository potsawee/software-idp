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
	cout << "HELLLLLOOOO" << endl;
    
    follow_forwards(4);
       follow_turn_right();
    follow_forwards(2);
    follow_turn_right();
    follow_forwards(2);
    follow_turn_right();
       follow_forwards(2);


    follow_forwards(2);

    
    
    /*while (1)
    {read_sensors();
     ConvertToBinary(lfsensor);
     cout<<endl;	
	delay(500);
     }*/
    

	return 0;  
}  

void ConvertToBinary(int n) /*Alex says: Good to use unsigned int if u can*/
{
    if (n / 2 != 0) {
        ConvertToBinary(n / 2);
    }
    printf("%d", n % 2);
}

