#include "header.h"
using namespace std;

void read_thermistor(){// tsensor = 1 means temp > 30 deg
	int s = rlink.request(READ_PORT_5);
	rstatus.tsensor = (s bitand 0b10000)/16;
	cout << rstatus.tsensor << endl; 
}

void defect_testing(){
	                    
                    
  rstatus.defect_indicator=0;// to be changed
}

void grab_object(){  //to use actuator, front motors to grab an object, and thermistor , to detect whether it has a defect, to find the orientation, to measure if its temperature is more than 30 deg.


                   

read_thermistor();
defect_testing();

///using the switches
/*
		int sw = rlink.request(READ_PORT_2);
		int s1 = sw bitand 0b10;
		int s2 = sw bitand 0b100;*/


}
void assemble_casting(){ //to assemble a casting into an engine.
	
}
void place_casting(){ //to place a casting at either DF or DH.
	
}

