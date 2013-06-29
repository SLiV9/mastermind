#
# Makefile voor Mastermind
#
# Sander in 't Veld, juni 2013
#


# programmas
P = main play

# object files
OB = code.o main.o play.o
O1 = code.o
OM = main.o $(O1)
OP = play.o $(O1)

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

# clean
clean:
	rm -f $(OB)
	rm -f $(P)

realclean:
	rm -f $(OB)
	rm -f $(P)
	rm -f *~
	
