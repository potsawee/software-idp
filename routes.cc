#include "header.h"
using namespace std;

void find_destination()
{
	if ( (rstatus.tsensor==1)&&(rstatus.defect_indicator ==0) )
	{rstatus.destination=DH;	
    }
	else if ( (rstatus.tsensor==0)&&(rstatus.defect_indicator ==1) )
	{rstatus.destination=DF;
	}	
	else if ( (rstatus.tsensor==0)&&(rstatus.defect_indicator ==0) )
	{
		switch(rstatus.good_casting_done){
	    case 0:
		rstatus.destination=D1;		
		break;
		case 1:
		rstatus.destination=D2;		
		break;
		case 2:
		rstatus.destination=D3;		
		break;
		case 3:
		cout<<"all three castings have been delivered already!"<<endl;
		break;
		default: cout<<"error with counting number of good casting done"<<endl;
        break;
	    }//end of switch
    }
    else
    cout<<"error about counting number of good castings"<<endl;
}



void go_to_P_from_S()
{
	follow_forwards(2);
	//codes for go forwards a little bit until the actuator touches the sample.	
}

void go_assembling()
{
	follow_backwards(5);
	follow_turn_left();
	follow_forwards(4); //the robot should stop at the line in front of D3
	
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
	rstatus.good_casting_done ++;
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
	int complete_indicator;
	if(rstatus.job_done==5)
	complete_indicator=1;
    else
    complete_indicator=0;
    
	switch(rstatus.destination){
	
	case D1:
		follow_backwards(1);
		follow_turn_left();
		follow_forwards(2);
		follow_turn_left();
		follow_forwards(4);
		follow_turn_left();
		follow_forwards(4-complete_indicator);
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
	
	case D2:
		follow_backwards(1);
		follow_turn_left();
		follow_forwards(1);
		follow_turn_left();
		follow_forwards(4);
		follow_turn_left();
		follow_forwards(4-complete_indicator);
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
		
	case D3:
		follow_backwards(5);
		follow_turn_right();
		follow_forwards(4-complete_indicator);
		//codes for go forwards a little bit until the actuator touches the sample.
		break;
		
	case DF:
	   follow_backwards(1);
	   follow_turn_left();
	   follow_forwards(3);
	   follow_turn_left();
	   follow_forwards(4-complete_indicator); 
	   //codes for go forwards a little bit until the actuator touches the sample.
	   break;
		
	case DH:
		follow_backwards(1);
	    follow_turn_right();
	    follow_forwards(1);
	    if (complete_indicator==0)
	    follow_turn_left();
	    //codes for go forwards a little bit until the actuator touches the sample.
	    else if (complete_indicator==1)
	    follow_turn_right();
	    follow_forwards(2);
		break;
		
    default: cout<<"error when going pack to P"<<endl;
             break;
	} //end of switch
		
}//end of the function


