#include "header.h"
using namespace std;
void go_assembling();


void go_DF()
{
	ajust_initial_position();
	rstatus.junctions_passed=0; // reset junction counter
	while (rstatus.junctions_passed< 4)
	{
		follow_line_count_when_pass_junc();
	}
	
	ajust_initial_position(); 
	follow_line_til_junc();
	follow_turn_left();
	
	rstatus.junctions_passed=0; // reset junction counter
	while (rstatus.junctions_passed< 3)
	{
		follow_line_count_when_pass_junc();
	}
	follow_turn_left();
	                    //codes for go forwards a little bit until the actuator touches the sample.
	
	};
void go_DH()
{
  
	ajust_initial_position();
	follow_line_til_junc();
	follow_turn_left();
	follow_line_til_junc();
	follow_turn_right();
	                   //codes for go forwards a little bit until the actuator touches the sample.
}
;
void go_back_to_S()
{
	switch(rstatus.destination){
	
	case D1:
	 {
		break;}
	
	case D2:
	 {
		break;}
		
	case D3:
	 {
		break;}
		
	case DF:
	 {
		 
		break;}
		
	case DH:
	 {
		break;}
		
    default: cout<<"error"<<endl;
             break;
	}
	
	
	
	
	
	};
void go_to_P_from_S()
{
	follow_line_count_when_pass_junc();
	delay(2000);
	follow_line_til_junc();
	                          //codes for go forwards a little bit until the actuator touches the sample.
	
	};
void go_back_to_start();
