#include "header.h"
using namespace std;


void ajust_initial_position(){
	go_backwards(100); //*adjust initial position 
	delay(500);
	stop();
}

void read_sensors(){
	int s = rlink.request(READ_PORT_5);
	rsensor = s bitand 0b111;
}
// connect motor 1 to the left hand side.
void follow_forwards(int n){
	int junc = 0;
	int k = 70; // need to calibrate this!
    go_forwards(126);
    bool moving = true;
    while(moving){
        read_sensors();
        if(rsensor != 0b010){
			switch(rsensor){
				case 0b110:
					//try to turn left
					set_motors(126-k,126);
					while(rsensor == 0b110){
						read_sensors();
					}
					go_forwards(126);
					break;
				case 0b011:
					//try to go right
					set_motors(126,126-k);
					while(rsensor == 0b011){
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
					while(rsensor == 0b111){
						read_sensors();
					}
					break;
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
        if(rsensor != 0b010){
			switch(rsensor){
				case 0b110:
					//try to turn left
					set_motors_back(126,126-k);
					while(rsensor == 0b110){
						read_sensors();
					}
					go_backwards(126);
					break;
				case 0b011:
					//try to go right
					set_motors_back(126-k,126);
					while(rsensor == 0b011){
						read_sensors();
					}
					go_backwards(126);
					break;
				case 0b111:
					//see a junction
					junc++;
					while(rsensor.left == W and rsensor.mid == W and rsensor.right == W){
						read_sensors();
					}
					if(junc == n){
						stop();
						cout << "Detect a junction" << endl;
						moving = false;
					}
					break;
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
	turn_right();
	
} //move forwards/backwards a a little bit and turn_right, after the sensor detected the junction and the robot stopped.
void follow_turn_left()
{
	turn_left();
	
} //move forwards/backwards a a little bit and turn_left,, after the sensor detected the junction and the robot stopped.
