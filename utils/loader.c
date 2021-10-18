#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int fun ()
{
    return 0;
}
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tloeader binary_code_file\n");
        exit(-1);
    }
    FILE* binary_code_file = fopen(argv[1], "r");
    assert(binary_code_file);
    int (*loaded_function)(void);

    fseek(binary_code_file, 0, SEEK_END);
    long file_size = ftell(binary_code_file);
    fseek(binary_code_file, 0, SEEK_SET);
    loaded_function = malloc(file_size);
    ((char*)fun)[0] = 1;
    //int success = fread(loaded_function, file_size, 1, binary_code_file);
    //assert(success==1);

    //int return_code = loaded_function();
    //printf("return code == %d\n", return_code);
    return 0;
}