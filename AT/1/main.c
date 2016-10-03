#include <stdlib.h>
#include <stdio.h>

#include "listes_adjacence.h"

int main(void) {
  
  trie *t = create_trie(50);
  insert_facteur(t, "mots");
  print_trie(t);
  printf("Test: %d\n", is_in_trie(t, "mots"));
  dispose_trie(&t);
  return EXIT_SUCCESS;
}
