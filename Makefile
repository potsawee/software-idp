# Automatically generated Makefile
test2 :  test2.o movements.o mechanisms.o line_following.o
	 g++ -L/export/teach/1BRobot -o test2  test2.o  movements.o  mechanisms.o  line_following.o  -lrobot

test2.o: test2.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c test2.cc
movements.o: movements.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c movements.cc
mechanisms.o: mechanisms.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c mechanisms.cc
line_following.o: line_following.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c line_following.cc
