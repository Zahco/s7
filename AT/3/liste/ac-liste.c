#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "listes_adjacence.h"
#include "../file_converter/file_converter.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    return EXIT_FAILURE;
  }
  char *mots = argv[1];
  char *text = argv[2];

  //Insertion des mots dans le trie
  FILE *fmots = fopen(mots, "r");
  if (fmots == NULL) {
    return EXIT_FAILURE;
  }
  fseek(fmots, 0, SEEK_END);
  long size = ftell(fmots);
  fseek(fmots, 0, SEEK_SET);
  trie *tr = create_trie(size);
  while(!feof(fmots)) {
    char mot[255];
    fscanf(fmots, "%s", mot);
    insert_in_trie(tr, mot);
  }
  fclose(fmots);

  set_suppleance(tr);
  //print_trie(tr);

  //Convertion du fichier de text en char*
  FILE *ftext = fopen(text, "r");
  if (ftext == NULL) {
    return EXIT_FAILURE;
  }
  fseek(ftext, 0, SEEK_END);
  size = ftell(ftext);
  fclose(ftext);
  char textbuf[size];
  file_to_string(text, textbuf, size);

  clock_t d = clock();
  int count = search(tr, textbuf, strlen(textbuf));
  clock_t fi = clock();
  printf("Nombre d'occurences: %d", count);

  float t = (float) (fi - d)/CLOCKS_PER_SEC;
  printf(" en %fs\n", t);

  dispose_trie(&tr);
  return EXIT_SUCCESS;
}
