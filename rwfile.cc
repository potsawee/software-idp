#include "header.h"
using namespace std;

void read_job_done(){
	string msg,msg2;
	ifstream ifstr;
	ifstr.open("jobdone");
	if(not ifstr.good()) {
		cout << "Couldn't open jobdone."  << endl;
		rstatus.job_done = 0; //in case there is something wrong, and jobdone can't be opened.
	}
	getline(ifstr, msg);
	getline(ifstr, msg2);
	char jd = msg[msg.length()-1]; // job done
	char gd = msg2[msg2.length()-1]; // job done
	
	switch(jd){
		case '0': rstatus.job_done = 0; break;
		case '1': rstatus.job_done = 1; break;
		case '2': rstatus.job_done = 2; break;
		case '3': rstatus.job_done = 3; break;
		case '4': rstatus.job_done = 4; break;
		default:
			cout << "Job_done is out of range" << endl;
			rstatus.job_done = 5;
			break;
	}
	switch(gd){
		case '0': rstatus.good_casting_done = 0; break;
		case '1': rstatus.good_casting_done = 1; break;
		case '2': rstatus.good_casting_done = 2; break;
		case '3': rstatus.good_casting_done = 3; break;
		default:
			cout << "Good_casting_done is out of range" << endl;
			rstatus.good_casting_done = 4;
			break;
	}
}
void write_job_done(){
	ofstream ofstr;
	ofstr.open("jobdone");
	if (not ofstr.good()) {
		cout  << "Can't open job_done to write"  << endl;
	}
	char jd = rstatus.job_done + '0'; // convert int job_done into char
	char gd = rstatus.good_casting_done + '0';
	ofstr << "job_done = ";
	ofstr <<  jd;
	ofstr <<  endl;
	ofstr << "good_casting_done = ";
	ofstr <<  gd;
	ofstr.close();
}
