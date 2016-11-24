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

int main (){

	cout << "HELLLLLOOOO" << endl;

	read_job_done();
	cout << "rstatus.job_done = " << rstatus.job_done << endl;
	cout << "rstatus.good_done = " << rstatus.good_casting_done << endl << endl;
	rstatus.job_done += 2;
	rstatus.good_casting_done += 1;
	write_job_done();
	cout << "rstatus.job_done = " << rstatus.job_done << endl;
	cout << "rstatus.good_done = " << rstatus.good_casting_done << endl;
    
  
    

	return 0;  
}  

