//// Functions in routes.cc ////


//// Functions in mechanisms.cc ////


//// Functions in line_following.cc ////


//// Functions in movements.cc ////





//// Enums & Classes ////
enum casting_type {
	GOOD = 1,
	HOT,
	FLASHING
};
enum location {
	S = 0,
	D1,
	D2,
	D3,
	DF,
	DH,
	P
};

class robot_status {
	public:
		casting_type casting;
		int job_done;
		location destination;
}


///// Global Variables /////
extern robot_link rlink; 
extern stopwatch watch;
extern robot_status rstatus;




