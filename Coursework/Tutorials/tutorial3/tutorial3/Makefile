all: test1 test2

test1: Room.o Date.o Reservation.o test1.cc
	g++ -Wall -o test1 Reservation.o Date.o Room.o test1.cc

test2: Room.o Date.o Reservation.o test2.cc
	g++ -Wall -o test2 Date.o Reservation.o Room.o test2.cc

Date.o: Date.h Date.cc
	g++ -Wall -c Date.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -Wall -c Reservation.cc

Room.o: Room.h Room.cc
	g++ -Wall -c Room.cc

clean:
	rm -f test1 test2 *.o
