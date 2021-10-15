#include "encoder.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tget_encoded_instruction\n");
        exit(-1);
    }
    lexed_instruction_t lexed_instruction = lex_instruction(argv[1]);
    instruction_item_t instruction_item = get_instruction_item(lexed_instruction);
    encoded_instruction_t encoded_instruction = encode_instruction(instruction_item, lexed_instruction);

    print_encoded_instruction(encoded_instruction);

    return 0;
}