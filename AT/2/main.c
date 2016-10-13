#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "text_generator.h"

int main(void) {
  time_t t;
  srand((unsigned) time(&t));
  ftext_generator("test_text_generator", 300, 'z');
  fwords_generator("test_words_generator", 6, 100, 'z');
  return EXIT_SUCCESS;
}