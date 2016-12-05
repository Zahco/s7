#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "text_generator.h"

int main(int argc, char *argv[]) {
  if (argc != 5) {
    return EXIT_FAILURE;
  }
  time_t t;
  srand((unsigned) time(&t));
  char *output = argv[1];
  size_t wordlen = atoi(argv[3]);
  size_t nbword = atoi(argv[2]);
  size_t alphalen = atoi(argv[4]);


  fwords_generator(output, wordlen, nbword, alphalen);
  return EXIT_SUCCESS;
}
