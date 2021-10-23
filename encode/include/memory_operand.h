#ifndef AMD64_MEMORY_OPERAND_H
#define AMD64_MEMORY_OPERAND_H
#include "encode/register.h"
#include <stdint.h>

typedef struct 
{
    int width;
    uint64_t constant;
}amd64_bits_constant_t;


typedef struct 
{
    uint8_t exist_base : 1;
    uint8_t exist_index : 1;
    uint8_t exist_scale : 1;
    uint8_t exist_displacement : 1;
    uint8_t scale : 4;
    amd64_bits_t base;
    amd64_bits_t index;
    amd64_bits_constant_t displacement;

    amd64_bits_width_t width;
}amd64_memory_operand_t;

#endif