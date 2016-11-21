#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "text_generator.h"

int main(void) {
  time_t t;
  srand((unsigned) time(&t));
  size_t ylen = 3000;
  char *filename = "test_text_generator";
  
  ftext_generator(filename, ylen, 'Z');
  return EXIT_SUCCESS;
}
