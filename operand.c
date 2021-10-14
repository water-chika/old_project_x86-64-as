#include "operand.h"
#include <string.h>
#include <search.h>

struct reg
{
    char* str;
    int encode;
    operand_type_t type;
};

struct reg regs[] = {
    {"AX",0,OPERAND_r16},
    {"CX",1,OPERAND_r16},
    {"DX",2,OPERAND_r16},
    {"BX",3,OPERAND_r16},
    {"SP",4,OPERAND_r16},
    {"BP",5,OPERAND_r16},
    {"SI",6,OPERAND_r16},
    {"BI",7,OPERAND_r16},
    {"R8",8,OPERAND_r16},
    {"R9",9,OPERAND_r16},
    {"R10",10,OPERAND_r16},
    {"R11",11,OPERAND_r16},
    {"R12",12,OPERAND_r16},
    {"R13",13,OPERAND_r16},
    {"R14",14,OPERAND_r16},
    {"R15",15,OPERAND_r16},
};
int compare_reg_str(const void* a,const void* b)
{
    return strcmp(((struct reg*)a)->str,((struct reg*)b)->str);
}

operand_set_t lex_operand(const char* operand_string)
{
    operand_set_t operand_set;
    if (operand_string[0] == '%')
    {
        struct reg r;
        r.str = operand_string+1;
        size_t regs_num = sizeof(regs)/sizeof(regs[0]);
        struct reg* find_reg= lfind(&r, regs, &regs_num, sizeof(r), compare_reg_str);
        assert(find_reg);
        operand_set.encode = find_reg->encode;
        operand_set.operand_type[0] = find_reg->type;
    }
    else if (operand_string[0] == '[')
    {

    }
    else if (operand_string[0] == '$')
    {

    }
}