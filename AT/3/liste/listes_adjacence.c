#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "listes_adjacence.h"

trie *create_trie(int maxNode) {
  if (maxNode < 1) {
    return NULL;
  }
  trie *t = malloc(sizeof(*t));
  if (t == NULL) {
    return NULL;
  }
  t->maxNode = maxNode;
  t->nextNode = 0;
  t->curNode = 0;
  
  t->transition = malloc(sizeof(list *) * maxNode);
  if (t->transition == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxNode; ++i) {
    t->transition[i] = NULL;
  }
  
  t->finite = malloc(maxNode);
  if (t->finite == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxNode; ++i) {
    t->finite[i] = 0;
  }
  
  t->suppleance = malloc(maxNode * sizeof(size_t));
  if (t->suppleance == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxNode; ++i) {
    t->suppleance[i] = 0;
  }
  
  return t;
}

int get_transition(list *l, char c) {
  if (l == NULL) {
    return -1;
  }
  if (l->letter == c) {
    return l->targetNode;
  }
  return get_transition(l->next, c);
}

int add_transition(trie *t, int node, char c) {
  if (t == NULL) {
    return -1;
  }
  list *l = malloc(sizeof(*l));
  if (l == NULL) {
    return -1;
  }
  l->letter = c;
  l->targetNode = t->nextNode;
  l->next = t->transition[node];
  t->transition[node] = l;
  return t->nextNode;
}

int insert_in_trie(trie *t, char *w) {
  if (t == NULL || w == NULL) {
    return -1;
  }
  int curNode = 0;
  int nextNode;
  size_t i = 0;
  while (i < strlen(w) 
    && (nextNode = get_transition(t->transition[curNode], w[i])) != -1) {
    curNode = nextNode;
    ++i;
  }
  size_t j = i;
  while (j < strlen(w) && t->nextNode < t->maxNode) {
    ++t->nextNode;
    add_transition(t, curNode, w[j]);
    curNode = t->nextNode;
    ++j;
  }
  t->finite[curNode] = 1;
  return curNode;
}

int set_suppleance(trie *t, size_t prevNode, char c, size_t curNode) {
  if (t == NULL) {
    return -1;
  }
  if (curNode == 0 || prevNode == 0) {
    t->suppleance[curNode] = 0;
  }
  size_t tmpNode = -1;
  while (prevNode != 0 && tmpNode == -1) {
    size_t tmpNode = get_transition(t->set_suppleance[prevNode], c);
    if (tmpNode == -1) {
      prevNode = t->set_suppleance[prevNode];
    } else {
      t->suppleance[curNode] = tmpNode;
    }
  }
  list *l = t->transition[curNode];
  while (l != NULL) {
    set_suppleance(t, curNode, l->letter, l->targetNode);
  }
}
/*
int is_in_trie(trie *t, char *w) {
  if (t == NULL || w == NULL) {
    return -1;
  }
  int nextNode = 0;
  for (size_t i = 0; i < strlen(w); ++i) {
    nextNode = get_transition(t->transition[nextNode], w[i]);
    if (nextNode == -1) {
      return 0;
    }
  }
  return t->finite[nextNode];
}

void print_transition(list *l) {
  if (l == NULL) {
    return;
  }
  printf(" [%zu, %c]", l->targetNode, l->letter);
  print_transition(l->next);
}
*/
void print_trie(trie *t) {
  if (t == NULL) {
    return;
  }
  for (size_t i = 0; i < t->maxNode; ++i) {
    printf("[%zu] {", i);
    print_transition(t->transition[i]);
    printf(" } - %d\n", (int) t->finite[i]);
  }
}

void dispose_transition(list *l) {
  if (l == NULL) {
    return;
  }
  dispose_transition(l->next);
  free(l);
}

void dispose_trie(trie **t) {
  if (t == NULL || *t == NULL) {
    return;
  }
  free((*t)->transition);
  free((*t)->finite);
  free((*t)->suppleance);
  free(*t);
  *t = NULL;
}
/*
void insert_prefixe(trie *t, char *w) {
  int l = strlen(w);
  char mot[l];
  strcpy(mot, w);
  for (int i = l; i > 0; --i) {
    mot[i] = '\0';
    insert_in_trie(t, mot);
  }
}

void insert_suffixe(trie *t, char *w) {
  int l = strlen(w);
  for (int i = 0; i < l; ++i) {
    printf("insert: %s\n", w + i);
    insert_in_trie(t, w + i);
  }
}

void insert_facteur(trie *t, char *w) {
  int l = strlen(w);
  for (int i = 0; i < l; ++i) {
    insert_suffixe(t, w + i);
  }
}
*/


























