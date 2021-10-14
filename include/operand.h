#ifndef OPERAND_H
#define OPERAND_H

#include "immediate.h"
#include "register.h"
#include <stdint.h>

typedef enum{
OPERAND_rel8,
OPERAND_rel16,
OPERAND_rel32,
OPERAND_imm8,
OPERAND_imm16,
OPERAND_imm32,

OPERAND_r8,
OPERAND_r16,
OPERAND_r32,
}operand_symbol_t;

typedef enum
{
    OPERAND_IMMEDIATE,
    OPERAND_REGISTER,
    OPERAND_MEMORY,
}operand_type_t;
typedef struct 
{
    operand_type_t type;
    union{
        immediate_t imm;
        x86_64_register_t reg;
    };
}operand_t;


operand_t lex_operand(const char* operand_string);

#endif