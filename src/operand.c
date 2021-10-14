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