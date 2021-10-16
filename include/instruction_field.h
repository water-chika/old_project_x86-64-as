#include <stdint.h>
#include "register.h"

typedef uint8_t reg_field_t;
typedef uint8_t w_field_t;
typedef uint8_t s_field_t;
typedef struct{
    reg_field_t reg : 3;
    w_field_t w : 1;
    s_field_t s : 1;
    uint8_t sreg2 : 2;
    uint8_t sreg3 : 3;
    uint8_t eee : 3;
    uint8_t tttn : 4;
    uint8_t d : 1;
}instruction_special_fields_t;

typedef enum
{
    OPERATION_DATA_SIZE_8BIT,
    OPERATION_DATA_SIZE_16BIT,
    OPERATION_DATA_SIZE_32BIT,
    OPERATION_DATA_SIZE_64BIT
}operation_data_size_t;

reg_field_t encode_reg_field(x86_64_register_t reg, int exist_w, w_field_t w, operation_data_size_t operation_data_size);

typedef enum
{
    SIGN_EXTEND_NONE,
    SIGN_EXTEND_IMMEDIATE,
}sign_extend_t;

s_field_t encode_sign_extend(sign_extend_t);