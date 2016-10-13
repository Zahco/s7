#ifndef _TEXT_GENERATOR_H
#define _TEXT_GENERATOR_H

#define MIN_CARAC 'A'

extern int text_generator(FILE *file, size_t textlen, size_t alphalen);
extern int ftext_generator(const char *filename, size_t textlen, size_t alphalen);

extern int words_generator(FILE *file, size_t wordlen, size_t nbword, size_t alphalen);
extern int fwords_generator(const char *filename, size_t wordlen, size_t nbword, size_t alphalen);

#endif // _TEXT_GENERATOR_H