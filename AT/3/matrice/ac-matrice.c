#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "matrice_transition.h"
#include "../file_converter/file_converter.h"

int main(void) {
  trie *t = create_trie(40);
  FILE *f = fopen("mots", "r");
  while(!feof(f)) {
    char mot[255];
    fscanf(f, "%s", mot);
    insert_in_trie(t, mot);
  }
  set_suppleance(t);
  print_trie(t);
  size_t size = 100000;
  char text[size];
  file_to_string("texte", text, size);
  int count = search(t, text, strlen(text));
  printf("\nCount: %d\n\n", count);

  dispose_trie(&t);
  return EXIT_SUCCESS;
}