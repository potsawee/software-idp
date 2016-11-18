# Automatically generated Makefile
test :  test.o movements.o line_following.o
	 g++ -L/export/teach/1BRobot -o test  test.o  movements.o  line_following.o  -lrobot

test.o: test.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c test.cc
movements.o: movements.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c movements.cc
line_following.o: line_following.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c line_following.cc
