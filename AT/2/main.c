#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "text_generator.h"
#include "search.h"
#include "file_converter.h"

int main(void) {
  time_t t;
  srand((unsigned) time(&t));
  size_t ylen = 3000;
  char *filename = "test_text_generator";
  
  ftext_generator(filename, ylen, 'Z');
  char text[ylen];
  file_to_string(filename, text, ylen);
  
  printf("Nombre d'occurence: %d\n", naif_i("AA", 2, text, ylen));
  return EXIT_SUCCESS;
}
