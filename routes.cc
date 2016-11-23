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
			rstatus.destination=D3;		
			break;
		case 2:
			rstatus.destination=D2;		
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
	adjust2();
	turn_left();
	follow_forwards(1);
	follow_til_corner(3800);
	follow_curve(rstatus.good_casting_done+1);
	turn_right();
	//the robot should just in front of the block
	rstatus.good_casting_done ++;
	rstatus.job_done ++;
}


void go_DF()
{
	adjust2();
    turn_left();
	follow_forwards(1);
	follow_til_corner(3800);
	turn_left();
	follow_forwards(2);
	turn_right();
	follow_forwards(1);
	turn_left();
	//the robot should just in front of the block              
	rstatus.job_done ++;
	}
void go_DH()
{
	adjust2();
    turn_left();
	follow_forwards(1);
	turn_right();
 	//the robot should just in front of the block              
	rstatus.job_done ++;
}

void go_back_to_P()
{
  switch(rstatus.destination){
	 
		case 1: //D1
			cout<<"GO BACK FROM D1 TO P"<<endl;
			adjust1();
			rotate180(ACW);
			follow_til_corner2(4700);
			follow_forwards(1);
			turn_left();
			follow_til_corner2(8500);
			turn_right();
			follow_forwards(2);
			turn_left(); //at P		
			break;
		case 2:
			cout<<"GO BACK FROM D2 TO P"<<endl;
		
				
			break;
		case 3:
			cout<<"GO BACK FROM D3 TO P"<<endl;
			adjust1();
			rotate180(ACW);
			follow_forwards(4);
			turn_left();
			follow_forwards(4);
			break;
		case 4:
			cout<<"GO BACK FROM DF TO P"<<endl;
			adjust1();
			turn_left();
			follow_forwards(3);
			turn_left();
			follow_forwards(4);
			break;
		case 5:
			cout<<"GO BACK FROM DT TO P"<<endl;
			adjust1();
			turn_right();
			follow_forwards(1);
			turn_left();  ///////   need to talk about the final position;
			break;
		default: cout<<"error with counting number of good casting done"<<endl;
			break;	
	}
}//end of the function
void go_back_to_S()
{
	switch(rstatus.destination){
	 
		case 1: //D1
			cout<<"GO BACK FROM D1 TO S"<<endl;
			adjust1();
		    turn_left();/////////haven't finished
			follow_til_corner2(4700);
			follow_forwards(1);
			turn_left();
			follow_til_corner2(8500);
			turn_right();
			follow_forwards(2);
			turn_left(); 	
			break;
		case 2:
		
		
				
			break;
		case 3:
			cout<<"GO BACK FROM D3 TO S"<<endl;
			adjust1();
			rotate180(ACW);
			follow_forwards(4);
			turn_left();
			follow_forwards(4);
			break;
		case 4:
			cout<<"GO BACK FROM DF TO S"<<endl;
			adjust1();
			turn_left();
			follow_forwards(3);
			turn_left();
			follow_forwards(3);
			break;
		case 5:
			cout<<"GO BACK FROM DH TO S"<<endl;
			adjust1();
			turn_right();
			follow_forwards(1);
			turn_left();  ///////   need to talk about the final position;
			break;
		default: cout<<"error with counting number of good casting done"<<endl;
			break;	
	}
}


