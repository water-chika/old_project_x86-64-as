#include <stdio.h>
#include <stdlib.h>
#include "register.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tget_register_code register\n");
        exit(-1);
    }
    const char* register_string = argv[1];
    printf("%d\n", lex_register(register_string));
    return 0;
}