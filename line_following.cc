#include "header.h"
using namespace std;


void adjust_initial_position(){
	go_backwards(126); //*adjust initial position 
	delay(1500);
	follow_forwards(1);
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
						cout << "Detect a junction1111" << endl;
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
					break;
				case 0b000:
					cout << "need to recover... now BBB" << endl;
					recovery1();
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
	int k = 50;
	int fspeed = 100;
    go_backwards(126);

	bool moving = true;
    while(moving){
        read_sensors();
        cout << "lfsensor " << lfsensor << endl;
        
        if(lfsensor != 0b010){
			switch(lfsensor){
				case 0b011:
					cout << "turn leftttt!!!" << endl;
					//try to turn left
					//rlink.command(MOTOR_1_GO, (50/2)+0x80);
					//rlink.command(MOTOR_2_GO, 80);
					set_motors_back(fspeed-k,fspeed);
					while(lfsensor == 0b011){
						read_sensors();
					}
					go_backwards(126);
					break;
				case 0b110:
					cout << "turn righttttt!!!" << endl;
					//try to go right
					set_motors_back(fspeed,fspeed-k);
					while(lfsensor == 0b110){
						read_sensors();
					}
					go_backwards(126);
					break;
				case 0b111:
					cout << "WWW!!!" << endl;
					//see a junction
					junc++;
					while(lfsensor == 0b111){
						read_sensors(); 
					}
					if(junc == n){
						stop();
						cout << "Detect a junction22222222" << endl;
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

void follow_til_corner(int T){
	int k = 70; // need to calibrate this!
	int t_start = watch.read();
	int time = watch.read() - t_start;
	//int T = (3850);// distance over speed; here calibrate with speed = 126
    go_forwards(126);
    while(lfsensor == 0b111){
		read_sensors();
	}
    bool moving = true;
    while(moving){
        read_sensors();
        time = watch.read() - t_start;
        if(lfsensor != 0b010 and time < T){
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
				//recovery when the mid sensor reads BLACK
				case 0b100:
					rstatus.last_white = 1;
					break;
				case 0b001:
					rstatus.last_white = 2;
					break;
				case 0b000:
					cout << "need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "Sensors detect something unexpected!" << endl;
					stop();
					moving = false;
				
			}//ending of switch
		}// ending of if not 0b010
		else if(time > T){
			cout << "T > 3850" << endl;
			go_forwards(126);
			while(true){
				read_sensors();
				if(lfsensor == 0b011){
					moving = false;
					cout << "detect a corner" << endl;
					break;
				}
			};
		}
    }
}

void rotate180(rotation R){
	if(R == ACW)
		spin_left();
	else if(R == CW)
		spin_right();
	else
		cout << "rotation180 accpets either ACW for anti-clockwise or CW for clockwise" << endl;
	read_sensors();
	while(lfsensor != 0b000){
		read_sensors();
	}
	while(lfsensor != 0b010){
		read_sensors();
	}
	stop();	
}

void follow_curve(int n){
	go_forwards(126);
	delay(3000);
	read_sensors();
	while(lfsensor == 0b000){
		read_sensors();
	}
	follow_forwards(n);
}
void follow_curve_back(){
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
				case 0b000:
					cout << "see blacl space BBB" << endl;
					moving = false;
					break;
				default:
					cout << "problem occurs follow curve back" << endl;
					break;
			}//ending of switch
		}// ending of if not 0b010
    }
    
    go_forwards(126);
	read_sensors();
	while(lfsensor == 0b000){
		read_sensors();
	}
	follow_forwards(2);
}

void follow_til_corner2(int T){
	int k = 70; // need to calibrate this!
	int t_start = watch.read();
	int time = watch.read() - t_start;
	//int T = (6000);// distance over speed; here calibrate with speed = 126
    go_forwards(126);
    while(lfsensor == 0b111){
		read_sensors();
	}
    bool moving = true;
    while(moving){
        read_sensors();
        time = watch.read() - t_start;
        if(lfsensor != 0b010 and time < T){
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
				//recovery when the mid sensor reads BLACK
				case 0b100:
					rstatus.last_white = 1;
					break;
				case 0b001:
					rstatus.last_white = 2;
					break;
				case 0b000:
					cout << "need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "Sensors detect something unexpected!" << endl;
					stop();
					moving = false;
				
			}//ending of switch
		}// ending of if not 0b010
		else if(time > T){
			cout << "T > 3850" << endl;
			go_forwards(126);
			while(true){
				read_sensors();
				if(lfsensor == 0b110){
					moving = false;
					cout << "detect a corner type 2" << endl;
					break;
				}
			};
		}
    }
}

void recovery1(){
	go_backwards(126);
	while(lfsensor == 0b000){
		read_sensors();
	}
	//stop();
	if(rstatus.last_white == 1){
		spin_left();
		while(lfsensor != 0b010){
			read_sensors();
		}
	}else {
		spin_right();
		while(lfsensor != 0b010){
			read_sensors();
		}
	}
	go_forwards(126);
}
void recovery2(){

}
