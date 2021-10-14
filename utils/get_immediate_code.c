#include "immediate.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tget_immediate_code imm\n");
        exit(-1);
    }
    const char* imm_str = argv[1];
    printf("immediate: %d\n", (int)lex_immediate(imm_str));

    return 0;
}