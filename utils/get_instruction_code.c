#include "lexer.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tget_instruction_code instruction\n");
        exit(-1);
    }

    lexed_instruction_t lexed_instruction = lex_instruction(argv[1]);

    printf("%d ", lexed_instruction.mnemonic);
    for (int i = 0; i < lexed_instruction.operand_num - 1; i++)
    {
        operand_t operand = lexed_instruction.operand[i];
        printf("(%d,%d),", operand.type, (int)(operand.type == OPERAND_IMMEDIATE?operand.imm:operand.reg));
    }

    operand_t last_operand = lexed_instruction.operand[lexed_instruction.operand_num-1];
    printf("(%d,%d)\n",last_operand.type, (int)(last_operand.type == OPERAND_IMMEDIATE?last_operand.imm:last_operand.reg));

    return 0;
}