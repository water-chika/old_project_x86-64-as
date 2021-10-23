#ifndef X_INSTRUCTION_H
#define X_INSTRUCTION_H
#include <stdint.h>
#include "encode/register.h"
#include "encode/operand.h"
typedef enum
{
    SEGMENT_OVERRIDE_PREFIX_CS,
    SEGMENT_OVERRIDE_PREFIX_DS,
    SEGMENT_OVERRIDE_PREFIX_ES,
    SEGMENT_OVERRIDE_PREFIX_FS,
    SEGMENT_OVERRIDE_PREFIX_GS,
    SEGMENT_OVERRIDE_PREFIX_SS,
}segment_override_prefix_t;

typedef struct 
{
    uint8_t b : 1;
    uint8_t x : 1;
    uint8_t r : 1;
    uint8_t w : 1;

    uint8_t care_b : 1;
    uint8_t care_x : 1;
    uint8_t care_r : 1;
    uint8_t care_w : 1;
}x_instruction_rex_prefix_t;


typedef struct 
{
    uint8_t rm : 3;
    uint8_t reg : 3;
    uint8_t mod : 2;

    uint8_t care_rm : 1;
    uint8_t care_reg : 1;
    uint8_t care_mod : 1;
}x_instruction_mod_rm_t;

typedef struct 
{
    uint8_t base : 3;
    uint8_t index : 3;
    uint8_t scale : 2;

    uint8_t care_base : 1;
    uint8_t care_index : 1;
    uint8_t care_scale : 1;
}x_instruction_sib_t;

typedef struct 
{
    uint8_t care_width : 1;
    uint8_t width;
    uint64_t displacement;
}x_instruction_displacement_t;

typedef struct 
{
    uint8_t care_width : 1;
    uint8_t width;
    uint64_t immediate;
}x_instruction_immediate_t;


typedef struct 
{
    uint8_t exist_operand_size_override_prefix : 1;
    uint8_t care_operand_size_override_prefix : 1;

    uint8_t exist_address_size_override_prefix : 1;
    uint8_t care_address_size_override_prefix : 1;

    uint8_t exist_segment_override_prefix : 1;
    uint8_t care_segment_override_prefix : 1;
    segment_override_prefix_t segemnt_override_prefix;

    uint8_t exist_lock_prefix : 1;
    uint8_t care_lock_prefix : 1;

    uint8_t exist_repeat_prefix : 1;
    uint8_t care_repeat_prefix : 1;

    uint8_t exist_rex_prefix : 1;
    uint8_t care_rex_prefix : 1;
    x_instruction_rex_prefix_t rex_prefix;

    uint8_t primary_opcode;
    uint8_t exist_primary_opcode : 1;
    uint8_t care_primary_opcode : 1;

    uint8_t exist_mod_rm : 1;
    uint8_t care_mod_rm : 1;
    x_instruction_mod_rm_t mod_rm;

    uint8_t exist_sib : 1;
    uint8_t care_sib : 1;
    x_instruction_sib_t sib;

    uint8_t exist_disp : 1;
    uint8_t care_disp : 1;
    x_instruction_displacement_t disp;

    uint8_t exist_immediate : 1;
    uint8_t care_immediate : 1;
    x_instruction_immediate_t immediate;
}x_instruction_t;

typedef struct 
{
    int byte_num;
    uint8_t code[15];
}amd64_binary_instruction_t;


x_instruction_t add_x_instruction(x_instruction_t a, x_instruction_t b);
amd64_binary_instruction_t generate_binary_instruction(x_instruction_t x_instruction);

x_instruction_t x_instruction_opcode(uint8_t opcode);
x_instruction_t x_instruction_operand_Eb(amd64_operand_t operand);
x_instruction_t x_instruction_operand_Gb(amd64_operand_t operand);
#endif