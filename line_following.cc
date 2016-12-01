#include "header.h"
using namespace std;

int k = 40;

void adjust1(){
	read_sensors();
	cout << "start adjusting1" << endl;
	go_backwards(50);
	//cout << "back adjusting1" << endl;
	while(lfsensor != 0b111){
		read_sensors();
	}
	while(lfsensor == 0b111){
		read_sensors();
	}
	cout << "stop adjusting1" << endl;
	stop();
}
void adjust2(){
	read_sensors();
	cout << "start adjusting2" << endl;
	go_backwards(50);
	//cout << "back adjusting2" << endl;
	while(lfsensor != 0b111){
		read_sensors();
	}
	while(lfsensor == 0b111){
		read_sensors();
	}
	cout << "stop adjusting2" << endl;
	
	go_forwards(30);
	delay(175);
	stop();
}
void read_sensors(){
	int s = rlink.request(READ_PORT_5);
	lfsensor = s bitand 0b111; 
}
// connect motor 1 to the left hand side.
void follow_forwards(int n){
	cout << "Start follow_forward" << endl;
	int junc = 0;
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
						cout << "FF: Detect a junction (next command)" << endl;
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
					cout << "FF: need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "FF: Sensors detect something unexpected!" << endl;
					cout << "IRsensors = " << lfsensor << endl;
					stop();
			}//ending of switch
		}// ending of if not 0b010
    }
}

void follow_curve(int n){
	cout << "Start follow_curve" << endl;
	rlink.command (RAMP_TIME,0);
	rlink.command(MOTOR_1_GO, 126/2); 
	rlink.command(MOTOR_3_GO, (126/2) -5 + 0x80);
	delay(2000);
	read_sensors();
	while(lfsensor == 0b000){
		read_sensors();
	}
	
	cout << "Start curve part 2" << endl;
	int junc = 0;
	int k = 40;
    go_forwards(126/2);
    bool moving = true;
    while(moving){
        read_sensors();
        if(lfsensor != 0b010){
			switch(lfsensor){
				case 0b110:
					//try to turn left
					set_motors((126/2)-k,126/2);
					while(lfsensor == 0b110){
						read_sensors();
					}
					go_forwards(126/2);
					break;
				case 0b011:
					//try to go right
					set_motors(126/2,(126/2)-k);
					while(lfsensor == 0b011){
						read_sensors();
					}
					go_forwards(126/2);
					break;
				case 0b111:
					//see a junction
					junc++;
					if(junc == n){
						stop();
						cout << "Fcurve: Detect a junction (next command)" << endl;
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
					cout << "Fcurve: need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "Fcurve: Sensors detect something unexpected!" << endl;
					cout << "IRsensors = " << lfsensor << endl;
					stop();
			}//ending of switch
		}// ending of if not 0b010
    }
}

void follow_til_corner(int T){
	int k = 50;
	cout << "Start follow_til_corner" << endl;
	int t_start = watch.read();
	int time = watch.read() - t_start;
    go_forwards(80);
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
					set_motors(80-k,80);
					while(lfsensor == 0b110){
						read_sensors();
					}
					go_forwards(80);
					break;
				case 0b011:
					//try to go right
					set_motors(80,80-k);
					while(lfsensor == 0b011){
						read_sensors();
					}
					go_forwards(80);
					break;
				//recovery when the mid sensor reads BLACK
				case 0b100:
					rstatus.last_white = 1;
					break;
				case 0b001:
					rstatus.last_white = 2;
					break;
				case 0b000:
					cout << "FC: need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "FC: Sensors detect something unexpected!" << endl;
					stop();
				
			}//ending of switch
		}// ending of if not 0b010
		else if(time > T){
			cout << "time exceeded corner type 1" << endl;
			go_forwards(80);
			while(true){
				read_sensors();
				if(lfsensor == 0b000){
					moving = false;
					cout << "detect a black space" << endl;
					break;
				}
			};
		}
    }
}

void follow_by_time(int T){
	cout << "Start follow_by_time" << endl;
	go_forwards(126);
	int t0 = watch.read();
    while(watch.read()-t0 < T){
		//cout << "t = " << watch.read()-t0 << endl;
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
					cout << "Follow by time: Detect WWW" << endl;
					break;
				//recovery when the mid sensor reads BLACK
				case 0b100:
					rstatus.last_white = 1;
					break;
				case 0b001:
					rstatus.last_white = 2;
					break;
				case 0b000:
					cout << "Follow by time: need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "Follow by time: Sensors detect something unexpected!" << endl;
					cout << "IRsensors = " << lfsensor << endl;
			}//ending of switch
		}// ending of if not 0b010
    }
    stop();
    cout << "Time exceeded, finish follow by time" << endl;
}

void rotate180(rotation R){
	if(R == ACW){
		spin_left();
		cout << "Rotate 180 deg ACW" << endl;
		while(lfsensor != 0b000){
			read_sensors();
		}
		while(lfsensor != 0b010){
			read_sensors();
			if(lfsensor == 0b011)
				break;
		}
		stop();	
	}
	else if(R == CW){
		spin_right();
		cout << "Rotate 180 deg CW" << endl;
		while(lfsensor != 0b000){
			read_sensors();
		}
		while(lfsensor != 0b010){
			read_sensors();
			if(lfsensor == 0b110)
				break;
		}
		stop();	
	}
	else
		cout << "rotation180 accpets either ACW for anti-clockwise or CW for clockwise" << endl;
	read_sensors();

}


void recovery1(){
	/*go_backwards(126);
	while(lfsensor == 0b000){
		read_sensors();
	}*/
	//stop();
	if(rstatus.last_white == 1){
		spin_right();
		//set_motors(10,50);
		while(lfsensor != 0b010){
			read_sensors();
		}
	}else {
		spin_left();
		//set_motors(50,10);
		while(lfsensor != 0b010){
			read_sensors();
		}
	}
	go_forwards(50);
}

void align_pickup(){
	cout << "Align for picking up" << endl;
	go_forwards(50);
	delay(825); // 700 for table 2 // 850 for table 1
	stop();
}
void align_assemble(){
	cout << "Align for assembling" << endl;
}

/*void follow_til_corner2(int T){
	cout << "Start follow_til_corner2" << endl;
	int t_start = watch.read();
	int time = watch.read() - t_start;
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
					cout << "FC2: need to recover... now BBB" << endl;
					recovery1();
					break;
				default:
					cout << "FC2: Sensors detect something unexpected!" << endl;
					stop();
					moving = false;
				
			}//ending of switch
		}// ending of if not 0b010
		else if(time > T){
			cout << "time exceeded corner type 2" << endl;
			go_forwards(126);
			while(true){
				read_sensors();
				if(lfsensor != 0b010){
					moving = false;
					cout << "detect a corner type 2" << endl;
					break;
				}
			};
		}
    }
}*/
