CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror
LDFLAGS =
LDLIBS =
executable = main

all: $(executable)

main: main.o listes_adjacence.o
main.o: main.c listes_adjacence.h


matrice_transition.o: matrice_transition.c matrice_transition.h
listes_adjacence.o: listes_adjacence.c listes_adjacence.h

clean:
	$(RM) $(executable) *.o
