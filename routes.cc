#include "header.h"
using namespace std;

void go_to_P_from_S()
{
	follow_forwards(2);     	                          //codes for go forwards a little bit until the actuator touches the sample.	
}

void go_assembling()
{
	follow_backwards(5);
	follow_turn_left();
	follow_forwards(4); //////the robot should stop at the line in front of D3
	
	switch(rstatus.destination){
	
	   case D1:
		 follow_turn_right();
		 follow_forwards(2);
		 follow_turn_left();
		 //codes for go forwards a little bit until the actuator touches the sample.
		 break;
	
	   case D2:
		 follow_turn_right();
		 follow_forwards(1);
		 follow_turn_left();
		 //codes for go forwards a little bit until the actuator touches the sample.
		 break;
		
	   case D3:
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
		
	   default: cout<<"error when going to the destination"<<endl;
             break;
	}
	rstatus.job_done ++;
}


void go_DF()
{
	
    follow_backwards(5);
	follow_turn_left();
	follow_forwards(3);
	follow_turn_left();
	                    //codes for go forwards a little bit until the actuator touches the sample.
	rstatus.job_done ++;
	}
void go_DH()
{
  
	follow_backwards(1);
	follow_turn_left();
	follow_forwards(1);
	follow_turn_right();
	                   //codes for go forwards a little bit until the actuator touches the sample.
	rstatus.job_done ++;
}

void go_back_to_P()
{
	switch(rstatus.destination){
	
	case D1:
		follow_backwards(1);
		follow_turn_left();
		follow_forwards(2);
		follow_turn_left();
		follow_forwards(4);
		follow_turn_left();
		follow_forwards(4);
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
	
	case D2:
		follow_backwards(1);
		follow_turn_left();
		follow_forwards(1);
		follow_turn_left();
		follow_forwards(4);
		follow_turn_left();
		follow_forwards(4);
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
		
	case D3:
		follow_backwards(5);
		follow_turn_right();
		follow_forwards(4);
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
		
	case DF:
	   follow_backwards(1);
	   follow_turn_left();
	   follow_forwards(3);
	   follow_turn_left();
	   follow_forwards(4); 
	   //codes for go forwards a little bit until the actuator touches the sample.
	   break;
		
	case DH:
		follow_backwards(1);
	    follow_turn_right();
	    follow_forwards(1);
	    follow_turn_left();
	    //codes for go forwards a little bit until the actuator touches the sample.
		break;
		
    default: cout<<"error when going pack to P"<<endl;
             break;
	}
	
	
	}

void go_back_to_start(){};
