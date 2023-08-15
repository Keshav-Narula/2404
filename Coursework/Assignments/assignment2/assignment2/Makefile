OBJ = main.o PhotoArray.o Album.o AlbumArray.o Photo.o Date.o Client.o PhotoGram.o TestControl.o TestView.o

all: a2
	
a2: $(OBJ)
	g++ -g -o  a2 $(OBJ) 
	
main.o:	main.cc TestControl.o
	g++ -c main.cc

PhotoArray.o:	defs.h PhotoArray.cc PhotoArray.h 
	g++ -c PhotoArray.cc
	
Album.o:	Album.h Album.cc 
	g++ -c Album.cc 

Photo.o:	Photo.h Photo.cc
	g++ -c Photo.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

AlbumArray.o:	AlbumArray.h AlbumArray.cc defs.h
	g++ -c AlbumArray.cc


PhotoGram.o:	PhotoGram.h PhotoGram.cc
	g++ -c PhotoGram.cc

Client.o:	Client.h Client.cc 
	g++ -c Client.cc

TestControl.o:	TestControl.h TestControl.cc 
	g++ -c TestControl.cc


TestView.o:	TestView.h TestView.cc
	g++ -c TestView.cc
	
clean:
	rm -f a2 *.o

