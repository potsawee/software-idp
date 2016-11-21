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
	//the robot should just in front of the block
}

void go_assembling()
{
	ajust_initial_position();
	follow_turn_left();
	follow_forwards(1);
	follow_til_corner();
	follow_curve(good_casting_done+1);
	follow_turn_right();
	//the robot should just in front of the block
	rstatus.good_casting_done ++;
	rstatus.job_done ++;
}


void go_DF()
{
	ajust_initial_position();
    follow_turn_left();
	follow_forwards(1);
	follow_til_corner();
	follow_turn_left();
	follow_forwards(2);
	follow_turn_right();
	follow_forwards(1);
	follow_turn_left();
	//the robot should just in front of the block              
	rstatus.job_done ++;
	}
void go_DH()
{
	ajust_initial_position();
    follow_turn_left();
	follow_forwards(1);
	follow_turn_right();
 	//the robot should just in front of the block              
	rstatus.job_done ++;
}

void go_back_to_P()
{
	int complete_indicator;
	if(rstatus.job_done==5)
	complete_indicator=1;
    else
    complete_indicator=0;
    
    if(0<rstatus.destination<4)
    {
		ajust_initial_position();
        follow_turn_right();
        while (rstatus.destination>0)
        {
        follow_forwards(rstatus.destination-1);
		};	
		follow_curve_back();
	};
	else if (rstatus.destination==4) //DF
	{
		ajust_initial_position();
        follow_turn_right();
        follow_forwards(1);
        follow_turn_right();
        follow_forwards(2);
        follow_curve_back();	
    };
    else if (rstatus.destination==5) //DH
	{
		ajust_initial_position();
        follow_turn_right();
        follow_forwards(1);
    };
}//end of the function

//function for going back to S !!!!!!!!!!!!!!

