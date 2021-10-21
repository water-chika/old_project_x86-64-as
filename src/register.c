#include "register.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct 
{
    const char* str;
    x86_64_register_t reg;
}register_string_map_t;

register_string_map_t register_string_map[] = {
    {"AL", REGISTER_AL}, {"BL", REGISTER_BL}, {"CL", REGISTER_CL}, {"DL",REGISTER_DL},
    {"AH", REGISTER_AH}, {"BH", REGISTER_BH}, {"CH", REGISTER_CH}, {"DH",REGISTER_DH},
    {"BPL",REGISTER_BPL},{"SPL",REGISTER_SPL},{"DIL",REGISTER_DIL},{"SIL",REGISTER_SIL},
    {"R8B",REGISTER_R8B},{"R9B",REGISTER_R9B},{"R10B",REGISTER_R10B},{"R11B",REGISTER_R11B},
    {"R12B",REGISTER_R12B},{"R13B",REGISTER_R13B},{"R14B",REGISTER_R14B},{"R15B",REGISTER_R15B},
    
    {"AX", REGISTER_AX},{"BX", REGISTER_BX},{"CX", REGISTER_CX},{"DX", REGISTER_DX},
    {"SP", REGISTER_SP},{"BP", REGISTER_BP},{"SI", REGISTER_SI},{"DI", REGISTER_DI},
    {"R8W", REGISTER_R8W},{"R9W", REGISTER_R9W},{"R10W", REGISTER_R10W},{"R11W", REGISTER_R11W},
    {"R12W", REGISTER_R12W},{"R13W", REGISTER_R13W},{"R14W", REGISTER_R14W},{"R15W", REGISTER_R15W},

    {"EAX", REGISTER_EAX},{"ECX", REGISTER_ECX}, {"EDX", REGISTER_EDX}, {"EBX", REGISTER_EBX},
    {"EBP", REGISTER_EBP},{"ESP", REGISTER_ESP}, {"ESI", REGISTER_ESI}, {"EDI", REGISTER_EDI},
    {"R8D",REGISTER_R8D},{"R9D",REGISTER_R9D},{"R10D",REGISTER_R10D},{"R11D",REGISTER_R11D},
    {"R12D",REGISTER_R12D},{"R13D",REGISTER_R13D},{"R14D",REGISTER_R14D},{"R15D",REGISTER_R15D},

    {"RAX", REGISTER_RAX}, {"RCX", REGISTER_RCX}, {"RDX", REGISTER_RDX}, {"RBX", REGISTER_RBX},
    {"RSP", REGISTER_RSP}, {"RBP", REGISTER_RBP}, {"RSI", REGISTER_RSI}, {"RDI", REGISTER_RDI},
    {"R8",REGISTER_R8},{"R9",REGISTER_R9},{"R10",REGISTER_R10},{"R11",REGISTER_R11},
    {"R12",REGISTER_R12},{"R13",REGISTER_R13},{"R14",REGISTER_R14},{"R15",REGISTER_R15},
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
        assert(0);
        exit(-1);
    }
    return result->reg;
}

int cmp_register_string_map_reg(const void* a, const void* b)
{
    return ((register_string_map_t*)a)->reg - ((register_string_map_t*)b)->reg;
}

void print_register(x86_64_register_t reg)
{
    register_string_map_t search_register = {0, reg};
    size_t register_string_map_num = sizeof(register_string_map)/sizeof(register_string_map[0]);
    register_string_map_t* result = lfind(&search_register,
        register_string_map, &register_string_map_num, sizeof(register_string_map_t),
        cmp_register_string_map_reg);
    assert(result);
    printf("%s", result->str);
}

int belong_to_register_class(x86_64_register_t reg, x86_64_register_class_t reg_class)
{
    if (reg_class == REGISTER_CLASS_R8)
    {
        switch (reg)
        {
            case REGISTER_AL:case REGISTER_CL:case REGISTER_DL:case REGISTER_BL:
            case REGISTER_BPL:case REGISTER_SPL:case REGISTER_SIL:case REGISTER_DIL:
            case REGISTER_R8B:case REGISTER_R9B:case REGISTER_R10B:case REGISTER_R11B:
            case REGISTER_R12B:case REGISTER_R13B:case REGISTER_R14B:case REGISTER_R15B:
                return 1;
            default:
                return 0;
        }
    }
    else if (reg_class == REGISTER_CLASS_R8_COMPAT)
    {
        switch (reg)
        {
            case REGISTER_AL:case REGISTER_CL:case REGISTER_DL:case REGISTER_BL:
            case REGISTER_AH:case REGISTER_CH:case REGISTER_DH:case REGISTER_BH:
            return 1;
            default:
            return 0;
        }
    }
    else if (reg_class == REGISTER_CLASS_R16)
    {
        switch (reg)
        {
            case REGISTER_AX:case REGISTER_CX:case REGISTER_DX:case REGISTER_BX:
            case REGISTER_SP:case REGISTER_BP:case REGISTER_SI:case REGISTER_DI:
            case REGISTER_R8W:case REGISTER_R9W:case REGISTER_R10W:case REGISTER_R11W:
            case REGISTER_R12W:case REGISTER_R13W:case REGISTER_R14W:case REGISTER_R15W:
            return 1;
            default:
            return 0;
        }
    }
    else if (reg_class == REGISTER_CLASS_R32)
    {
        switch (reg)
        {
            case REGISTER_EAX:case REGISTER_ECX:case REGISTER_EDX:case REGISTER_EBX:
            case REGISTER_ESP:case REGISTER_EBP:case REGISTER_ESI:case REGISTER_EDI:
            case REGISTER_R8D:case REGISTER_R9D:case REGISTER_R10D:case REGISTER_R11D:
            case REGISTER_R12D:case REGISTER_R13D:case REGISTER_R14D:case REGISTER_R15D:
            return 1;
            default:
            return 0;
        }
    }
    else if (reg_class == REGISTER_CLASS_R64)
    {
        switch (reg)
        {
            case REGISTER_RAX:case REGISTER_RCX:case REGISTER_RDX:case REGISTER_RBX:
            case REGISTER_RSP:case REGISTER_RBP:case REGISTER_RSI:case REGISTER_RDI:
            case REGISTER_R8:case REGISTER_R9:case REGISTER_R10:case REGISTER_R11:
            case REGISTER_R12:case REGISTER_R13:case REGISTER_R14:case REGISTER_R15:
            return 1;
            default:
            return 0;
        }
    }
    else
    {
        fprintf(stderr, "Unknown register class\n");
        assert(0);
    }
}

int is_general_purpose_register(x86_64_register_t reg)
{
    assert(0);
}

//encode General Purpose Register
int encode_general_purpose_register(x86_64_register_t gpr)
{

    switch (gpr)
    {
        case REGISTER_AL:case REGISTER_AX:case REGISTER_EAX:case REGISTER_RAX:
            return 0;
            break;
        case REGISTER_CL:case REGISTER_CX:case REGISTER_ECX:case REGISTER_RCX:
            return 1;
            break;
        case REGISTER_DL:case REGISTER_DX:case REGISTER_EDX:case REGISTER_RDX:
            return 2;
            break;
        case REGISTER_BL:case REGISTER_BX:case REGISTER_EBX:case REGISTER_RBX:
            return 3;
            break;
        case REGISTER_AH:case REGISTER_SPL:case REGISTER_SP:case REGISTER_ESP:case REGISTER_RSP:
            return 4;
            break;
        case REGISTER_CH:case REGISTER_BPL:case REGISTER_BP:case REGISTER_EBP:case REGISTER_RBP:
            return 5;
            break;
        case REGISTER_DH:case REGISTER_SIL:case REGISTER_SI:case REGISTER_ESI:case REGISTER_RSI:
            return 6;
            break;
        case REGISTER_BH:case REGISTER_DIL:case REGISTER_DI:case REGISTER_EDI:case REGISTER_RDI:
            return 7;
            break;
        case REGISTER_R8B:case REGISTER_R8W:case REGISTER_R8D:case REGISTER_R8:
            return 8;
            break;
        case REGISTER_R9B:case REGISTER_R9W:case REGISTER_R9D:case REGISTER_R9:
            return 9;
            break;
        case REGISTER_R10B:case REGISTER_R10W:case REGISTER_R10D:case REGISTER_R10:
            return 10;
            break;
        case REGISTER_R11B:case REGISTER_R11W:case REGISTER_R11D:case REGISTER_R11:
            return 11;
            break;
        case REGISTER_R12B:case REGISTER_R12W:case REGISTER_R12D:case REGISTER_R12:
            return 12;
            break;
        case REGISTER_R13B:case REGISTER_R13W:case REGISTER_R13D:case REGISTER_R13:
            return 13;
            break;
        case REGISTER_R14B:case REGISTER_R14W:case REGISTER_R14D:case REGISTER_R14:
            return 14;
            break;
        case REGISTER_R15B:case REGISTER_R15W:case REGISTER_R15D:case REGISTER_R15:
            return 15;
            break;
    }
    fprintf(stderr, "Unknown reg : %d\n", gpr);
    assert(0);
    return -1;
}


rflags_t decode_rflags_register(rflags_register_t rflags_register)
{
    rflags_t rflags = {};
    rflags.CF = rflags_register & 0x1;
    rflags.PF = rflags_register >> 2;
    rflags.AF = rflags_register >> 4;
    rflags.ZF = rflags_register >> 6;
    rflags.SF = rflags_register >> 7;
    rflags.DF = rflags_register >> 10;
    rflags.OF = rflags_register >> 11;
    return rflags;
}
rflags_register_t encode_rfalgs(rflags_t rflags)
{
    rflags_register_t rflags_register;
    rflags_register = (rflags.OF<<11) | (rflags.DF << 10) | (rflags.SF << 7) |
        (rflags.ZF << 6) | (rflags.AF << 4) | (rflags.PF << 2) | (rflags.CF << 0);
}

int is_valid_rflags_register(rflags_register_t rflags_register)
{
    return (rflags_register & 0x0000cd5) == 0;
}
