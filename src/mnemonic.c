#include "mnemonic.h"
#include <search.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef struct 
{
    const char* str;
    mnemonic_t mnemonic;
}mnemonic_map_string_t;

mnemonic_map_string_t mnemonic_map_string[] = {
    {"ADC", MNEMONIC_ADC},
    {"ADD", MNEMONIC_ADD},
    {"CLC", MNEMONIC_CLC},
    {"CMOVA", MNEMONIC_CMOVA},
    {"CMP", MNEMONIC_CMP},
    {"RET", MNEMONIC_RET},
    {"MOV", MNEMONIC_MOV},
    {"LEA", MNEMONIC_LEA},
    {"SYSCALL", MNEMONIC_SYSCALL},
};

int cmp_mnemonic_map_string_str(const void* a, const void* b)
{
    return strcmp(((mnemonic_map_string_t*)a)->str, ((mnemonic_map_string_t*)b)->str);
}


mnemonic_t lex_mnemonic(const char* mnemonic_string)
{
    size_t mnemonic_map_string_num = sizeof(mnemonic_map_string)/sizeof(mnemonic_map_string[0]);
    mnemonic_map_string_t mnemonic_search = {mnemonic_string};
    mnemonic_map_string_t* result = lfind(&mnemonic_search,
        mnemonic_map_string, &mnemonic_map_string_num, sizeof(mnemonic_map_string_t), 
        cmp_mnemonic_map_string_str);
    if (result == NULL)
    {
        fprintf(stderr, "Unknown mnemonic : %s", mnemonic_string);
    }
    assert(result);
    return result->mnemonic;
}

int cmp_mnemonic_map_string_mnemonic(const void* a, const void* b)
{
    return ((mnemonic_map_string_t*)a)->mnemonic - ((mnemonic_map_string_t*)b)->mnemonic;
}

int print_mnemonic(mnemonic_t mnemonic)
{
    size_t mnemonic_map_string_num = sizeof(mnemonic_map_string)/sizeof(mnemonic_map_string[0]);
    mnemonic_map_string_t mnemonic_search = {0,mnemonic};
    mnemonic_map_string_t* result = lfind(&mnemonic_search,
        mnemonic_map_string, &mnemonic_map_string_num, sizeof(mnemonic_map_string_t),
        cmp_mnemonic_map_string_mnemonic);
    printf("%s", result->str);
    return 0;
}