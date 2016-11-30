# Automatically generated Makefile
testroute1 :  testroute1.o mechanisms.o
	 g++ -L/export/teach/1BRobot -o testroute1  testroute1.o  mechanisms.o  -lrobot

testroute1.o: testroute1.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c testroute1.cc
mechanisms.o: mechanisms.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c mechanisms.cc
