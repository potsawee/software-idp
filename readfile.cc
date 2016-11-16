include "header.h"
using namespace std;

void read_job_done(){
	string msg;
	ifstream ifstr;
	ifstr.open("jobdone");
	if(not ifstr.good()) {
		cout << "Couldn't open jobdone."  << endl;
		rstatus.job_done = 0; //in case there is something wrong, and jobdone can't be opened.
	}
	getline(ifstr, msg);
	char jb = msg[msg.length()-1];
	switch(jb){
		case '0': rstatus.job_done = 0; break;
		case '1': rstatus.job_done = 1; break;
		case '2': rstatus.job_done = 2; break;
		case '3': rstatus.job_done = 3; break;
		default:
			cout << "Job_done is out of range" << endl;
			rstatus.job_done = 0;
			break;
	}
}
void write_job_done(){
	ofstream ofstr;
	ofstr1.open("jobdone");
	if (not ofstr.good()) {
		cout  << "Can't open job_done to write"  << endl;
	}
	char jd = rstatus.job_done + '0'; // convert int job_done into char
	ofstr << "job_done = ";
	ofstr <<  jd;
	cout << "Job done = " << job_done << " finished writing to the file." << endl;
	ofstr.close();
}
