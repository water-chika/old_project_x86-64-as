#include <stdint.h>
#include "operand_size.h"
typedef enum
{
    MEMORY_ADDRESS_INSTRUCTION_RELATIVE,
}memory_address_t;
typedef int32_t instruction_relative_address_t;
typedef struct 
{
    operand_size_t operand_size;
    memory_address_t address_type;
    union{
        instruction_relative_address_t instruction_relative_address;
    };
}memory_t;

typedef struct 
{
    operand_size_t operand_size;
    memory_address_t address_type;
    union{
        instruction_relative_address_t instruction_relative_address;
    };
}memory_operand_t;
