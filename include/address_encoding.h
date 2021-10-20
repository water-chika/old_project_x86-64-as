#ifndef ADDRESS_ENCODING_H
#define ADDRESS_ENCODING_H
#include <stdint.h>
#include "encoder.h"




typedef struct 
{
    uint8_t exist_operand_size_prefix : 1;
    uint8_t exist_rex : 1;
    uint8_t exist_disp : 1;
    uint8_t rex_w : 1;
    uint8_t rex_b : 1;
    uint8_t mod : 2;
    uint8_t r_m : 3;
    uint8_t exist_sib : 1;
    sib_t sib;
    displacement_t disp;
}address_encoding_t;

address_encoding_t encode_address(operand_t operand);

#endif