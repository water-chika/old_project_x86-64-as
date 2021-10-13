#include <stdio.h>
#include "lexer.h"
#include "encoder.h"
int main(void)
{
    const char* line = "adc %al, 180";
    lexed_instruction_t lexed_instruction = lex_instruction(line);
    encoded_instruction_t encoded_instruction = encode_instruction(lexed_instruction);
    for (int i = 0; i < encoded_instruction.code_size; i++)
    {
        printf("%d", encoded_instruction.code[i]);
    }
    
    return 0;
}