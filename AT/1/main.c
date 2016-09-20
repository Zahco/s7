#include <stdlib.h>
#include <stdio.h>

#include "matrice_transition.h"

int main(void) {
  
  trie *t = create_trie(10);
  printf("Retour: %d\n", insert_in_trie(t, "mot"));
  printf("Retour: %d\n", insert_in_trie(t, "momo"));
  print_trie(t);
  printf("Test: %d\n", is_in_trie(t, "mots"));
  dispose_trie(&t);
  return EXIT_SUCCESS;
}
