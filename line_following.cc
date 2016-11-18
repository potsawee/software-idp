#include "header.h"
using namespace std;


void ajust_initial_position(){
	go_backwards(100); //*adjust initial position 
	delay(500);
	stop();
}

void read_sensors(){
	int s = rlink.request(READ_PORT_5);
	lfsensor = s bitand 0b111; 
}
// connect motor 1 to the left hand side.
void follow_forwards(int n){
	int junc = 0;
	int k = 70; // need to calibrate this!
    go_forwards(126);
    bool moving = true;
    while(moving){
        read_sensors();
        if(lfsensor != 0b010){
			switch(lfsensor){
				case 0b110:
					//try to turn left
					set_motors(126-k,126);
					while(lfsensor == 0b110){
						read_sensors();
					}
					go_forwards(126);
					break;
				case 0b011:
					//try to go right
					set_motors(126,126-k);
					while(lfsensor == 0b011){
						read_sensors();
					}
					go_forwards(126);
					break;
				case 0b111:
					//see a junction
					junc++;
					if(junc == n){
						stop();
						cout << "Detect a junction" << endl;
						moving = false;
						break;
					}
					while(lfsensor == 0b111){
						read_sensors();
					}
					break;
				//recovery when the mid sensor reads BLACK
				case 0b100:
					rstatus.last_white = 1;
					break;
				case 0b001:
					rstatus.last_white = 2;
				case 0b000:
					cout << "need to recover... now BBB" << endl;
					recovery1();
				default:
					cout << "Sensors detect something unexpected!" << endl;
					stop();
					moving = false;
				
			}//ending of switch
		}// ending of if not 0b010
    }
}

void follow_backwards(int n){
	int junc = 0;
	int k = 70;
    go_backwards(126);

	bool moving = true;
    while(moving){
        read_sensors();
        if(lfsensor != 0b010){
			switch(lfsensor){
				case 0b110:
					//try to turn left
					set_motors_back(126,126-k);
					while(lfsensor == 0b110){
						read_sensors();
					}
					go_backwards(126);
					break;
				case 0b011:
					//try to go right
					set_motors_back(126-k,126);
					while(lfsensor == 0b011){
						read_sensors();
					}
					go_backwards(126);
					break;
				case 0b111:
					//see a junction
					junc++;
					while(lfsensor == 0b111){
						read_sensors(); 
					}
					if(junc == n){
						stop();
						cout << "Detect a junction" << endl;
						moving = false;
					}
					break;
					
				//recovery when the mid sensor reads BLACK
				case 0b100:
					rstatus.last_white = 1;
					break;
				case 0b001:
					rstatus.last_white = 2;
				case 0b000:
					cout << "need to recover... now BBB" << endl;
					recovery2();
				default:
					cout << "Sensors detect something unexpected!" << endl;
					stop();
					moving = false;
				
			}//ending of switch
		}// ending of if not 0b010
	}
}

void follow_turn_right()
{
	go_forwards(126);
	delay(120);
	turn_right();
	
} //move forwards/backwards a a little bit and turn_right, after the sensor detected the junction and the robot stopped.
void follow_turn_left()
{
	go_forwards(126);
	delay(120);
	turn_left();
	
} //move forwards/backwards a a little bit and turn_left,, after the sensor detected the junction and the robot stopped.

void recovery1(){
	go_backwards(126);
	while(lfsensor == 0b000);
	stop();
	if(rstatus.last_white == 1){
		spin_left();
	}else {
		spin_right();
	}
	while((lfsensor bitand 0b010)!= 1 );
	delay(5);//calibrate this!!
	stop();
}
void recovery2(){

}
