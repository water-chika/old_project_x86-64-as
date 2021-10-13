#include "lexer.h"
#include <string.h>
lexed_instruction_t lex_instruction(const char* instruction)
{
    lexed_instruction_t lexed_instruction;
    char buff[128];
    strncpy(buff, instruction, sizeof(buff)-1);
    buff[127]='\0';
    assert(strlen(instruction) < sizeof(buff));
    const char* mnemonic_string = strtok(buff, " \n");
    const char* operand_string[4];
    for (int i = 0; i < 4; i ++)
    {
        operand_string[i] = strtok(NULL, ",");
    }
    lexed_instruction.mnemonic = get_mnemonic(mnemonic_string);
    for (int i = 0; i < 4; i++)
    {
        lexed_instruction.operand[i] = get_operand(operand_string[i]);
    }
}