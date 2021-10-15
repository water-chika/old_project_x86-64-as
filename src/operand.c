#include "operand.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <search.h>


operand_t lex_operand(const char* operand_string)
{
    operand_t operand;
    if (operand_string[0] == '%')
    {
        operand.type = OPERAND_REGISTER;
        operand.reg = lex_register(operand_string+1);
    }
    else if (operand_string[0] == '[')
    {

    }
    else if (operand_string[0] == '$')
    {
        operand.type = OPERAND_IMMEDIATE;
        operand.imm = lex_immediate(operand_string+1);
    }
    else
    {
        fprintf(stderr, "Unknown operand: %s\n", operand_string);
        exit(-1);
    }
    return operand;
}

int belong_r16(operand_t operand)
{
    return operand.type == OPERAND_REGISTER && (
            operand.reg == REGISTER_AX || operand.reg == REGISTER_CX ||
            operand.reg == REGISTER_BX || operand.reg == REGISTER_DX ||
            operand.reg == REGISTER_SP || operand.reg == REGISTER_BP ||
            operand.reg == REGISTER_SI || operand.reg == REGISTER_DI ||
            operand.reg == REGISTER_R8 || operand.reg == REGISTER_R9 ||
            operand.reg == REGISTER_R10 || operand.reg == REGISTER_R11 ||
            operand.reg == REGISTER_R12 || operand.reg == REGISTER_R13 ||
            operand.reg == REGISTER_R14 || operand.reg == REGISTER_R15);
}

int belong_operand_class(operand_t operand, operand_class_t operand_class)
{
    switch (operand_class.symbol)
    {
        case OPERAND_r8:
        return operand.type == OPERAND_CONSTANT_REGISTER && (
            operand.reg == REGISTER_AL || operand.reg == REGISTER_CL ||
            operand.reg == REGISTER_DL || operand.reg == REGISTER_BL ||
            operand.reg == REGISTER_AH || operand.reg == REGISTER_CH ||
            operand.reg == REGISTER_DH || operand.reg == REGISTER_BH ||
            operand.reg == REGISTER_SPL || operand.reg == REGISTER_BPL ||
            operand.reg == REGISTER_SIL || operand.reg == REGISTER_DIL ||
            operand.reg == REGISTER_R8B || operand.reg == REGISTER_R9B ||
            operand.reg == REGISTER_R10B || operand.reg == REGISTER_R11B ||
            operand.reg == REGISTER_R12B || operand.reg == REGISTER_R13B ||
            operand.reg == REGISTER_R14B || operand.reg == REGISTER_R15B
        );
        break;
        case OPERAND_r16:
        return belong_r16(operand);
        break;
        case OPERAND_r32:
        return operand.type == OPERAND_REGISTER && (
            operand.reg == REGISTER_EAX || operand.reg == REGISTER_EBX ||
            operand.reg == REGISTER_ECX || operand.reg == REGISTER_EDX ||
            operand.reg == REGISTER_ESP || operand.reg == REGISTER_EBP ||
            operand.reg == REGISTER_ESI || operand.reg == REGISTER_EDI ||
            operand.reg == REGISTER_R8D || operand.reg == REGISTER_R9D ||
            operand.reg == REGISTER_R10D || operand.reg == REGISTER_R11D ||
            operand.reg == REGISTER_R12D || operand.reg == REGISTER_R13D ||
            operand.reg == REGISTER_R14D || operand.reg == REGISTER_R15D
        );
        case OPERAND_CONSTANT_REGISTER:
        return operand.type == OPERAND_REGISTER && operand_class.reg == operand.reg;

        case OPERAND_r_m16:
        return belong_r16(operand) || operand.type == OPERAND_MEMORY;

        case OPERAND_imm8:
        return operand.type == OPERAND_IMMEDIATE && -128 <= operand.imm && operand.imm <= 127;
        break;
        case OPERAND_imm16:
        return operand.type == OPERAND_IMMEDIATE && -32768 <= operand.imm && operand.imm <= 32767;
        break;
        case OPERAND_imm32:
        return operand.type == OPERAND_IMMEDIATE && -2147483648 <= operand.imm && operand.imm <=-2147483647;
        break;
        default:
        return 0;
        break;
    }
}

int print_operand_class(operand_class_t operand_class)
{
    const char* symbol_string = "";
    switch (operand_class.symbol)
    {
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
        case OPERAND_imm8:
        symbol_string = "imm8";
        break;
        case OPERAND_imm16:
        symbol_string = "imm16";
        break;
        case OPERAND_imm32:
        symbol_string = "imm32";
        break;
        case OPERAND_r_m8:
        symbol_string = "r/m8";
        break;
        case OPERAND_r_m16:
        symbol_string = "r/m16";
        break;
        default:
        fprintf(stderr, "Unknown operand_class: %d\n", operand_class.symbol);
        exit(-1);
        break;
    }
    printf("%s ", symbol_string);
    return 0;
}