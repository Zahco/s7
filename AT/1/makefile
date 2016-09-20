CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror
LDFLAGS =
LDLIBS =
executable = main

all: $(executable)

main: main.o matrice_transition.o
main.o: main.c matrice_transition.h


matrice_transition.o: matrice_transition.c matrice_transition.h

clean:
	$(RM) $(executable) *.o
