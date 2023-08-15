TARGETS = p2in p2out

all:	$(TARGETS)

p2out:	out.o Student.o
	g++ -o p2out out.o Student.o

p2in:	in.o Student.o
	g++ -o p2in in.o Student.o

in.o:	in.cc Student.h 
	g++ -c in.cc

out.o:	out.cc Student.h 
	g++ -c out.cc

Student.o:	Student.cc Student.h
	g++ -c Student.cc

clean:
	rm -f *.o $(TARGETS)

sclean:
	rm -f *.o $(TARGETS) students.txt
