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
	

	
	read_job_done();
	cout << "good_casting_done = " << rstatus.good_casting_done << endl;
	rstatus.good_casting_done++;
	write_job_done();
  
	return 0;  
}  



