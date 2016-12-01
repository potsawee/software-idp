# Automatically generated Makefile
main :  rwfile.o routes.o movements.o mechanisms.o main.o line_following.o
	 g++ -L/export/teach/1BRobot -o main  rwfile.o  routes.o  movements.o  mechanisms.o  main.o  line_following.o  -lrobot

rwfile.o: rwfile.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c rwfile.cc
routes.o: routes.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c routes.cc
movements.o: movements.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c movements.cc
mechanisms.o: mechanisms.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c mechanisms.cc
main.o: main.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c main.cc
line_following.o: line_following.cc header.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c line_following.cc
