#include <stdint.h>
typedef enum{
OPERAND_imm8,
OPERAND_imm16,
OPERAND_imm32,

OPERAND_AX,OPERAND_CX,OPERAND_DX,OPERAND_BX,OPERAND_SP,OPERAND_BP,OPERAND_SI,OPERAND_BI,
OPERAND_R8,OPERAND_R9,OPERAND_R10,OPERAND_R11,OPERAND_R12,OPERAND_R13,OPERAND_R14,OPERAND_R15,
OPERAND_r8,
OPERAND_r16,
OPERAND_r32,
}operand_type_t;
typedef struct 
{
    int64_t encode;
    int set_size;
    operand_type_t operand_type[0];
}operand_set_t;


operand_set_t lex_operand(const char* operand_string);