#include "encode/register.h"

const amd64_bits_t AMD64_REGISTER_RFLAGS = {
    .amd64_register_namespace=AMD64_BITS_NAMESPACE_FLAGS_REGISTER,
    .start_address = {0},
    .width = 64,
};

const amd64_bits_t AMD64_REGISTER_EFLAGS = {
    .amd64_register_namespace=AMD64_BITS_NAMESPACE_FLAGS_REGISTER,
    .start_address = {0},
    .width = 32,
};

const amd64_bits_t AMD64_REGISTER_RIP = {
    .amd64_register_namespace=AMD64_BITS_NAMESPACE_INSTRUCTION_POINTER_REGISTER,
    .start_address = {0},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_EIP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_INSTRUCTION_POINTER_REGISTER,
    .start_address = {0},
    .width = 32,
};

const amd64_bits_t AMD64_REGISTER_RAX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RCX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RDX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RBX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RSP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RBP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RSI = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_RDI = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R8 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=8},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R9 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=9},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R10 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=10},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R11 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=11},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R12 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=12},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R13 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=13},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R14 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=14},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_R15 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=15},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_EAX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_ECX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_EDX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_EBX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_ESP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_EBP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_ESI = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_EDI = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R8D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=8},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R9D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=9},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R10D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=10},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R11D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=11},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R12D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=12},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R13D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=13},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R14D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=14},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_R15D = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=15},
    .width = 32,
};

const amd64_bits_t AMD64_REGISTER_AX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_CX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_DX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_BX = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_SP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_BP = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_SI = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_DI = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R8W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=8},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R9W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=9},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R10W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=10},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R11W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=11},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R12W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=12},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R13W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=13},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R14W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=14},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_R15W = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=15},
    .width = 16,
};

const amd64_bits_t AMD64_REGISTER_AL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_AH = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=8, .y=0},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_CL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_CH = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=8, .y=1},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_DL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_DH = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=8, .y=2},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_BL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_BH = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=8, .y=3},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_SPL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_BPL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_SIL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_DIL = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R8B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=8},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R9B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=9},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R10B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=10},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R11B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=11},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R12B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=12},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R13B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=13},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R14B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=14},
    .width = 8,
};
const amd64_bits_t AMD64_REGISTER_R15B = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER,
    .start_address = {.x=0, .y=15},
    .width = 8,
};

//x87 registers
const amd64_bits_t AMD64_REGISTER_FCW = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_ENVIRONMENT_WORD,
    .start_address = {.x=0, .y=0},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_FSW = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_ENVIRONMENT_WORD,
    .start_address = {.x=0, .y=1},
    .width = 16,
};
const amd64_bits_t AMD64_REGISTER_FTW = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_ENVIRONMENT_WORD,
    .start_address = {.x=0, .y=2},
    .width = 16,
};

const amd64_bits_t AMD64_REGISTER_LAST_X87_INSTRUCTION_POINTER = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_EXECUTE_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_LAST_X87_DATA_POINTER = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_EXECUTE_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_X87_OPCODE = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_EXECUTE_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 11,
};

const amd64_bits_t AMD64_REGISTER_FPR0 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR1 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR2 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR3 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR4 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR5 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR6 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 80,
};
const amd64_bits_t AMD64_REGISTER_FPR7 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 80,
};

const amd64_bits_t AMD64_REGISTER_MMX0 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX1 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX2 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX3 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX4 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX5 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX6 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 64,
};
const amd64_bits_t AMD64_REGISTER_MMX7 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_X87_DATA_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 64,
};


//SSE registers
const amd64_bits_t AMD64_REGISTER_MXCSR = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_CONTROL_STATUS_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 32,
};
const amd64_bits_t AMD64_REGISTER_XMM0 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM1 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM2 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM3 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM4 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM5 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM6 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM7 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM8 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=8},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM9 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=9},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM10 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=10},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM11 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=11},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM12 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=12},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM13 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=13},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM14 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=14},
    .width = 128,
};
const amd64_bits_t AMD64_REGISTER_XMM15 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=15},
    .width = 128,
};

const amd64_bits_t AMD64_REGISTER_YMM0 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=0},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM1 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=1},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM2 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=2},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM3 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=3},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM4 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=4},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM5 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=5},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM6 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=6},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM7 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=7},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM8 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=8},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM9 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=9},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM10 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=10},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM11 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=11},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM12 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=12},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM13 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=13},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM14 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=14},
    .width = 256,
};
const amd64_bits_t AMD64_REGISTER_YMM15 = {
    .amd64_register_namespace = AMD64_BITS_NAMESPACE_SSE_DATA_REGISTER,
    .start_address = {.x=0, .y=15},
    .width = 256,
};
