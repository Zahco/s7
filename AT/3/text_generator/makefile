CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror
LDFLAGS =
LDLIBS =
executable = genere-text genere-mots

all: $(executable)

genere-text: genere-text.o text_generator.o
genere-text.o: genere-text.c text_generator.h

genere-mots: genere-mots.o text_generator.o
genere-mots.o: genere-mots.c text_generator.h

text_generator.o: text_generator.c text_generator.h

clean:
	$(RM) $(executable) *.o
