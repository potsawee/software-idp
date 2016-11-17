#include "header.h"

void read_thermistor(){
	int s = rlink.request(READ_PORT_5);
	rstatus.tsensor = s bitand 0b1000; 
}

void defect_testing(){
	                    
                    
  rstatus.defect_indicator=0;// to be changed
}

void grab_object(){  //to use actuator, front motors to grab an object, and thermistor , to detect whether it has a defect, to find the orientation, to measure if its temperature is more than 30 deg.


                   

read_thermistor();
defect_testing();


}
void assemble_casting(){ //to assemble a casting into an engine.
	
}
void place_casting(){ //to place a casting at either DF or DH.
	
}
