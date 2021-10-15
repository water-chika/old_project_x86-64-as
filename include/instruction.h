#include <stdint.h>
#include "register.h"
#include "operand.h"
#include "mnemonic.h"
#include "lexer.h"

typedef struct 
{
	uint8_t opcode_num;
	uint8_t code[4];

	int NP : 1;
	int NFx : 1;
	int REX_W : 1;
	int e_digit : 1;
	int _r : 1;
	int e_code_offset : 1;
	int e_immediate : 1;
	int ib : 1;int iw : 1;int id : 1;int io : 1;
	int lsb3_opcode : 1;
	int _i_float : 1;

	uint8_t digit : 3;
	uint8_t code_offset : 3;
	uint8_t immediate_byte_num : 2;
	uint8_t i_float : 3;
}instruction_opcode_t;


typedef struct 
{
	instruction_opcode_t opcode;
	mnemonic_t mnemonic;
	int operand_num;
	operand_class_t operand[4];
}instruction_item_t;

instruction_item_t get_instruction_item(lexed_instruction_t lexed_instruction);

int print_instruction_item(instruction_item_t instruction_item);