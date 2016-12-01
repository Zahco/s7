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

int aux_set_suppleance(trie *t, size_t prevNode, char c, size_t curNode) {
  if (t == NULL) {
    return -1;
  }
  if (curNode == 0 || prevNode == 0) {
    t->suppleance[curNode] = 0;
  }
  int tmpNode = -1;
  while (prevNode != 0 && tmpNode == -1) {
    tmpNode = get_transition(t->transition[t->suppleance[prevNode]], c);
    if (tmpNode == -1) {
      prevNode = t->suppleance[prevNode];
    } else {
      t->suppleance[curNode] = tmpNode;
      if (t->finite[tmpNode]) {
        t->finite[curNode] = 1;
      }
    }
  }
  list *l = t->transition[curNode];
  while (l != NULL) {
    aux_set_suppleance(t, curNode, l->letter, l->targetNode);
    l = l->next;
  }
  return 1;
}

int set_suppleance(trie *t) {
  return aux_set_suppleance(t, 0, 0, 0);
}

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

void print_trie(trie *t) {
  if (t == NULL) {
    return;
  }
  for (size_t i = 0; i < t->maxNode; ++i) {
    printf("[%zu] {", i);
    print_transition(t->transition[i]);
    printf(" } - %d\n", (int) t->finite[i]);
  }
  printf("\n[ ");
  for (size_t i = 0; i < t->maxNode; ++i) {
    printf("%zu ", t->suppleance[i]);
  }
  printf("]\n");
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



//faire avancer l'automate
size_t get_next_node(trie *t, size_t curNode, char c) {
  if (t == NULL) {
    return -1;
  }
  int node = 0;
  while ((node = get_transition(t->transition[curNode], c)) == -1 && curNode != 0) {
    curNode = t->suppleance[curNode];
  }

  return node == -1 ? curNode : (size_t)node;
}

int search(trie *t, char *text, size_t textlen) {
  size_t curNode = 0;
  for (size_t i = 0; i < textlen; ++i) {
    curNode = get_next_node(t, curNode, text[i]);
    if (t->finite[curNode]) {
      printf("occ: %zu\n", i);
    }
  }
  return 0;
}