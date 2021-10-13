#include <stdint.h>
typedef enum{
OPERAND_IMM8,
OPERAND_IMM16,
OPERAND_IMM32,
OPERAND_R8,
OPERAND_R16,
OPERAND_R32,
}operand_type_t;
typedef struct 
{
    int64_t encode;
    int set_size;
    operand_type_t operand_type[0];
}operand_set_t;


typedef int operand_set_t;

operand_set_t lex_operand(const char* operand_string);