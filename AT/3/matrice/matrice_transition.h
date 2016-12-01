#ifndef _MATRICE_TRANSITION_H
#define _MATRICE_TRANSITION_H

struct _trie {
  int maxNode;
  int nextNode;
  char **transition;
  int *finite;
  int nbWord;

  int *suppleance;
};

typedef struct _trie trie;

extern trie *create_trie(int maxNode);

extern int insert_in_trie(trie *t, char *w);

extern int set_suppleance(trie *t);

extern void print_trie(trie *t);

extern int is_in_trie(trie *t, char *w);

extern void dispose_trie(trie **t);

extern int search(trie *t, char *text, size_t textlen);

#endif // _MATRICE_TRANSITION_H
