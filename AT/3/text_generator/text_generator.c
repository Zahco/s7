#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "text_generator.h"

char random_carac(size_t min, size_t max) {
  return (char)(min + (rand() % (max - min + 1)));
}

int text_generator(FILE *file, size_t textlen, size_t alphalen) {
  for (size_t i = 0; i < textlen; ++i) {
    char c = random_carac(MIN_CARAC, MIN_CARAC + alphalen - 1);
    fputc(c, file);
  }
  return 0;
}

int words_generator(FILE *file, size_t wordlen, size_t nbword, size_t alphalen) {
  for (size_t i = 0; i < nbword; ++i) {
    text_generator(file, wordlen, alphalen);
    fputc(' ', file);
  }
  return 0;
}

FILE *_open_file(const char *filename) {
  return fopen(filename, "w");
}

int ftext_generator(const char *filename, size_t textlen, size_t alphalen) {
  FILE *file = _open_file(filename);
  int ret = text_generator(file, textlen, alphalen);
  fclose(file);
  return ret;
}

int fwords_generator(const char *filename, size_t wordlen, size_t nbword, size_t alphalen) {
  FILE *file = _open_file(filename);
  int ret = words_generator(file, wordlen, nbword, alphalen);
  fclose(file);
  return ret;
}
