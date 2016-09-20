#ifndef _MATRICE_TRANSITION_H
#define _MATRICE_TRANSITION_H

struct _trie {
  int maxNode;
  int nextNode;
  char **transition;
  int *finite;
  int nbWord;
};

typedef struct _trie trie;

extern trie *create_trie(int maxNode);

extern int insert_in_trie(trie *t, char *w);

extern void print_trie(trie *t);

extern int is_in_trie(trie *t, char *w);

extern void dispose_trie(trie **t);

#endif // _MATRICE_TRANSITION_H
