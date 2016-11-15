#include "header.h"
using namespace std;


void ajust_initial_position(){
	go_backwards(100); //*adjust initial position 
	delay(500);
	stop();
}

void read_sensors(){
	int s = rlink.request(READ_PORT_5);
	if(s bitand 0x01){
		rsensor.right = W;
	} else {
		rsensor.right = B;
	}
	if(s bitand 0x02){
		rsensor.mid = W;
	} else {
		rsensor.mid = B;
	}
	if(s bitand 0x04){
		rsensor.left = W;
	}else {
		rsensor.left = B;
	}
}
// connect motor 1 to the left hand side.
void follow_forwards(int n){
	int junc = 0;
	int k = 70; // need to calibrate this!
    go_forwards(126);
    
    while(true){
        read_sensors();
        if(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
            if (rsensor.left == W or rsensor.mid == W or rsensor.right == B){
                //try to turn left
                set_motors(120-k,120);
                while(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
					read_sensors();
				}
				go_forwards(126);
                
            } else if(rsensor.left == B or rsensor.mid == B or rsensor.right == W){
                //try to go right
                set_motors(120,120-k);
                while(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
					read_sensors();
				}
				go_forwards(126);
            } else if (rsensor.left == W and rsensor.mid == W and rsensor.right == W) {
				junc++;
				if(junc == n){
					stop();
					cout << "Detect a junction" << endl;
					break;
				}
				while(rsensor.left == W and rsensor.mid == W and rsensor.right == W){
					read_sensors();
				}
	
			} else {
                cout << "ERROR BBB" << endl;
                stop();
                break;
            }
        }
    }
}

void follow_backwards(int n){
	int junc = 0;
	int k = 70;
    go_backwards(126);

    while(true){
        read_sensors();
        
        if(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
            if (rsensor.left == W or rsensor.mid == W or rsensor.right == B){
                //try..
                set_motors(120,120-k);
                while(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
					read_sensors();
				}
				go_backwards(126);
            } else if(rsensor.left == B or rsensor.mid == B or rsensor.right == W){
                //try
                set_motors(120-k,120);
                while(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
					read_sensors();
				}
				go_backwards(126);
            } else if (rsensor.left == W and rsensor.mid == W and rsensor.right == W) {
				junc++;
				while(rsensor.left == W and rsensor.mid == W and rsensor.right == W){
					read_sensors();
				}
				if(junc == n){
					stop();
					cout << "Detect a junction" << endl;
					break;
				}
			} else {
                cout << "ERROR BBB" << endl;
                stop();
                break;
            }
        }
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
