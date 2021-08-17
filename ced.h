#ifndef PHP_CED_CED_H
#define PHP_CED_CED_H

#include <stdbool.h>

const char *ced_detect_encoding(const char *text, int text_length, bool allow_utf8utf8);
const char *ced_version();

#endif
