#ifndef IMMEDIATE_H
#define IMMEDIATE_H

#include <stdint.h>
#include <stdlib.h>
typedef int64_t immediate_t;

immediate_t lex_immediate(const char* immediate_string);


#endif