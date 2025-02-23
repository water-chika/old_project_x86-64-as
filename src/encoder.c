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
            if (lexed_instruction.operand[i].type == OPERAND_TYPE_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.iw){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 2;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_TYPE_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.id){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 4;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_TYPE_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
    if (instruction_opcode.io){
        encoded_instruction.exist_immediate = 1;
        encoded_instruction.immediate.byte_num = 8;
        for (int i = 0; i < lexed_instruction.operand_num; i++)
        {
            if (lexed_instruction.operand[i].type == OPERAND_TYPE_IMMEDIATE)
                encoded_instruction.immediate.imm = lexed_instruction.operand[i].imm;
        }
    };
	if (instruction_opcode.reg_opcode)
    {assert(0);
    };
	if (instruction_opcode._i_float)assert(0);

    int exist_mod_r_m_m_operand = 0;
    operand_t mod_r_m_m_operand = {};
    int exist_mod_r_m_r_operand = 0;
    operand_t mod_r_m_r_operand = {};
    if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_MI)
    {
        exist_mod_r_m_m_operand = 1;
        mod_r_m_m_operand = lexed_instruction.operand[0];
        assert(lexed_instruction.operand[0].type != OPERAND_TYPE_IMMEDIATE);
        assert(lexed_instruction.operand[1].type == OPERAND_TYPE_IMMEDIATE);
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_ZO)
    {

    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_I)
    {
        assert(lexed_instruction.operand[0].type == OPERAND_TYPE_REGISTER);
        if (belong_to_register_class(lexed_instruction.operand[0].reg, REGISTER_CLASS_R16))
        {
            encoded_instruction.exist_group3_prefix=1;
            encoded_instruction.group3_prefix=GROUP3_PREFIX_OPERAND_SIZE_OVERRIDE;
        }
        else if (belong_to_register_class(lexed_instruction.operand[0].reg, REGISTER_CLASS_R8))
        {
        }
        else if (belong_to_register_class(lexed_instruction.operand[0].reg, REGISTER_CLASS_R64))
        {

        }
        else if (belong_to_register_class(lexed_instruction.operand[0].reg, REGISTER_CLASS_R32))
        {
        }
        else
        {
            assert(0);
        }
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_MR)
    {
        exist_mod_r_m_m_operand = 1;
        mod_r_m_m_operand = lexed_instruction.operand[0];
        exist_mod_r_m_r_operand = 1;
        mod_r_m_r_operand = lexed_instruction.operand[1];
        assert(lexed_instruction.operand[0].type != OPERAND_TYPE_IMMEDIATE);
        assert(lexed_instruction.operand[1].type == OPERAND_TYPE_REGISTER);
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_RM)
    {
        exist_mod_r_m_m_operand = 1;
        mod_r_m_m_operand = lexed_instruction.operand[1];
        exist_mod_r_m_r_operand = 1;
        mod_r_m_r_operand = lexed_instruction.operand[0];
        assert(lexed_instruction.operand[1].type != OPERAND_TYPE_IMMEDIATE);
        assert(lexed_instruction.operand[0].type == OPERAND_TYPE_REGISTER);
    }
    else if (instruction_item.operand_encoding == INSTRUCTION_OPERAND_ENCODING_OI)
    {
        assert(lexed_instruction.operand[0].type == OPERAND_TYPE_REGISTER);
        int reg_encode = encode_general_purpose_register(lexed_instruction.operand[0].reg);
        if (reg_encode >= 8)
        {
            encoded_instruction.exist_rex_prefix = 1;
            encoded_instruction.rex.R = 1;
            reg_encode -= 8;
        }
        assert(reg_encode < 8);
        encoded_instruction.opcode[0] |= reg_encode;
    }
    else
    {
        assert(0);
    }

    if (exist_mod_r_m_r_operand)
    {
        encoded_instruction.exist_mod_r_m = 1;
        assert(mod_r_m_r_operand.type == OPERAND_TYPE_REGISTER);
        int reg_encode = encode_general_purpose_register(mod_r_m_r_operand.reg);
        if (reg_encode >= 8)
        {
            encoded_instruction.exist_rex_prefix = 1;
            encoded_instruction.rex.R = 1;
            reg_encode -= 8;
        }
        assert(reg_encode < 8);
        encoded_instruction.mod_r_m.REG = reg_encode;
    }

    if (exist_mod_r_m_m_operand)
    {
        encoded_instruction.exist_mod_r_m = 1;
        address_encoding_t address_encoding = encode_address(mod_r_m_m_operand);
        if (address_encoding.exist_operand_size_prefix)
        {
            encoded_instruction.exist_group3_prefix = 1;
            encoded_instruction.group3_prefix = GROUP3_PREFIX_OPERAND_SIZE_OVERRIDE;
        }
        if (address_encoding.exist_rex)
        {
            encoded_instruction.exist_rex_prefix = address_encoding.exist_rex;
            encoded_instruction.rex.B = address_encoding.rex_b;
            encoded_instruction.rex.W = address_encoding.rex_w;
        }
        encoded_instruction.mod_r_m.Mod = address_encoding.mod;
        encoded_instruction.mod_r_m.RM = address_encoding.r_m;
        encoded_instruction.exist_sib |= address_encoding.exist_sib;
        encoded_instruction.sib = address_encoding.sib;
        encoded_instruction.exist_displacement = address_encoding.exist_disp;
        encoded_instruction.displacement = address_encoding.disp;
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
	if (encoded_instruction.exist_displacement)
    {
        uint32_t disp = encoded_instruction.displacement.disp;
        for (int i = 0; i < encoded_instruction.displacement.byte_num; i++)
        {
            code.bytes[code.size++] = disp & 0xff;
            disp >>= 8;
        }
    }
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
	if (encoded_instruction.exist_displacement)
    {
        for (int i = 0; i < encoded_instruction.displacement.byte_num; i++)
        {
            printf("%02x ", (encoded_instruction.displacement.disp>>(8*i) )& 0xff);
        }
    }
	if (encoded_instruction.exist_immediate)
    {
        for (int i = 0; i < encoded_instruction.immediate.byte_num; i++)
        {
            printf("%02x ", *(i+(uint8_t*)(&encoded_instruction.immediate.imm)));
        }
    };
}

encoded_instruction_t encode_exact_instruction(exact_instruction_t exact_instruction)
{
    instruction_item_iterator_t instruction_item_iterator = {.exact_instruction=exact_instruction};
    const instruction_item_t* instruction_item = next_instruction_item(&instruction_item_iterator);
    assert(0);
}