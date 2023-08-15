all: p1

p1: p1.cc Student.o #p1.o Student.o
	g++ -o p1 p1.cc Student.o

Student.o: Student.h Student.cc #Any changes in student.h or student.cc recompile the object file
	g++ -c Student.cc
	
clean:
	rm -f p1 *.o