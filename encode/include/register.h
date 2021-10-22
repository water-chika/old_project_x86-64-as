#ifndef AMD64_REGISTER_H
#define AMD64_REGISTER_H
#include <stdint.h>
typedef enum
{
    AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    AMD64_BITS_NAMESPACE_FLAGS_REGISTER,
    AMD64_BITS_NAMESPACE_INSTRUCTION_POINTER_REGISTER,
    AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    AMD64_BITS_NAMESPACE_X87_ENVIRONMENT_WORD,
    AMD64_BITS_NAMESPACE_X87_EXECUTE_REGISTER,
    AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    AMD64_BITS_NAMESPACE_SSE_CONTROL_STATUS_REGISTER,
}amd64_bits_namespace_t;

typedef uint64_t amd64_bits_address_unit_t;
typedef struct 
{
    amd64_bits_address_unit_t x;
    amd64_bits_address_unit_t y;
    amd64_bits_address_unit_t z;
}amd64_bits_address_t;

typedef uint64_t amd64_bits_width_t;
typedef struct amd64_bits_t
{
    amd64_bits_namespace_t amd64_register_namespace;
    amd64_bits_address_t start_address;
    amd64_bits_width_t width;
    struct amd64_register_t* next;
}amd64_bits_t;

extern const amd64_bits_t AMD64_REGISTER_RFLAGS;
extern const amd64_bits_t AMD64_REGISTER_EFLAGS;

extern const amd64_bits_t AMD64_REGISTER_RIP;
extern const amd64_bits_t AMD64_REGISTER_EIP;

extern const amd64_bits_t AMD64_REGISTER_RAX;
extern const amd64_bits_t AMD64_REGISTER_RCX;
extern const amd64_bits_t AMD64_REGISTER_RDX;
extern const amd64_bits_t AMD64_REGISTER_RBX;
extern const amd64_bits_t AMD64_REGISTER_RSP;
extern const amd64_bits_t AMD64_REGISTER_RBP;
extern const amd64_bits_t AMD64_REGISTER_RSI;
extern const amd64_bits_t AMD64_REGISTER_RDI;
extern const amd64_bits_t AMD64_REGISTER_R8;
extern const amd64_bits_t AMD64_REGISTER_R9;
extern const amd64_bits_t AMD64_REGISTER_R10;
extern const amd64_bits_t AMD64_REGISTER_R11;
extern const amd64_bits_t AMD64_REGISTER_R12;
extern const amd64_bits_t AMD64_REGISTER_R13;
extern const amd64_bits_t AMD64_REGISTER_R14;
extern const amd64_bits_t AMD64_REGISTER_R15;
extern const amd64_bits_t AMD64_REGISTER_EAX;
extern const amd64_bits_t AMD64_REGISTER_ECX;
extern const amd64_bits_t AMD64_REGISTER_EDX;
extern const amd64_bits_t AMD64_REGISTER_EBX;
extern const amd64_bits_t AMD64_REGISTER_ESP;
extern const amd64_bits_t AMD64_REGISTER_EBP;
extern const amd64_bits_t AMD64_REGISTER_ESI;
extern const amd64_bits_t AMD64_REGISTER_EDI;
extern const amd64_bits_t AMD64_REGISTER_R8D;
extern const amd64_bits_t AMD64_REGISTER_R9D;
extern const amd64_bits_t AMD64_REGISTER_R10D;
extern const amd64_bits_t AMD64_REGISTER_R11D;
extern const amd64_bits_t AMD64_REGISTER_R12D;
extern const amd64_bits_t AMD64_REGISTER_R13D;
extern const amd64_bits_t AMD64_REGISTER_R14D;
extern const amd64_bits_t AMD64_REGISTER_R15D;

extern const amd64_bits_t AMD64_REGISTER_AX;
extern const amd64_bits_t AMD64_REGISTER_CX;
extern const amd64_bits_t AMD64_REGISTER_DX;
extern const amd64_bits_t AMD64_REGISTER_BX;
extern const amd64_bits_t AMD64_REGISTER_SP;
extern const amd64_bits_t AMD64_REGISTER_BP;
extern const amd64_bits_t AMD64_REGISTER_SI;
extern const amd64_bits_t AMD64_REGISTER_DI;
extern const amd64_bits_t AMD64_REGISTER_R8W;
extern const amd64_bits_t AMD64_REGISTER_R9W;
extern const amd64_bits_t AMD64_REGISTER_R10W;
extern const amd64_bits_t AMD64_REGISTER_R11W;
extern const amd64_bits_t AMD64_REGISTER_R12W;
extern const amd64_bits_t AMD64_REGISTER_R13W;
extern const amd64_bits_t AMD64_REGISTER_R14W;
extern const amd64_bits_t AMD64_REGISTER_R15W;

extern const amd64_bits_t AMD64_REGISTER_AL;
extern const amd64_bits_t AMD64_REGISTER_AH;
extern const amd64_bits_t AMD64_REGISTER_CL;
extern const amd64_bits_t AMD64_REGISTER_CH;
extern const amd64_bits_t AMD64_REGISTER_DL;
extern const amd64_bits_t AMD64_REGISTER_DH;
extern const amd64_bits_t AMD64_REGISTER_BL;
extern const amd64_bits_t AMD64_REGISTER_BH;
extern const amd64_bits_t AMD64_REGISTER_SPL;
extern const amd64_bits_t AMD64_REGISTER_BPL;
extern const amd64_bits_t AMD64_REGISTER_SIL;
extern const amd64_bits_t AMD64_REGISTER_DIL;
extern const amd64_bits_t AMD64_REGISTER_R8B;
extern const amd64_bits_t AMD64_REGISTER_R9B;
extern const amd64_bits_t AMD64_REGISTER_R10B;
extern const amd64_bits_t AMD64_REGISTER_R11B;
extern const amd64_bits_t AMD64_REGISTER_R12B;
extern const amd64_bits_t AMD64_REGISTER_R13B;
extern const amd64_bits_t AMD64_REGISTER_R14B;
extern const amd64_bits_t AMD64_REGISTER_R15B;

//x87 registers
extern const amd64_bits_t AMD64_REGISTER_FCW;
extern const amd64_bits_t AMD64_REGISTER_FSW;
extern const amd64_bits_t AMD64_REGISTER_FTW;

extern const amd64_bits_t AMD64_REGISTER_LAST_X87_INSTRUCTION_POINTER;
extern const amd64_bits_t AMD64_REGISTER_LAST_X87_DATA_POINTER;
extern const amd64_bits_t AMD64_REGISTER_X87_OPCODE;

extern const amd64_bits_t AMD64_REGISTER_FPR0;
extern const amd64_bits_t AMD64_REGISTER_FPR1;
extern const amd64_bits_t AMD64_REGISTER_FPR2;
extern const amd64_bits_t AMD64_REGISTER_FPR3;
extern const amd64_bits_t AMD64_REGISTER_FPR4;
extern const amd64_bits_t AMD64_REGISTER_FPR5;
extern const amd64_bits_t AMD64_REGISTER_FPR6;
extern const amd64_bits_t AMD64_REGISTER_FPR7;

extern const amd64_bits_t AMD64_REGISTER_MMX0;
extern const amd64_bits_t AMD64_REGISTER_MMX1;
extern const amd64_bits_t AMD64_REGISTER_MMX2;
extern const amd64_bits_t AMD64_REGISTER_MMX3;
extern const amd64_bits_t AMD64_REGISTER_MMX4;
extern const amd64_bits_t AMD64_REGISTER_MMX5;
extern const amd64_bits_t AMD64_REGISTER_MMX6;
extern const amd64_bits_t AMD64_REGISTER_MMX7;




// SSE registers
extern const amd64_bits_t AMD64_REGISTER_MXCSR;

extern const amd64_bits_t AMD64_REGISTER_XMM0;
extern const amd64_bits_t AMD64_REGISTER_XMM1;
extern const amd64_bits_t AMD64_REGISTER_XMM2;
extern const amd64_bits_t AMD64_REGISTER_XMM3;
extern const amd64_bits_t AMD64_REGISTER_XMM4;
extern const amd64_bits_t AMD64_REGISTER_XMM5;
extern const amd64_bits_t AMD64_REGISTER_XMM6;
extern const amd64_bits_t AMD64_REGISTER_XMM7;
extern const amd64_bits_t AMD64_REGISTER_XMM8;
extern const amd64_bits_t AMD64_REGISTER_XMM9;
extern const amd64_bits_t AMD64_REGISTER_XMM10;
extern const amd64_bits_t AMD64_REGISTER_XMM11;
extern const amd64_bits_t AMD64_REGISTER_XMM12;
extern const amd64_bits_t AMD64_REGISTER_XMM13;
extern const amd64_bits_t AMD64_REGISTER_XMM14;
extern const amd64_bits_t AMD64_REGISTER_XMM15;

extern const amd64_bits_t AMD64_REGISTER_YMM0;
extern const amd64_bits_t AMD64_REGISTER_YMM1;
extern const amd64_bits_t AMD64_REGISTER_YMM2;
extern const amd64_bits_t AMD64_REGISTER_YMM3;
extern const amd64_bits_t AMD64_REGISTER_YMM4;
extern const amd64_bits_t AMD64_REGISTER_YMM5;
extern const amd64_bits_t AMD64_REGISTER_YMM6;
extern const amd64_bits_t AMD64_REGISTER_YMM7;
extern const amd64_bits_t AMD64_REGISTER_YMM8;
extern const amd64_bits_t AMD64_REGISTER_YMM9;
extern const amd64_bits_t AMD64_REGISTER_YMM10;
extern const amd64_bits_t AMD64_REGISTER_YMM11;
extern const amd64_bits_t AMD64_REGISTER_YMM12;
extern const amd64_bits_t AMD64_REGISTER_YMM13;
extern const amd64_bits_t AMD64_REGISTER_YMM14;
extern const amd64_bits_t AMD64_REGISTER_YMM15;

#endif