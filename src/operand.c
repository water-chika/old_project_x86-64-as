#include "operand.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <search.h>
#include <assert.h>


operand_t lex_operand(const char* operand_string)
{
    operand_t operand;
    if (operand_string[0] == '%')
    {
        operand.type = OPERAND_TYPE_REGISTER;
        operand.reg = lex_register(operand_string+1);
    }
    else if (operand_string[0] == '[')
    {
        if (operand_string[1]=='.')
        {
            operand.type = OPERAND_TYPE_MEMORY;
            operand.mem.address_type = MEMORY_ADDRESS_INSTRUCTION_RELATIVE;
            char* tail = NULL;
            operand.mem.instruction_relative_address = strtoll(operand_string+2, &tail, 10);
        }
        else
        {
            assert(0);
        }
    }
    else if (operand_string[0] == '$')
    {
        operand.type = OPERAND_TYPE_IMMEDIATE;
        operand.imm = lex_immediate(operand_string+1);
    }
    else
    {
        fprintf(stderr, "Unknown operand: %s\n", operand_string);
        exit(-1);
    }
    return operand;
}
int belong_r8_compat(operand_t operand)
{
    return operand.type == OPERAND_TYPE_REGISTER && belong_to_register_class(operand.reg, REGISTER_CLASS_R8_COMPAT);
}
int belong_r8(operand_t operand)
{
        return operand.type == OPERAND_TYPE_REGISTER && belong_to_register_class(operand.reg, REGISTER_CLASS_R8);
}
int belong_r16(operand_t operand)
{
    return operand.type == OPERAND_TYPE_REGISTER && belong_to_register_class(operand.reg, REGISTER_CLASS_R16);
}
int belong_r32(operand_t operand)
{
        return operand.type == OPERAND_TYPE_REGISTER && belong_to_register_class(operand.reg, REGISTER_CLASS_R32);
}

int belong_operand_class(operand_t operand, operand_class_t operand_class)
{
    switch (operand_class.symbol)
    {
        case OPERAND_r8_compat:
        return belong_r8_compat(operand);
        break;
        case OPERAND_r8:
        return belong_r8(operand);
        break;
        case OPERAND_r16:
        return belong_r16(operand);
        break;
        case OPERAND_r32:
        return belong_r32(operand);
        case OPERAND_r64:
        return operand.type == OPERAND_TYPE_REGISTER && belong_to_register_class(operand.reg, REGISTER_CLASS_R64);

        case OPERAND_CONSTANT_REGISTER:
        return operand.type == OPERAND_TYPE_REGISTER && operand_class.reg == operand.reg;

        case OPERAND_m:
        return operand.type == OPERAND_TYPE_MEMORY;
        break;

        case OPERAND_r_m8_compat:
        return belong_r8_compat(operand) || operand.type == OPERAND_TYPE_MEMORY;
        case OPERAND_r_m8:
        return belong_r8(operand) || operand.type == OPERAND_TYPE_MEMORY;
        case OPERAND_r_m16:
        return belong_r16(operand) || operand.type == OPERAND_TYPE_MEMORY;
        case OPERAND_r_m32:
        return belong_r32(operand) || operand.type == OPERAND_TYPE_MEMORY;
        case OPERAND_r_m64:
        return operand.type == OPERAND_TYPE_MEMORY || operand.type == OPERAND_TYPE_REGISTER && belong_to_register_class(operand.reg, REGISTER_CLASS_R64);

        case OPERAND_imm8:
        return operand.type == OPERAND_TYPE_IMMEDIATE && -128 <= operand.imm && operand.imm <= 127;
        break;
        case OPERAND_imm16:
        return operand.type == OPERAND_TYPE_IMMEDIATE && -32768 <= operand.imm && operand.imm <= 32767;
        break;
        case OPERAND_imm32:
        return operand.type == OPERAND_TYPE_IMMEDIATE && -2147483648 <= operand.imm && operand.imm <=2147483647;
        break;
        case OPERAND_imm64:
        return operand.type == OPERAND_TYPE_IMMEDIATE;
        break;
        default:
        printf("%d\n", operand_class.symbol);
        assert(0);
        break;
    }
}

int print_operand_class(operand_class_t operand_class)
{
    const char* symbol_string = "";
    switch (operand_class.symbol)
    {
        case OPERAND_r8_compat:
        symbol_string = "r8_compat";
        break;
        case OPERAND_r8:
        symbol_string = "r8";
        break;
        case OPERAND_r16:
        symbol_string = "r16";
        break;
        case OPERAND_CONSTANT_REGISTER:
            print_register(operand_class.reg);
            return 0;
        break;
        case OPERAND_r32:
        symbol_string = "r32";
        break;
        case OPERAND_r64:
        symbol_string = "r64";
        break;
        case OPERAND_m:
        symbol_string = "m";
        break;
        case OPERAND_imm8:
        symbol_string = "imm8";
        break;
        case OPERAND_imm16:
        symbol_string = "imm16";
        break;
        case OPERAND_imm32:
        symbol_string = "imm32";
        break;
        case OPERAND_imm64:
        symbol_string = "imm64";
        break;
        case OPERAND_r_m8_compat:
        symbol_string = "r/m8_compat";
        break;
        case OPERAND_r_m8:
        symbol_string = "r/m8";
        break;
        case OPERAND_r_m16:
        symbol_string = "r/m16";
        break;
        default:
        fprintf(stderr, "Unknown operand_class: %d\n", operand_class.symbol);
        assert(0);
        break;
    }
    printf("%s", symbol_string);
    return 0;
}