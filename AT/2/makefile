CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror
LDFLAGS =
LDLIBS =
executable = main

all: $(executable)

main: main.o text_generator.o
main.o: main.c text_generator.h


text_generator.o: text_generator.c text_generator.h

clean:
	$(RM) $(executable) *.o
