CFLAGS = -Wall -Wextra -pedantic -std=c11 -Werror
LDFLAGS =
LDLIBS =
executable = main

all: $(executable)

main: main.o text_generator.o search.o file_converter.o
main.o: main.c text_generator.h search.h file_converter.h


text_generator.o: text_generator.c text_generator.h
search.o: search.c search.h
file_converter.o: file_converter.c file_converter.h

clean:
	$(RM) $(executable) *.o
