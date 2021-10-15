#include "instruction.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tget_instruction_symbol instruction\n");
        exit(-1);
    }

    const char* instruction_string = argv[1];

    instruction_item_t instruction_item = get_instruction_item(lex_instruction(instruction_string));

    print_instruction_item(instruction_item);

    return 0;
}