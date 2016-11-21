CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror
LDFLAGS =
LDLIBS =
executable = ac-liste ac-matrice ac-mixte

all: $(executable)
	cd text_generator; make

ac-liste: liste/ac-liste.o liste/listes_adjacence.o file_converter/file_converter.o
	cc liste/ac-liste.o liste/listes_adjacence.o file_converter/file_converter.o -o ac-liste

liste/ac-liste.o: liste/ac-liste.c liste/listes_adjacence.h file_converter/file_converter.h
liste/listes_adjacence.o: liste/listes_adjacence.c liste/listes_adjacence.h

ac-matrice: matrice/ac-matrice.o matrice/matrice_transition.o file_converter/file_converter.o
	cc matrice/ac-matrice.o matrice/matrice_transition.o file_converter/file_converter.o -o ac-matrice 

matrice/ac-matrice.o: matrice/ac-matrice.c matrice/matrice_transition.h file_converter/file_converter.h
matrice/matrice_transition.o: matrice/matrice_transition.c matrice/matrice_transition.h

ac-mixte: mixte/ac-mixte.o mixte/mixte.o file_converter/file_converter.o
	cc mixte/ac-mixte.o mixte/mixte.o file_converter/file_converter.o -o ac-mixte

mixte/ac-mixte.o: mixte/ac-mixte.c mixte/mixte.h file_converter/file_converter.h
mixte/mixte.o: mixte/mixte.c mixte/mixte.h

file_converter/file_converter.o: file_converter/file_converter.c file_converter/file_converter.h



clean:
	$(RM) $(executable) liste/*.o matrice/*.o mixte/*.o file_converter/*.o
	cd text_generator; make clean
