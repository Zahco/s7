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
  char *ys = malloc(xlen + ylen - 1);
  strcpy(ys, y);
  strcpy(ys + ylen - 1, x);
  char c = x[0];
  size_t i = 0;
  while (1) {
    if (c == ys[i]) {
      size_t j = 1;
      while (j < xlen && x[j] == ys[i + j]) {
        ++j;
      }
      if (j == xlen) {
        ++nbocc;
        printf("Occ : %zu\n", i);
        if (i + j >= xlen + ylen - 1) {
          return nbocc;
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

//KNUTH-MORIS-PRATT
int *meil_pref(const char *x, size_t xlen) {
  int *bp = bon_pref(x, xlen);
  int *mp = malloc(sizeof(*mp) * xlen + 1);
  mp[0] = -1;
  for (size_t i = 1; i < xlen + 1; ++i) {
    if (x[i] == x[bp[i]]) {
      mp[i] = mp[bp[i]];
    } else {
      mp[i] = bp[i];
    }
  }
  free(bp);
  return mp;
}

int knuth_moris_pratt(const char *x, size_t xlen, const char *y, size_t ylen) {
  int *mp = meil_pref(x, xlen);
  int i = 0;
  int nbocc = 0;
  for (size_t j = 0; j < ylen; ++j) {
    while (i >= 0 && x[i] != y[j]) {
      i = mp[i];
    }
    ++i;
    if (i == (int)xlen) {
      printf("Occ : %zu\n", j);
      ++nbocc;
      i = mp[i];
    }
  }
  free(mp);
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
      while (g >= 0 && x[g] == x[g + xlen + 1 - f]) {
        --g;
      }
      suff[i] = f - g;
    }
  }
  return suff;
}

int *bon_suffixe(const char *x, size_t xlen) {
  int *bs = malloc(xlen);
  int *suff = suffixe(x, xlen);
 
  for (size_t i = 0; i < xlen; ++i){
    bs[i] = xlen;
  }
  for (int i = xlen - 1; i >= 0; --i) {
    if (suff[i] == i + 1) {
     for (size_t j = 0; j < xlen - 1 - i; ++j) {
        if (bs[j] == (int)xlen) {
          bs[j] = xlen - 1 - i;
        }
      }
    }
  }
  for (size_t i = 0; i <= xlen - 2; ++i) {
    bs[xlen - 1 - suff[i]] = xlen - 1 - i;
  }
  free(suff);
  return bs;
}

int *dernocc(const char *x, size_t xlen) {
  int *docc = malloc(CHAR_MAX * sizeof(int));
  for (size_t i = 0; i < CHAR_MAX; ++i) {
    docc[i] = xlen;
  }
  for (size_t i = 0; i < xlen - 1; ++i) {
    docc[(size_t)x[i]] = xlen - 1 - i;
  }
  return docc;
}

int boyer_moore(const char *x, size_t xlen, const char *y, size_t ylen) {
  int *bs = bon_suffixe(x, xlen);
  int *docc = dernocc(x, xlen);
  int nbocc = 0;
  size_t j = 0;
  while (j < ylen) {
    int i = xlen - 1;
    while (i >= 0 && x[i] == y[j + i]) {
      --i;
    }
    if (i < 0) {
      printf("Occ : %zu\n", j);
      ++nbocc;
      j += bs[0];
    } else {
      j += max(bs[i], docc[y[j + i] - xlen + 1 + i]);
    }
  }
  free(docc);
  free(bs);
  return nbocc;
}

//HORSPOOL

int horspool(const char *x, size_t xlen, const char *y, size_t ylen) {
  int *occ = malloc(CHAR_MAX * sizeof(int));
  for (size_t i = 0; i < CHAR_MAX; ++i) {
    occ[i] = xlen;
  }
  for (size_t i = 0; i < xlen - 1; ++i) {
    occ[(size_t)x[i]] = xlen - 1 - i;
  }
  int nbocc = 0;
  for (const char *q = y; q < y + ylen - xlen + 1; q += occ[(size_t)q[xlen - 1]]) {
    if (memcmp(x, q, xlen) == 0) {
      printf("Occ : %zu\n", q - y);
      ++nbocc;
    }
  }
  free(occ);
  return nbocc;
}


//QUICK SEARCH

int quick_search(const char *x, size_t xlen, const char *y, size_t ylen) {
  int *occ = malloc(CHAR_MAX * sizeof(int));
  for (size_t i = 0; i < CHAR_MAX; ++i) {
    occ[i] = xlen + 1;
  }
  for (size_t i = 0; i < xlen; ++i) {
    occ[(size_t)x[i]] = xlen - i;
  }
  int nbocc = 0;
  for (const char *q = y; q < y + ylen - xlen; q += occ[(size_t)q[xlen]]) {
    if (memcmp(x, q, xlen) == 0) {
      printf("Occ : %zu\n", q - y);
      ++nbocc;
    }
  }
  free(occ);
  return nbocc;
}













