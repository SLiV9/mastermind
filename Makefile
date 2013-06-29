#
# Makefile voor Mastermind
#
# Sander in 't Veld, juni 2013
#


# programmas
P = main

# object files
O1 = main.o code.o

# flags
CFLAGS = -std=gnu99 -Wall
LFLAGS = 

# make
main: $(O1)
	gcc $(O1) -o $(P) $(LFLAGS)

# make object files
main.o: main.c
	gcc -c $(CFLAGS) main.c
	
code.o: code.c
	gcc -c $(CFLAGS) code.c

# clean
clean:
	rm -f $(O1)
	rm -f $(P)

realclean:
	rm -f $(O1)
	rm -f $(P)
	rm -f *~
	
