#include "header.h"
using namespace std;

void go_to_P_from_S()
{
	follow_forwards(2);
}

void find_destination()
{
	 switch(rstatus.job_done+1)
	 { 
		case 1: 
			rstatus.destination=DH;
			break;
		case 2:
			rstatus.destination=D1;
			break;
		case 3:
			rstatus.destination=D2;
			break;
		case 4:
			rstatus.destination=DF;
			break;
		case 5:
			rstatus.destination=D3;
			break;
		default:
			break;
	}
}

void go_assembling()
{
	 switch(rstatus.destination)
	 {
		case 1: //D1
		cout<<"GO D1"<<endl;
			adjust2();
			turn_left();
			follow_forwards(1);
			follow_til_corner(3000);
			follow_curve(1); 
			turn_right();
			rstatus.good_casting_done ++;
			rstatus.job_done ++;
			break;
		case 2: //D2
		cout<<"GO D2"<<endl;
			adjust2();
			turn_left();
			follow_forwards(1);
			follow_til_corner(3000);
			follow_curve(2); 
			turn_right();
			rstatus.good_casting_done ++;
			rstatus.job_done ++;
			break;
		case 3: //D3
		cout<<"GO D3"<<endl;
			adjust2();
			turn_left();
			follow_forwards(1);
			follow_til_corner(3000);
			follow_curve(3); 
			turn_right();
			rstatus.good_casting_done ++;
			rstatus.job_done ++;
			break;
		case 4:  //DF
		cout<<"GO DF"<<endl;
			adjust2();
			turn_left();
			follow_forwards(1);
			turn_left();
			follow_forwards(2);
			turn_right();
			follow_forwards(2);
			turn_left();    
			rstatus.job_done ++;
			break;
		case 5: //DH
		cout<<"GO DH"<<endl; 
			adjust2();
			turn_left();
			follow_forwards(1);
			turn_right();
			rstatus.job_done ++;
			break;
		default:
			break;
		}
	}
void go_back_to_P()
{
  switch(rstatus.destination){
	 
		case 1: //D1
			cout<<"GO BACK FROM D1 TO P"<<endl;
			adjust1();
			rotate180(ACW);
			follow_by_time(3000);
			follow_forwards(2);
			turn_left2();///////replace with a!C!!!!T!U!!!!!!!!!!!!!!! => i changed to left2
			follow_forwards(1);
			turn_right();
			follow_forwards(1);
			turn_left(); //at P
			
		
			// need to adjust
			
			go_backwards(50);
			delay(1500);
			follow_forwards(1);
			break;
		case 2:
			cout<<"GO BACK FROM D2 TO P"<<endl;
		    adjust1();
			turn_left();
			follow_forwards(1);
			turn_right();
		    adjust1();    ///////////NOW IT IS AT D3
			rotate180(ACW);
			follow_forwards(4);
			turn_left();
			follow_forwards(4);
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
			cout<<"GO BACK FROM DH TO P"<<endl;
			adjust2();
			//turn_right();
		go_forwards(126);
		delay(120);
		rlink.command (RAMP_TIME,0);
		rlink.command(MOTOR_1_GO, (65) + 0x80);
		rlink.command(MOTOR_3_GO, 90 + 0x80);
		delay(2000);
			follow_forwards(1);
			//turn_left();  ///////   need to talk about the final position;
		go_forwards(80);
		delay(200); 
		rlink.command (RAMP_TIME,0);
		rlink.command(MOTOR_1_GO, (100));
		rlink.command(MOTOR_3_GO, 80);
		delay(1650);
			break;
		default: cout<<"error with counting number of good casting done"<<endl;
			break;	
	}
}
void go_back_to_S()
{
	switch(rstatus.destination){
	 
		case 1: 
			cout<<"GO BACK FROM D1 TO S"<<endl;
			adjust1();
			turn_left();
			follow_forwards(2);
			turn_right();
			adjust1();
			rotate180(ACW);
			follow_forwards(4);
			turn_left();
			follow_forwards(3);
			break;
		case 2:
			cout<<"GO BACK FROM D2 TO S"<<endl;
		    adjust1();
			turn_left();
			follow_forwards(1);
			turn_right();
		    adjust1();    ///////////NOW IT IS AT D3
			rotate180(ACW);
			follow_forwards(4);
			turn_left();
			follow_forwards(3);		
			break;
		case 3:
			cout<<"GO BACK FROM D3 TO S"<<endl;
			adjust1();
			rotate180(ACW);
			follow_forwards(4);
			turn_left();
			follow_forwards(3);
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
			adjust2();
			//turn_right();
			go_forwards(126);
		delay(90);//100
		rlink.command (RAMP_TIME,0);
		rlink.command(MOTOR_1_GO, (65) + 0x80);
		rlink.command(MOTOR_3_GO, 90 + 0x80);
		delay(1750);//3250
	
	
	
			follow_forwards(1);
			//turn_left();  ///////   need to talk about the final position;		
	go_forwards(100);
	delay(225); //180
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, (100));
	rlink.command(MOTOR_3_GO, 80);
	delay(1500);//found this issue on Tues week 3  //3550
	
	
			adjust1();    
			rotate180(ACW);
			follow_forwards(2);
			break;
		default: cout<<"error with counting number of good casting done"<<endl;
			break;	
	}
}
/*void find_destination()
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
}*/

/*void go_assembling()
{
  if (rstatus.destination<4)   //D123
  {
	adjust2();
	turn_left();
	follow_forwards(1);
	follow_til_corner(3000);
	follow_curve(rstatus.job_done+1); 
	turn_right();

	rstatus.good_casting_done ++;
	rstatus.job_done ++;
  }
  else if (rstatus.destination==4) //DF
  {
	adjust2();
    turn_left();
	follow_forwards(1);
	turn_left();
	follow_forwards(2);
	turn_right();
	follow_forwards(2);
	turn_left();
             
	rstatus.job_done ++;
  }
  else if (rstatus.destination==5)  //DH 
  {
	cout << "GOOOO" << endl; 
	adjust2();
    turn_left();
	follow_forwards(1);
	turn_right();
              
	rstatus.job_done ++;
  }
}//end of the function*/
