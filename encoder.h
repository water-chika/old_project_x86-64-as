#ifndef ENCODER_H
#define ENCODER_H

//encoder get a binary instruction using instruction set table and a index to that instruction and a instruction.
#include "lexer.h"
#include <stdint.h>
typedef uint8_t byte_t;
typedef struct 
{
    byte_t code[15];
	int code_size; //code for a instruction is made of sevaral components.

	//some components is optional, so it's size maybe zero.
	//code_size should equal to sum of these components' size.
	int legacy_prefixes_size;
	int rex_prefix_size;
	int opcode_size;
	int mod_r_m_size;
	int sib_size;
	int displacement_size;
	int immediate_size;
}encoded_instruction_t;

encoded_instruction_t encode_instruction(lexed_instruction_t lexed_instruction);
#endif