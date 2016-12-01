#include "header.h"
using namespace std;

void read_thermistor(){// tsensor = 1 means temp > 30 deg
	int s = rlink.request(READ_PORT_5);
	rstatus.tsensor = (s bitand 0b10000)/16;
	cout << rstatus.tsensor << endl; 
}

void defect_testing(){
    rstatus.defect_indicator=0;// to be changed
}

void grab_object(){  //to use actuator, front motors to grab an object, and thermistor , to detect whether it has a defect, to find the orientation, to measure if its temperature is more than 30 deg.


                   

read_thermistor();
defect_testing();

//using the switches
/*
		int sw = rlink.request(READ_PORT_2);
		int s1 = sw bitand 0b10;
		int s2 = sw bitand 0b100;*/


}

void rotate_grabber(int t, rotation R){
    int x = 0;
    if(R == ACW) // not sure which way is ACW.
        x += 0x80;
    rlink.command (RAMP_TIME,0);
    rlink.command(MOTOR_4_GO, 127 + x); // at the maximum speed
    delay(t);
    rlink.command(MOTOR_4_GO, 0);
    cout << "Rotate the grabber for " << t << " ms." << endl;
}

void grabber_closed(){
	rlink.command (WRITE_PORT_2, 0b00000000);
	cout << "grabber closed" << endl;
}

void grabber_open(){
	rlink.command (WRITE_PORT_2, 0b10000000);
	cout << "grabber open" << endl;
}

/* THIS is for the ultrasonic sensors.
		int r = rlink.request(READ_PORT_2);
		//int a = r bitand 0b1000000; // closest distance  7th
		//int b = r bitand 0b100000; // 2nd most           6th
		int c = r bitand 0b10000;
*/
/* using grabber open / closed instead.
void set_actuator(int n){
    if(n == 1){
        rlink.command (WRITE_PORT_2, 0b10000000);
        cout << "Set the actuator = 1" << endl;
    }else if(n == 0){
        rlink.command (WRITE_PORT_2, 0b00000000);
        
    }
	//most significant bit at 010
}*/
