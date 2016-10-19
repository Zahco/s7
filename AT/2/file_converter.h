#ifndef _FILE_CONVERTER_H
#define _FILE_CONVERTER_H

extern int file_to_string(const char *filename, char *output, size_t size);

extern int string_to_file(const char *filename, const char *input, size_t size);

#endif // _FILE_CONVERTER_H
