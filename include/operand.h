#ifndef OPERAND_H
#define OPERAND_H

#include "immediate.h"
#include "register.h"
#include "memory.h"
#include <stdint.h>


typedef enum
{
    OPERAND_TYPE_IMMEDIATE,
    OPERAND_TYPE_REGISTER,
    OPERAND_TYPE_MEMORY,
}operand_type_t;

typedef struct 
{
    operand_type_t type;
    union{
        immediate_t imm;
        x86_64_register_t reg;
        memory_t mem;
    };
}operand_t;


operand_t lex_operand(const char* operand_string);

typedef enum{
OPERAND_NONE,
OPERAND_rel8,
OPERAND_rel16,
OPERAND_rel32,
OPERAND_imm8,
OPERAND_imm16,
OPERAND_imm32,
OPERAND_imm64,

OPERAND_r8_compat,
OPERAND_r8,
OPERAND_r16,
OPERAND_r32,
OPERAND_r64,

OPERAND_m,

OPERAND_r_m8_compat,
OPERAND_r_m8,
OPERAND_r_m16,
OPERAND_r_m32,
OPERAND_r_m64,
OPERAND_CONSTANT_REGISTER,
}operand_symbol_t;

typedef struct{
	operand_symbol_t symbol;
	union{
	x86_64_register_t reg; //If symbol == OPERAND_CONSTANT_REGISTER
	};
}operand_class_t;

int belong_operand_class(operand_t operand, operand_class_t operand_class);

int print_operand_class(operand_class_t operand_class);

typedef struct 
{
    operand_type_t operand_type;
    union{
        immediate_operand_t immediate_operand;
        register_operand_t register_operand;
        memory_operand_t memory_operand;
    };
}exact_operand_t;

int exact_operand_belong_operand_class(exact_operand_t operand, operand_class_t operand_class);

#endif