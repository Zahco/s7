#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "search.h"

int max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int min(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}

int naif_i(const char *x, size_t xlen, const char *y, size_t ylen) {
  int nbocc = 0;
  for (size_t i = 0; i < ylen - xlen; ++i) {
    size_t j = 0;
    while (j < xlen && x[j] == y[i + j]) {
      ++j;
    }
    if (j == xlen) {
      printf("Occ : %zu\n", i);
      ++nbocc;
    }
  }
  return nbocc;
}

int naif_ir(const char *x, size_t xlen, const char *y, size_t ylen) {
  int nbocc = 0;
  char c = x[0];
  for (size_t i = 0; i < ylen - xlen; ++i) {
    if (c == y[i]) {
      size_t j = 1;
      while (j < xlen && x[j] == y[i + j]) {
        ++j;
      }
      if (j == xlen) {
        printf("Occ : %zu\n", i);
        ++nbocc;
      }
    }
  }
  return nbocc;
}


int naif_irs(const char *x, size_t xlen, const char *y, size_t ylen) {
  int nbocc = 0;
  char *ys = malloc(xlen + ylen);
  strcpy(ys, y);
  strcpy(ys + ylen, x);
  char c = x[0];
  size_t i = 0;
  while (1) {
    if (c == y[i]) {
      size_t j = 1;
      while (j < xlen && x[j] == y[i + j]) {
        ++j;
      }
      if (j == xlen) {
        ++nbocc;
        printf("Occ : %zu\n", i);
        if (i + j >= xlen + ylen) {
          return 0;
        }
      }
    }
    ++i;
  }
  return nbocc;
}


int naif_s(const char *x, size_t xlen, const char *y, size_t ylen) {
  int nbocc = 0;
  for (size_t i = 0; i < ylen - xlen; ++i) {
    if (strncmp(x + i, y, ylen) == 0) {
      printf("Occ : %zu\n", i);
      ++nbocc;
    }
  }
  return nbocc;
}

int naif_sr(const char *x, size_t xlen, const char *y, size_t ylen) {
  char c = x[0];
  int nbocc = 0;
  for (size_t i = 0; i < ylen - xlen; ++i) {
    if (c == y[i]) {
      if (strncmp(x + i, y, ylen) == 0) {
        printf("Occ : %zu\n", i);
        ++nbocc;
      }
    }
  }
  return nbocc;
}

int naif_srs(const char *x, size_t xlen, const char *y, size_t ylen) {
  char *ys = malloc(xlen + ylen);
  strcpy(ys, y);
  strcpy(ys + ylen, x);
  char c = x[0];
  size_t i = 0;
  int nbocc = 0;
  while (1) {
    if (c == y[i]) {
      if (strncmp(x + i, y, ylen) == 0) {
        printf("Occ : %zu\n", i);
        ++nbocc;
        if (i >= ylen - xlen) {
          return 0;
        }
      }
    }
    ++i;
  }
  return nbocc;
}

//MORIS-PRATT

int *bon_pref(const char *x, size_t xlen) {
  int *bp = malloc(sizeof(*bp) * xlen + 1);
  bp[0] = -1;
  int i = 0;
  for (size_t j = 1; j < xlen; ++j) {
    bp[j] = i;
    while (i >= 0 && x[i] != x[j]) {
      i = bp[i];
    }
    ++i;
  }
  bp[xlen] = i;
  return bp;
}

int moris_pratt(const char *x, size_t xlen, const char *y, size_t ylen) {
  int *bp = bon_pref(x, xlen);
  int i = 0;
  int nbocc = 0;
  for (size_t j = 0; j < ylen; ++j) {
    while (i >= 0 && x[i] != y[j]) {
      i = bp[i];
    }
    ++i;
    if (i == (int)xlen) {
      printf("Occ : %zu\n", j);
      ++nbocc;
      i = bp[i];
    }
  }
  free(bp);
  return nbocc;
}

//BOYER-MOORE

int *suffixe(const char *x, size_t xlen) {
  int *suff = malloc(sizeof(*suff) * xlen);
  int g = xlen - 1;
  int f = 0;
  suff[xlen - 1] = xlen;
  for (int i = xlen - 2; i >= 0; --i) {
    if (i > g && suff[i + xlen - 1 - f] != i - g) {
      suff[i] = min(suff[i + xlen - 1 - f], i - g);
    } else {
      g = min(i, g);
      f = i;
      while (g >= 0 && x[g] != x[g + xlen - 1 - f]) {
        --g;
      }
      suff[i] = f - g;
    }
  }
  return suff;
}

int *bon_suffixe(const char *x, size_t xlen) {
  int *bs = malloc(sizeof(*bs) * xlen);
  int *suff = suffixe(x, xlen);
  size_t i = 0;
  for (int j = xlen - 2; j >= -1; --j) {
    if (j == -1 || suff[j] == j + 1) {
      while (i < xlen - 1 - j) {
        bs[i] = xlen - 1 - j;
        ++i;
      }
    }
  }
  for (size_t j = 0; j < xlen - 1; ++j) {
    bs[xlen - 1 - suff[j]] = xlen - 1 - j;
  }
  free(suff);
  return bs;
}

int *dernocc(const char *x, size_t xlen) {
  int *docc = malloc(CHAR_MAX);
  for (size_t i = 0; i < CHAR_MAX; ++i) {
    docc[i] = xlen;
  }
  for (size_t i = 0; i < xlen; ++i) {
    docc[(size_t)x[i]] = xlen - 1 - i;
  }
  return docc;
}

int boyer_moore(const char *x, size_t xlen, const char *y, size_t ylen) {
  int *bs = bon_suffixe(x, xlen);
  int *docc = dernocc(x, xlen);
  int nbocc = 0;
  size_t j = xlen - 1;
  while (j < ylen) {
    int i = xlen - 1;
    while (i >= 0 && x[i] == y[j - xlen + 1 + i]) {
      --i;
    }
    if (i < 0) {
      printf("Occ : %zu\n", j);
      ++nbocc;
      j += bs[0];
    } else {
      j = max(bs[i], docc[y[j - xlen + 1 + i] - xlen + 1 + i]);
    }
  }
  free(docc);
  free(bs);
  return nbocc;
}

