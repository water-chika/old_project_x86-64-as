#include "operand.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tget_operand_code operand\n");
        exit(-1);
    }
    operand_t operand = lex_operand(argv[1]);
    if (operand.type == OPERAND_IMMEDIATE)
    {
        printf("immediate: %d\n", (int)operand.imm);
    }
    else if (operand.type == OPERAND_REGISTER)
    {
        printf("register: %d\n", operand.reg);
    }
    else
    {
        fprintf(stderr, "Unknown operand: %s\n", argv[1]);
    }

    return 0;
}