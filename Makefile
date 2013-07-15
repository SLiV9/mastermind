#
# Makefile voor Mastermind
#
# Sander in 't Veld, juni 2013
#


# programmas
P = main play

# object files
O1 = code.o dlist.o ai.o randy.o jimmy.o philip.o
OM = main.o $(O1)
OP = play.o $(O1)
OB = main.o play.o $(O1)

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = 

# make
main: $(OM)
	gcc $(OM) -o main $(LFLAGS)
	
play: $(OP)
	gcc $(OP) -o play $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c
	
play.o: play.c
	gcc -c $(CFLAGS) play.c
	
code.o: code.c evaluate.c
	gcc -c $(CFLAGS) code.c
	
dlist.o: dlist.c
	gcc -c $(CFLAGS) dlist.c
	
ai.o: ai.c
	gcc -c $(CFLAGS) ai.c
	
randy.o: randy.c
	gcc -c $(CFLAGS) randy.c
jimmy.o: jimmy.c
	gcc -c $(CFLAGS) jimmy.c
philip.o: philip.c
	gcc -c $(CFLAGS) philip.c

# clean
clean:
	rm -f $(OB)
	rm -f $(P)

realclean:
	rm -f $(OB)
	rm -f $(P)
	rm -f *~
	
