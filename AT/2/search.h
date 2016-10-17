#ifndef SEARCH_H
#define SEARCH_H

extern int naif_i(const char *x, size_t xlen, const char *y, size_t ylen);
extern int naif_ir(const char *x, size_t xlen, const char *y, size_t ylen);
extern int naif_irs(const char *x, size_t xlen, const char *y, size_t ylen);

extern int naif_s(const char *x, size_t xlen, const char *y, size_t ylen);
extern int naif_sr(const char *x, size_t xlen, const char *y, size_t ylen);
extern int naif_srs(const char *x, size_t xlen, const char *y, size_t ylen);

extern int moris_pratt(const char *x, size_t xlen, const char *y, size_t ylen);

extern int boyer_moore(const char *x, size_t xlen, const char *y, size_t ylen);

#endif // SEARCH_H
