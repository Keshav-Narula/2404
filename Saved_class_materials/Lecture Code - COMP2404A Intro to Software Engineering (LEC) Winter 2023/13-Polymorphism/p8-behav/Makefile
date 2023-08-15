p8:	main.o Animals.o DanceBehaviour.o
	g++ -o p8 main.o Animals.o DanceBehaviour.o

main.o:	main.cc Animals.h
	g++ -c main.cc

Animals.o:	Animals.cc Animals.h
	g++ -c Animals.cc

DanceBehaviour.o:	DanceBehaviour.cc DanceBehaviour.h
	g++ -c DanceBehaviour.cc

clean:
	rm -f *.o p8
