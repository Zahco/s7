#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "mixte.h"

int main(void) {
  trie *t = create_trie(10);
  insert_in_trie(t, "abaab");
  insert_in_trie(t, "aa");
  insert_in_trie(t, "bba");
  set_suppleance(t);
  print_trie(t);
  search(t, "abbaabaabababababababaa", 23);
  dispose_trie(&t);
  return EXIT_SUCCESS;
}
