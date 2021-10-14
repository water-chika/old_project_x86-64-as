#include "register.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
register_string_map_t register_string_map[] = {
    {"AX", REGISTER_AX},
    {"BX", REGISTER_BX},
    {"CX", REGISTER_CX},
    {"DX", REGISTER_DX},
    {"SP", REGISTER_SP},
    {"BP", REGISTER_BP},
    {"SI", REGISTER_SI},
    {"BI", REGISTER_BI},
    {"R8", REGISTER_R8},
    {"R9", REGISTER_R9},
    {"R10", REGISTER_R10},
    {"R11", REGISTER_R11},
    {"R12", REGISTER_R12},
    {"R13", REGISTER_R13},
    {"R14", REGISTER_R14},
    {"R15", REGISTER_R15},
};
int cmp_register_string_map_str(const void* a, const void* b)
{
    return strcmp(((register_string_map_t*)a)->str, ((register_string_map_t*)b)->str);
}

x86_64_register_t lex_register(const char* register_string)
{
    register_string_map_t search_register = {register_string};
    size_t register_string_map_num = sizeof(register_string_map)/sizeof(register_string_map[0]);
    register_string_map_t* result = lfind(&search_register, 
        register_string_map, &register_string_map_num, sizeof(register_string_map_t), 
        cmp_register_string_map_str);
    if (result == NULL)
    {
        fprintf(stderr, "Unknown register: %s\n", register_string);
        exit(-1);
    }
    return result->reg;
}