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
    for (int j = 0; j < maxNode; ++j) {
      t->transition[i][j] = 0;
    }
  }

  t->finite = malloc(maxNode * sizeof(int));
  if (t->finite == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxNode; ++i) {
    t->finite[i] = 0;
  }

  t->nbWord = 0;

  t->suppleance = malloc(maxNode * sizeof(int));
  if (t->suppleance == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxNode; ++i) {
    t->suppleance[i] = 0;
  }

  return t;
}

int get_transition(trie *t, int node, char c) {
  for (int i = 0; i < t->maxNode; ++i) {
    if (t->transition[node][i] == c) {
      return i;
    }
  }
  return -1;
}

int set_suppleance(trie *t) {
  if (t == NULL) {
    return -1;
  }
  for (int curNode = 1; curNode < t->maxNode; ++curNode) {
    for (int nextNode = 0; nextNode < t->maxNode; ++nextNode) {
      char c = t->transition[curNode][nextNode];
      if (c != 0) {
        int tmpNode = -1;
        int prevNode = curNode;
        while (prevNode != 0 && tmpNode == -1) {
          tmpNode = get_transition(t, t->suppleance[prevNode], c);
          if (tmpNode == -1) {
            prevNode = t->suppleance[prevNode];
          } else {
            t->suppleance[nextNode] = tmpNode;
            if (t->finite[tmpNode]) {
              ++t->finite[nextNode];
            }
          }
        }
      }
    }
  }
  return 1;
}

int insert_in_trie(trie *t, char *w) {
  if (t == NULL) {
    return -1;
  }
  int node = 0;
  int pt = 0;
  size_t i = 0;
  while (i < strlen(w) && (pt = get_transition(t, node, w[i])) != -1) {
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
  t->finite[t->nextNode - 1] = 1;
  ++t->nbWord;
  return 0;
}

int is_in_trie(trie *t, char *w) {
  if (t == NULL ||w == NULL) {
    return -1;
  }
  int p = 0;
  size_t i = 0;
  while (i < strlen(w) && (p = get_transition(t, p, w[i])) != -1) {
    ++i;
  }
  if (strlen(w) == i) {
    for (int j = 0; j < t->maxNode; ++i) {
      if (t->finite[p]) {
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
  printf("\n[ ");
  for (int i = 0; i < t->maxNode; ++i) {
    printf("%d ", t->suppleance[i]);
  }
  printf("]\n");
  printf("\n[ ");
  for (int i = 0; i < t->maxNode; ++i) {
    printf("%d ", t->finite[i]);
  }
  printf("]\n");
}

void dispose_trie(trie **t) {
  if (*t == NULL) {
    return;
  }
  for (int i = 0; i < (*t)->maxNode; ++i) {
    free((*t)->transition[i]);
  }
  free((*t)->transition);
  free((*t)->suppleance);
  free((*t)->finite);
  free(*t);
  *t = NULL;
}


//faire avancer l'automate
size_t get_next_node(trie *t, size_t curNode, char c) {
  if (t == NULL) {
    return -1;
  }
  int node = 0;
  while ((node = get_transition(t, curNode, c)) == -1 && curNode != 0) {
    curNode = t->suppleance[curNode];
  }

  return node == -1 ? curNode : (size_t)node;
}

int search(trie *t, char *text, size_t textlen) {
  int count = 0;
  size_t curNode = 0;
  for (size_t i = 0; i < textlen; ++i) {
    curNode = get_next_node(t, curNode, text[i]);
    if (t->finite[curNode]) {
      count += t->finite[curNode];
    }
  }
  return count;
}