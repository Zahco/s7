#include <stdlib.h>
#include <stdio.h>

#include "file_converter.h"


int file_to_string(const char *filename, char *output, size_t size) {
  FILE *f = fopen(filename, "r");
  size_t i = 0;
  while (i < size && !feof(f)) {
    output[i] = fgetc(f);
    ++i;
  }
  output[i - 1] = '\0';
  fclose(f);
  return i;
}

int string_to_file(const char *filename, const char *input, size_t size) {
  FILE *f = fopen(filename, "w");
  size_t i = 0;
  while (i < size) {
    fputc(input[i], f);
    ++i;
  }
  fclose(f);
  return i;
}
