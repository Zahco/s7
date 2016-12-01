#ifndef _MIXTE_H
#define _MIXTE_H

#include <limits.h>

struct list {
  size_t targetNode;
  char letter;
  struct list *next;
};

typedef struct list list;

struct trie {
  size_t maxNode;
  size_t nextNode;
  list **transition;
  char *finite;
  int firstNode[CHAR_MAX];

  size_t *suppleance;
};

typedef struct trie trie;


extern trie *create_trie(int maxNode);
extern int insert_in_trie(trie *t, char *w);
//extern int is_in_trie(trie *t, char *w);
extern void print_trie(trie *t);
extern void dispose_trie(trie **t);

extern int set_suppleance(trie *t);
extern int search(trie *t, char *text, size_t textlen);


#endif // _MIXTE_H
