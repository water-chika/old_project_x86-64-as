#include "immediate.h"

immediate_t lex_immediate(const char* immediate_string)
{
    char* tail;
    immediate_t imm = strtoll(immediate_string, &tail, 10);
    return imm;
}