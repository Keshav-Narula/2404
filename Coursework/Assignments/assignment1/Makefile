all: a1

a1: main.o Hotel.o Room.o Date.o Reservation.o 
	g++ -o a1 main.o Date.o Room.o Reservation.o Hotel.o -g

main.o:	main.cc defs.h
	g++ -c main.cc

Hotel.o: Hotel.h Hotel.cc
	g++ -c Hotel.cc

Date.o: Date.h Date.cc
	g++ -c Date.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Room.o: Room.h Room.cc
	g++ -c Room.cc

clean:
	rm -f a1 *.o
