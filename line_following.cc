#include "header.h"



void ajust_initial_position(){
	go_backwards(100); //*adjust initial position 
	delay(500);
	stop();
}

void read_sensors(){
    rsensor.left = (rlink.command(READ_PORT_5) && 0x04) >> 2;
    rsensor.mid = (rlink.command(READ_PORT_5) && 0x02) >> 1;
    rsensor.right = (rlink.command(READ_PORT_5) && 0x04);
}
	
void follow_line_count_when_pass_junc() //the sensor will send several values when passing one junction! so use time to control that.
{
	//(punpun) I think we don't need a function for this. When it detect WWW,
	
}

void follow_line_til_junc(){
    go_forward(126);
    while(true){
        read_sensors();
        if(rsensor.left != B or rsensor.mid != W or rsensor.right != B){
            if (rsensor.left == W or rsensor.mid == W or rsensor.right == B){
                //try to go left
            } else if(rsensor.left == B or rsensor.mid == B or rsensor.right == W){
                //try to go right
            } else if (rsensor.left == W and rsensor.mid == W and rsensor.right == W) {
                stop();
                rstatus.junctions_passed++;
                cout << "Detect a junction" << endl;
                break;
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
	
	
	
} //move forwards/backwards a a little bit and turn_right, after the sensor detected the junction and the robot stopped.
void follow_turn_left()
{
	
	
	
	
} //move forwards/backwards a a little bit and turn_left,, after the sensor detected the junction and the robot stopped.
