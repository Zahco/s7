#ifndef _LISTES_ADJACENCE_H
#define _LISTES_ADJACENCE_H

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
};

typedef struct trie trie;


extern trie *create_trie(int maxNode);
extern int insert_in_trie(trie *t, char *w);
extern int is_in_trie(trie *t, char *w);
extern void print_trie(trie *t);
extern void dispose_trie(trie **t);

extern void insert_prefixe(trie *t, char *w);
extern void insert_suffixe(trie *t, char *w);
extern void insert_facteur(trie *t, char *w);


#endif // _MATRICE_TRANSITION_H
