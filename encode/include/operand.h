#ifndef AMD64_OPERAND_H
#define AMD64_OPERAND_H
#include "encode/memory_operand.h"
#include "encode/register.h"

typedef enum
{
    AMD64_OPERAND_TYPE_REGISTER,
    AMD64_OPERAND_TYPE_MEMORY,
    AMD64_OPERAND_TYPE_IMMEDIATE,
}amd64_operand_type_t;
typedef struct 
{
    amd64_operand_type_t operand_type;
    union{
        amd64_bits_t reg;
        amd64_memory_operand_t mem;
        amd64_bits_constant_t imm;
    };
}amd64_operand_t;

#endif