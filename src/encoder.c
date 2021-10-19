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
    if (instruction_opcode.exist_REX){
        encoded_instruction.exist_rex_prefix = 1;
    }
	if (instruction_opcode.REX_W){
        encoded_instruction.exist_rex_prefix = 1;
        encoded_instruction.rex.W = 1;
    };
	if (instruction_opcode.e_digit){
        encoded_instruction.exist_mod_r_m = 1;
        encoded_instruction.mod_r_m.REG = instruction_opcode.digit;
    };
	if (instruction_opcode._r)
    {
        encoded_instruction.exist_mod_r_m = 1;
    }
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
    if (instruction_opcode.io){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 8;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
	if (instruction_opcode.lsb3_opcode)
    {
    };
	if (instruction_opcode._i_float)assert(0);

    if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_MI)
    {
        assert(lexed_instruction.operand[0].type != OPERAND_IMMEDIATE);
        assert(lexed_instruction.operand[1].type == OPERAND_IMMEDIATE);
        address_encoding_t address_encoding = encode_address(lexed_instruction.operand[0]);
        if (address_encoding.exist_operand_size_prefix)
        {
            encoded_instruction.exist_group3_prefix = 1;
            encoded_instruction.group3_prefix = GROUP3_PREFIX_OPERAND_SIZE_OVERRIDE;
        }
        encoded_instruction.exist_rex_prefix |= address_encoding.exist_rex;
        encoded_instruction.rex.B = address_encoding.rex_b;
        encoded_instruction.rex.W = address_encoding.rex_w;
        encoded_instruction.exist_mod_r_m = 1;
        encoded_instruction.mod_r_m.Mod = address_encoding.mod;
        encoded_instruction.mod_r_m.RM = address_encoding.r_m;
        encoded_instruction.exist_sib |= address_encoding.exist_sib;
        encoded_instruction.sib = address_encoding.sib;
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_ZO)
    {

    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_I)
    {

    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_MR)
    {
        assert(lexed_instruction.operand[0].type != OPERAND_IMMEDIATE);
        assert(lexed_instruction.operand[1].type == OPERAND_REGISTER);
        address_encoding_t address_encoding = encode_address(lexed_instruction.operand[0]);
        if (address_encoding.exist_operand_size_prefix)
        {
            encoded_instruction.exist_group3_prefix = 1;
            encoded_instruction.group3_prefix = GROUP3_PREFIX_OPERAND_SIZE_OVERRIDE;
        }
        encoded_instruction.exist_rex_prefix |= address_encoding.exist_rex;
        encoded_instruction.rex.B = address_encoding.rex_b;
        encoded_instruction.rex.W = address_encoding.rex_w;
        encoded_instruction.exist_mod_r_m = 1;
        encoded_instruction.mod_r_m.Mod = address_encoding.mod;
        encoded_instruction.mod_r_m.RM = address_encoding.r_m;
        encoded_instruction.exist_sib |= address_encoding.exist_sib;
        encoded_instruction.sib = address_encoding.sib;

        int reg_encode = encode_register_in_register_class(lexed_instruction.operand[1].reg);
        if (reg_encode >= 8)
        {
            encoded_instruction.exist_rex_prefix = 1;
            encoded_instruction.rex.R = 1;
            reg_encode -= 8;
        }
        assert(reg_encode < 8);
        encoded_instruction.mod_r_m.REG = reg_encode;
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_OI)
    {
        assert(lexed_instruction.operand[0].type == OPERAND_REGISTER);
        int reg_encode = encode_register_in_register_class(lexed_instruction.operand[0].reg);
        if (reg_encode >= 8)
        {
            encoded_instruction.exist_rex_prefix = 1;
            encoded_instruction.rex.B = 1;
            reg_encode -= 8;
        }
        encoded_instruction.opcode[0] |= reg_encode;
    }
    else
    {
        assert(0);
    }

    return encoded_instruction;
}

binary_instruction_t generate_binary_instruction(encoded_instruction_t encoded_instruction)
{
    binary_instruction_t code = {0};
    if (encoded_instruction.exist_group1_prefix)assert(0);
	if (encoded_instruction.exist_group2_prefix)assert(0);
	if (encoded_instruction.exist_group3_prefix){
        code.bytes[code.size++] = encoded_instruction.group3_prefix;
    };
	if (encoded_instruction.exist_group4_prefix)assert(0);
	if (encoded_instruction.exist_rex_prefix)
    {
        rex_prefix_t rex_prefix = encoded_instruction.rex;
        code.bytes[code.size++] = (rex_prefix.fix_code<<4) | (rex_prefix.W << 3) | (rex_prefix.R << 2) | (rex_prefix.X << 1) | (rex_prefix.B);
    };
	if (encoded_instruction.opcode_num)
    {
        for (int i = 0; i < encoded_instruction.opcode_num; i++)
        {
            code.bytes[code.size++] = encoded_instruction.opcode[i];
        }
    };
	if (encoded_instruction.exist_mod_r_m){
        mod_r_m_t mod_r_m = encoded_instruction.mod_r_m;
        code.bytes[code.size++] = (mod_r_m.Mod << 6) | (mod_r_m.REG << 3) | (mod_r_m.RM);
    };
	if (encoded_instruction.exist_sib)assert(0);
	if (encoded_instruction.exist_displacement)assert(0);
	if (encoded_instruction.exist_immediate)
    {
        immediate_t imm = encoded_instruction.immediate.imm;
        for (int i = 0; i < encoded_instruction.immediate.byte_num; i++)
        {
            code.bytes[code.size++] = imm & 0xff;
            imm >>= 8;
        }
    };
    return code;
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
            printf("%02x ", encoded_instruction.opcode[i]);
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