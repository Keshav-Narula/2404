OBJECTS = main.o Battle.o Board.o Character.o Wizard.o Hero.o Orc.o Swing.o 

p7: $(OBJECTS)
	g++ -o p7 $(OBJECTS)

main.o:	main.cc Battle.h defs.h
	g++ -c main.cc

Battle.o:	Battle.cc Battle.h defs.h
	g++ -c Battle.cc

Board.o:	Board.cc Board.h defs.h
	g++ -c Board.cc

Character.o:	Character.cc Character.h defs.h
	g++ -c Character.cc

Wizard.o:	Wizard.cc Wizard.h defs.h
	g++ -c Wizard.cc

Hero.o:	Hero.cc Hero.h defs.h
	g++ -c Hero.cc

Orc.o:	Orc.cc Orc.h defs.h
	g++ -c Orc.cc


Swing.o: Swing.cc Swing.h 
	g++ -c Swing.cc

clean:
	rm -f *.o p7