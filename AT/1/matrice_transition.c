#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "matrice_transition.h"


trie *create_trie(int maxNode) {
  if (maxNode < 1) {
    return NULL;
  }
  trie *t = malloc(sizeof(*t));
  if (t == NULL) {
    return NULL;
  }
  t->maxNode = maxNode;
  t->nextNode = 1;
  t->transition = malloc(sizeof(char *) * maxNode);
  if (t->transition == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxNode; ++i) {
    t->transition[i] = malloc(maxNode);
    if (t->transition[i] == NULL) {
      return NULL;
    }
  }
  t->finite = malloc(maxNode);
  t->nbWord = 0;
  return t;
}

int search_transition(trie *t, int node, char c) {
  for (int i = 0; i < t->maxNode; ++i) {
    if (t->transition[node][i] == c) {
      return i;
    }
  }
  return -1;
}

int insert_in_trie(trie *t, char *w) {
  if (t == NULL) {
    return -1;
  }
  int node = 0;
  int pt = 0;
  size_t i = 0;
  while (i < strlen(w) && (pt = search_transition(t, node, w[i])) != -1) {
    node = pt;
    ++i;
  }
  if ((int)(strlen(w) - i) > t->maxNode - t->nextNode) {
    return -1;
  }
  while (i < strlen(w)) {
    t->transition[node][t->nextNode] = w[i];
    ++i;
    node = t->nextNode;
    ++t->nextNode;
  }
  t->finite[t->nbWord] = node;
  ++t->nbWord;
  return 0;
}

int is_in_trie(trie *t, char *w) {
  if (t == NULL ||w == NULL) {
    return -1;
  }
  int p = 0;
  size_t i = 0;
  while (i < strlen(w) && (p = search_transition(t, p, w[i])) != -1) {
    ++i;
  }
  if (strlen(w) == i) {
    for (int j = 0; j < t->nbWord; ++i) {
      if (t->finite[j] == p) {
        return 1;
      }
    }
  }
  return 0;
}

void print_trie(trie *t) {
  for (int i = 0; i < t->maxNode; ++i) {
    for (int j = 0; j < t->maxNode; ++j) {
      printf("%c", t->transition[i][j] == 0 ? '*' : t->transition[i][j]);
    }
    printf("\n");
  }
}

void dispose_trie(trie **t) {
  if (*t == NULL) {
    return;
  }
  for (int i = 0; i < (*t)->maxNode; ++i) {
    free((*t)->transition[i]);
  }
  free((*t)->transition);
  free(*t);
  *t = NULL;
}

