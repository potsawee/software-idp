# Automatically generated Makefile
testroute1 :  testroute1.o routes.o movements.o mechanisms.o line_following.o
	 g++ -L/export/teach/1BRobot -o testroute1  testroute1.o  routes.o  movements.o  mechanisms.o  line_following.o  -lrobot

testroute1.o: testroute1.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c testroute1.cc
routes.o: routes.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c routes.cc
movements.o: movements.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c movements.cc
mechanisms.o: mechanisms.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c mechanisms.cc
line_following.o: line_following.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c line_following.cc
