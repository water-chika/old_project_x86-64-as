#ifndef REGISTER_H
#define REGISTER_H
#include <search.h>
typedef enum
{
    REGISTER_AX,
    REGISTER_CX,
    REGISTER_DX,
    REGISTER_BX,
    REGISTER_SP,
    REGISTER_BP,
    REGISTER_SI,
    REGISTER_BI,
    REGISTER_R8,
    REGISTER_R9,
    REGISTER_R10,
    REGISTER_R11,
    REGISTER_R12,
    REGISTER_R13,
    REGISTER_R14,
    REGISTER_R15,
    REGISTER_R16,
}x86_64_register_t;

typedef struct 
{
    const char* str;
    x86_64_register_t reg;
}register_string_map_t;

x86_64_register_t lex_register(const char* register_string);
#endif