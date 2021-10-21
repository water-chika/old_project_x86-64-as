#ifndef IMMEDIATE_H
#define IMMEDIATE_H

#include <stdint.h>
#include <stdlib.h>
#include "operand_size.h"
typedef int64_t immediate_t;
typedef struct 
{
    operand_size_t operand_size;
    union 
    {
        int8_t imm8;
        int16_t imm16;
        int32_t imm32;
        int64_t imm64;
    };
}immediate_operand_t;


immediate_t lex_immediate(const char* immediate_string);


#endif