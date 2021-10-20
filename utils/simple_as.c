#include "encoder.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
char* change_suffix(const char* file_name, const char* new_suffix);
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage:\n\tsimple_as file\n");
        exit(-1);
    }
    
    const char* in_file_name = argv[1];
    FILE* in = fopen(in_file_name, "r");
    if (in == NULL)
    {
        fprintf(stderr, "%s open fail", in_file_name);
        perror(" ");
        exit(-1);
    }
    char* output_file_name = change_suffix(in_file_name, "bin");
    FILE* out = fopen(output_file_name, "w");

    size_t line_size = 0;
    char* line= NULL;
    while (0 < getline(&line, &line_size, in))
    {
        printf("%s", line);
        if (line[0] == '.')
        {
            char* command = strtok(line, " \n");
            if (0 == strcmp(command, ".byte"))
            {
                long byte_value = strtol(strtok(NULL," \n"), NULL, 10);
                assert( (byte_value&0xff) == byte_value);
                int count = fwrite(&byte_value, 1, 1, out);
                assert(count == 1);
            }
            else if (0 == strcmp(command, ".ascii"))
            {
                char* ascii_str = strtok(NULL, " \n");
                int len = strlen(ascii_str);
                int count = fwrite(ascii_str, len, 1, out);
                assert(count == 1);
            }
            else
            {
                assert(0);
            }
            continue;
        }
        lexed_instruction_t lexed_instruction = lex_instruction(line);
        instruction_item_t instruction_item = get_instruction_item(lexed_instruction);
        encoded_instruction_t encoded_instruction = encode_instruction(instruction_item, lexed_instruction);
        binary_instruction_t binary_code = generate_binary_instruction(encoded_instruction);
        int count = fwrite(binary_code.bytes, binary_code.size, 1, out);
        printf("%d\n",binary_code.size);
        assert(count == 1);
    }

    if (line)free(line);
    
    fclose(out);
    fclose(in);
    free(output_file_name);

    return 0;
}

char* change_suffix(const char* file_name, const char* new_suffix)
{
    char *old_suffix = strrchr(file_name, '.');
    int file_name_only_len;
    if (old_suffix)
    {
        file_name_only_len = old_suffix - file_name;
    }
    else
    {
        file_name_only_len = strlen(file_name);
    }
    int new_file_name_size = file_name_only_len + strlen(new_suffix) + 2;
    char* new_file_name = (char*)malloc(new_file_name_size);

    strcpy(new_file_name, file_name);
    new_file_name[file_name_only_len] = '.';
    strcpy(new_file_name + file_name_only_len+1, new_suffix);

    return new_file_name;
}