#ifndef ENCODER_H
#define ENCODER_H

#include "lexer.h"
#include "instruction.h"
#include <stdint.h>

typedef uint8_t opcode_t;
typedef uint8_t rex_prefix_t;
typedef uint8_t mod_r_m_t;
typedef uint8_t sib_t;
typedef int64_t displacement_t;
typedef struct 
{
	int byte_num;
	uint64_t imm;
}encoded_immediate_t;

typedef enum
{
	GROUP1_PREFIX_LOCK = 0xf0,
	GROUP1_PREFIX_RPNE = 0xf2,
	GROUP1_PREFIX_REP = 0xf3,
}group1_prefix_t;
typedef enum
{
	GROUP2_PREFIX_CS_SEGMENT_OVERRIDE = 0x2e,
	GROUP2_PREFIX_SS_SEGMENT_OVERRIDE = 0x36,
	GROUP2_PREFIX_DS_SEGMENT_OVERRIDE = 0x3e,
	GROUP2_PREFIX_ES_SEGMENT_OVERRIDE = 0x26,
	GROUP2_PREFIX_FS_SEGMENT_OVERRIDE = 0x64,
	GROUP2_PREFIX_GS_SEGMENT_OVERRIDE = 0x65,
	GROUP2_PREFIX_BRANCH_NOT_TAKEN = 0x2e,
	GROUP2_PREFIX_BRANCH_TAKEN = 0x3e
}group2_prefix_t;
typedef enum
{
	GROUP3_PREFIX_OPERAND_SIZE_OVERRIDE = 0x66
}group3_prefix_t;
typedef enum
{
	GROUP4_PREFIX_ADDRESS_SIZE_OVERRIDE = 0x67
}group4_prefix_t;

typedef struct 
{
	int exist_group1_prefix : 1;
	int exist_group2_prefix : 1;
	int exist_group3_prefix : 1;
	int exist_group4_prefix : 1;
	int exist_rex_prefix : 1;
	int opcode_num : 2;
	int exist_mod_r_m : 1;
	int exist_sib : 1;
	int exist_displacement : 1;
	int exist_immediate : 1;

	group1_prefix_t group1_prefix;
	group2_prefix_t group2_prefix;
	group3_prefix_t group3_prefix;
	group4_prefix_t group4_prefix;
	rex_prefix_t rex;
	opcode_t opcode[4];
	mod_r_m_t mod_r_m;
	sib_t sib_t;
	displacement_t displacement;
	encoded_immediate_t immediate;
}encoded_instruction_t;

encoded_instruction_t encode_instruction(instruction_item_t instruction_item, lexed_instruction_t lexed_instruction);

void print_encoded_instruction(encoded_instruction_t encoded_instruction);

#endif