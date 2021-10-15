#include "encoder.h"
#include <assert.h>
#include <stdio.h>

encoded_instruction_t encode_instruction(instruction_item_t instruction_item, lexed_instruction_t lexed_instruction)
{
    encoded_instruction_t encoded_instruction = {};
    instruction_opcode_t instruction_opcode = instruction_item.opcode;
    encoded_instruction.opcode_num = instruction_opcode.opcode_num;
    for (int i = 0; i < encoded_instruction.opcode_num; i++)
    {
        encoded_instruction.opcode[i] = instruction_opcode.code[i];
    }

    if (instruction_opcode.NP)assert(0);
	if (instruction_opcode.NFx)assert(0);
	if (instruction_opcode.REX_W)assert(0);
	if (instruction_opcode.e_digit)assert(0);
	if (instruction_opcode._r)assert(0);
	if (instruction_opcode.e_code_offset)assert(0);
	if (instruction_opcode.e_immediate)assert(0);
	if (instruction_opcode.ib)assert(0);
    if (instruction_opcode.iw){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 4;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.id)assert(0);
    if (instruction_opcode.io)assert(0);
	if (instruction_opcode.lsb3_opcode) assert(0);
	if (instruction_opcode._i_float)assert(0);

    return encoded_instruction;
}

void print_encoded_instruction(encoded_instruction_t encoded_instruction)
{
    if (encoded_instruction.exist_group1_prefix)assert(0);
	if (encoded_instruction.exist_group2_prefix)assert(0);
	if (encoded_instruction.exist_group3_prefix)assert(0);
	if (encoded_instruction.exist_group4_prefix)assert(0);
	if (encoded_instruction.exist_rex_prefix)printf("REX ");
	if (encoded_instruction.opcode_num)
    {
        for (int i = 0; i < encoded_instruction.opcode_num; i++)
        {
            printf("%x ", encoded_instruction.opcode[i]);
        }
    };
	if (encoded_instruction.exist_mod_r_m)assert(0);
	if (encoded_instruction.exist_sib)assert(0);
	if (encoded_instruction.exist_displacement)assert(0);
	if (encoded_instruction.exist_immediate)
    {
        for (int i = 0; i < encoded_instruction.immediate.byte_num; i++)
        {
            printf("%02x ", *(i+(uint8_t*)(&encoded_instruction.immediate.imm)));
        }
    };
}