#include <stdint.h>
#include "register.h"
#include "operand.h"
#include "mnemonic.h"
#include "lexer.h"

typedef struct 
{
	uint8_t opcode_num;
	uint8_t code[4];

	uint8_t NP : 1;
	uint8_t NFx : 1;
	uint8_t REX_W : 1;
	uint8_t exist_REX : 1;
	uint8_t e_digit : 1;
	uint8_t _r : 1;
	uint8_t e_code_offset : 1;
	uint8_t e_immediate : 1;
	uint8_t ib : 1;uint8_t iw : 1;uint8_t id : 1;uint8_t io : 1;
	uint8_t reg_opcode : 1;
	uint8_t _i_float : 1;

	uint8_t digit : 3;
	uint8_t code_offset : 3;
	uint8_t immediate_byte_num : 2;
	uint8_t i_float : 3;
}instruction_opcode_t;

typedef enum
{
	INSTRUCTION_OPERAND_ENCODING_ZO,
	INSTRUCTION_OPERAND_ENCODING_RM,
	INSTRUCTION_OPERAND_ENCODING_MR,
	INSTRUCTION_OPERAND_ENCODING_MI,
	INSTRUCTION_OPERAND_ENCODING_O,
	INSTRUCTION_OPERAND_ENCODING_OI,
	INSTRUCTION_OPERAND_ENCODING_I,
}instruction_operand_encoding_t;



typedef struct 
{
	instruction_opcode_t opcode;
	mnemonic_t mnemonic;
	int operand_num;
	operand_class_t operand[4];
	instruction_operand_encoding_t operand_encoding;
}instruction_item_t;

instruction_item_t get_instruction_item(lexed_instruction_t lexed_instruction);

int print_instruction_item(instruction_item_t instruction_item);

typedef struct
{
	mnemonic_t mnemonic;
	int operand_num;
	exact_operand_t operand[4];
}exact_instruction_t;

typedef struct 
{
	int offset;
	exact_instruction_t exact_instruction;
}instruction_item_iterator_t;

const instruction_item_t* next_instruction_item(instruction_item_iterator_t* iterator);