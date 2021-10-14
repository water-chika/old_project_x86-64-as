#include "lexer.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
lexed_instruction_t lex_instruction(const char* instruction)
{
    lexed_instruction_t lexed_instruction;
    char buff[128];
    strncpy(buff, instruction, sizeof(buff)-1);
    buff[127]='\0';
    assert(strlen(instruction) < sizeof(buff));
    const char* mnemonic_string = strtok(buff, " \n");
    const char* operand_string[4];

    lexed_instruction.operand_num = 4;
    for (int i = 0; i < 4; i ++)
    {
        operand_string[i] = strtok(NULL, ",");
        if (operand_string[i] == NULL)
        {
            lexed_instruction.operand_num = i;
            break;
        }
    }

    lexed_instruction.mnemonic = lex_mnemonic(mnemonic_string);
    for (int i = 0; i < lexed_instruction.operand_num; i++)
    {
        lexed_instruction.operand[i] = lex_operand(operand_string[i]);
    }

    return lexed_instruction;
}