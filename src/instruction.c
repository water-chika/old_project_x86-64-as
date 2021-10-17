#include "instruction.h"
#include <stdio.h>
#include <assert.h>

instruction_item_t instruction_items[] = {
    {{1,0x14,.ib=1},MNEMONIC_ADC, 
        2, {{OPERAND_CONSTANT_REGISTER, REGISTER_AL}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I},
    {{1,0x15, .iw=1},MNEMONIC_ADC, 
        2, {{OPERAND_CONSTANT_REGISTER,REGISTER_AX}, {OPERAND_imm16}}, 
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I},
    {{1,0x15, .id=1},MNEMONIC_ADC, 
        2, {{OPERAND_CONSTANT_REGISTER, REGISTER_EAX}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I},
    {{1,0x15, .id=1, .REX_W=1},MNEMONIC_ADC,
        2, {{OPERAND_CONSTANT_REGISTER, REGISTER_RAX}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I},
    {{1,0x80, .e_digit=1, .digit=2, .ib=1},MNEMONIC_ADC, 
        2, {{OPERAND_r_m8_compat}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x80, .e_digit=1, .digit=2, .ib=1, .exist_REX=1},MNEMONIC_ADC, 
        2, {{OPERAND_r_m8}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x83, .e_digit=1, .digit=2, .ib=1},.mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m16}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x83, .e_digit=1, .digit=2, .ib=1},.mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m32}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x83, .REX_W=1,.e_digit=1, .digit=2, .ib=1},.mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m64}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x81, .e_digit=1, .digit=2, .iw=1},MNEMONIC_ADC, 
        2, {{OPERAND_r_m16}, {OPERAND_imm16}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x81, .e_digit=1, .digit=2, .id=1},MNEMONIC_ADC, 
        2, {{OPERAND_r_m32}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},
    {{1,0x81, .REX_W=1,.e_digit=1, .digit=2, .id=1},.mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m64}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MI},


    {{1,0xf8},MNEMONIC_CLC, 
        0,{},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_ZO},
};

instruction_item_t get_instruction_item(lexed_instruction_t lexed_instruction)
{
    for (int i = 0; i < sizeof(instruction_items)/sizeof(instruction_items[0]); i++)
    {
        instruction_item_t instruction_item = instruction_items[i];
        if (instruction_item.mnemonic == lexed_instruction.mnemonic 
            && instruction_item.operand_num == lexed_instruction.operand_num)
        {
            int flag = 1;
            for (int i = 0; i < instruction_item.operand_num; i++)
            {
                if (!belong_operand_class(lexed_instruction.operand[i], instruction_item.operand[i]))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)return instruction_item;
        }
    }
    assert(0);
}

int print_instruction_item(instruction_item_t instruction_item)
{
    print_mnemonic(instruction_item.mnemonic);
    putchar(' ');
    for (int i = 0; i < instruction_item.operand_num - 1; i++)
    {
        print_operand_class(instruction_item.operand[i]);
        putchar(',');
    }
    if (instruction_item.operand_num > 0)
    {
        print_operand_class(instruction_item.operand[instruction_item.operand_num-1]);
    }
    return 0;
}