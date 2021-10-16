#include "encoder.h"
#include <assert.h>
#include <stdio.h>
#include "address_encoding.h"


encoded_instruction_t encode_instruction(instruction_item_t instruction_item, lexed_instruction_t lexed_instruction)
{
    encoded_instruction_t encoded_instruction = {};
    encoded_instruction.rex.fix_code = 0x4;
    instruction_opcode_t instruction_opcode = instruction_item.opcode;
    encoded_instruction.opcode_num = instruction_opcode.opcode_num;
    for (int i = 0; i < encoded_instruction.opcode_num; i++)
    {
        encoded_instruction.opcode[i] = instruction_opcode.code[i];
    }

    if (instruction_opcode.NP)assert(0);
	if (instruction_opcode.NFx)assert(0);
	if (instruction_opcode.REX_W){
        encoded_instruction.exist_rex_prefix = 1;
        encoded_instruction.rex.W = 1;
    };
	if (instruction_opcode.e_digit){
        encoded_instruction.exist_mod_r_m = 1;
        encoded_instruction.mod_r_m.REG = instruction_opcode.digit;
    };
	if (instruction_opcode._r)assert(0);
	if (instruction_opcode.e_code_offset)assert(0);
	if (instruction_opcode.e_immediate)assert(0);
	if (instruction_opcode.ib)
    {
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 1;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.iw){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.exist_group3_prefix = 1;
        encoded_instruction.group3_prefix = GROUP3_PREFIX_OPERAND_SIZE_OVERRIDE;
        encoded_instruction.immediate.byte_num = 2;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.id){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 4;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.io)assert(0);
	if (instruction_opcode.lsb3_opcode) assert(0);
	if (instruction_opcode._i_float)assert(0);

    if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_MI)
    {
        address_encoding_t address_encoding = encode_address(lexed_instruction.operand[0]);
        if (address_encoding.exist_rex)encoded_instruction.exist_rex_prefix = 1;
        encoded_instruction.mod_r_m.Mod = address_encoding.mod;
        encoded_instruction.mod_r_m.RM = address_encoding.r_m;
        encoded_instruction.exist_sib=address_encoding.exist_sib;
        encoded_instruction.sib = address_encoding.sib;
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_ZO)
    {

    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_I)
    {

    }
    else
    {
        assert(0);
    }

    return encoded_instruction;
}

void print_encoded_instruction(encoded_instruction_t encoded_instruction)
{
    if (encoded_instruction.exist_group1_prefix)assert(0);
	if (encoded_instruction.exist_group2_prefix)assert(0);
	if (encoded_instruction.exist_group3_prefix){
        printf("%02x ", encoded_instruction.group3_prefix);
    };
	if (encoded_instruction.exist_group4_prefix)assert(0);
	if (encoded_instruction.exist_rex_prefix)
    {
        rex_prefix_t rex_prefix = encoded_instruction.rex;
        printf("%02x ", (rex_prefix.fix_code<<4) | (rex_prefix.W << 3) | (rex_prefix.R << 2) | (rex_prefix.X << 1) | (rex_prefix.B));
    };
	if (encoded_instruction.opcode_num)
    {
        for (int i = 0; i < encoded_instruction.opcode_num; i++)
        {
            printf("%x ", encoded_instruction.opcode[i]);
        }
    };
	if (encoded_instruction.exist_mod_r_m){
        mod_r_m_t mod_r_m = encoded_instruction.mod_r_m;
        printf("%02x ", (mod_r_m.Mod << 6) | (mod_r_m.REG << 3) | (mod_r_m.RM));
    };
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