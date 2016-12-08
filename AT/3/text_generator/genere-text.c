#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "text_generator.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    return EXIT_FAILURE;
  }
  time_t t;
  srand((unsigned) time(&t));
  char *output = argv[1];
  size_t textlen = atoi(argv[2]);
  size_t alphalen = atoi(argv[3]);

  ftext_generator(output, textlen, alphalen);
  return EXIT_SUCCESS;
}
