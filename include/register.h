#ifndef REGISTER_H
#define REGISTER_H
#include <search.h>
typedef enum
{
    REGISTER_AL,REGISTER_CL,REGISTER_DL,REGISTER_BL,
    REGISTER_AH,REGISTER_CH,REGISTER_DH,REGISTER_BH,
    REGISTER_BPL,REGISTER_SPL,REGISTER_DIL,REGISTER_SIL,
    REGISTER_R8B,REGISTER_R9B,REGISTER_R10B,REGISTER_R11B,
    REGISTER_R12B,REGISTER_R13B,REGISTER_R14B,REGISTER_R15B,

    REGISTER_AX,REGISTER_CX,REGISTER_DX,REGISTER_BX,
    REGISTER_SP,REGISTER_BP,REGISTER_SI,REGISTER_DI,
    REGISTER_R8W,REGISTER_R9W,REGISTER_R10W,REGISTER_R11W,
    REGISTER_R12W,REGISTER_R13W,REGISTER_R14W,REGISTER_R15W,

    REGISTER_EAX,REGISTER_ECX,REGISTER_EDX,REGISTER_EBX,
    REGISTER_ESP,REGISTER_EBP,REGISTER_ESI,REGISTER_EDI,
    REGISTER_R8D,REGISTER_R9D,REGISTER_R10D,REGISTER_R11D,
    REGISTER_R12D,REGISTER_R13D,REGISTER_R14D,REGISTER_R15D,

    REGISTER_RAX,REGISTER_RCX,REGISTER_RDX,REGISTER_RBX,
    REGISTER_RSP,REGISTER_RBP,REGISTER_RSI,REGISTER_RDI,
    REGISTER_R8,REGISTER_R9,REGISTER_R10,REGISTER_R11,
    REGISTER_R12,REGISTER_R13,REGISTER_R14,REGISTER_R15,

    REGISTER_YMM0,REGISTER_YMM1,REGISTER_YMM2,REGISTER_YMM3,
    REGISTER_YMM4,REGISTER_YMM5,REGISTER_YMM6,REGISTER_YMM7,
    REGISTER_YMM8,REGISTER_YMM9,REGISTER_YMM10,REGISTER_YMM11,
    REGISTER_YMM12,REGISTER_YMM13,REGISTER_YMM14,REGISTER_YMM15,

    REGISTER_XMM0,REGISTER_XMM1,REGISTER_XMM2,REGISTER_XMM3,
    REGISTER_XMM4,REGISTER_XMM5,REGISTER_XMM6,REGISTER_XMM7,
    REGISTER_XMM8,REGISTER_XMM9,REGISTER_XMM10,REGISTER_XMM11,
    REGISTER_XMM12,REGISTER_XMM13,REGISTER_XMM14,REGISTER_XMM15,

    REGISTER_MMX0,REGISTER_MMX1,REGISTER_MMX2,REGISTER_MMX3,
    REGISTER_MMX4,REGISTER_MMX5,REGISTER_MMX6,REGISTER_MMX7,

    REGISTER_FPR0,REGISTER_FPR1,REGISTER_FPR2,REGISTER_FPR3,
    REGISTER_FPR4,REGISTER_FPR5,REGISTER_FPR6,REGISTER_FPR7,

    REGISTER_RIP,REGISTER_RFLAGS,
}x86_64_register_t;

x86_64_register_t lex_register(const char* register_string);

void print_register(x86_64_register_t reg);

typedef enum
{
    REGISTER_CLASS_R8,
    REGISTER_CLASS_R16,
    REGISTER_CLASS_R32,
    REGISTER_CLASS_R64,

    REGISTER_CLASS_R8_COMPAT,
}x86_64_register_class_t;
int belong_to_register_class(x86_64_register_t reg, x86_64_register_class_t reg_class);

int is_general_purpose_register(x86_64_register_t reg);
int encode_general_purpose_register(x86_64_register_t gpr);
#endif
