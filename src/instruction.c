#include "instruction.h"
#include <stdio.h>
#include <assert.h>

instruction_item_t instruction_items[] = {
    //ADC
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
    {{1,0x10, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m8_compat}, {OPERAND_r8_compat}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MR},
    {{1,0x10, .exist_REX=1,._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m8}, {OPERAND_r8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MR},
    {{1,0x11, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m16}, {OPERAND_r16}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MR},
    {{1,0x11, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m32}, {OPERAND_r32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MR},
    {{1,0x11, .REX_W=1,._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r_m64}, {OPERAND_r64}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MR},
    {{1,0x12, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r8_compat}, {OPERAND_r_m8_compat}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM},
    {{1,0x12, .exist_REX=1, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r8}, {OPERAND_r_m8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM},
    {{1,0x13, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r16}, {OPERAND_r_m16}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM},
    {{1,0x13, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r32}, {OPERAND_r_m32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM},
    {{1,0x13, .REX_W=1, ._r=1}, .mnemonic=MNEMONIC_ADC,
        .operand_num=2, .operand={{OPERAND_r64}, {OPERAND_r_m64}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM},

    //ADD
    {
        {1,0x04, .ib=1}, .mnemonic=MNEMONIC_ADD,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER, REGISTER_AL},{OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },
    {
        {1,0x05, .iw=1}, .mnemonic=MNEMONIC_ADD,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER, REGISTER_AX},{OPERAND_imm16}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },
    {
        {1,0x05, .id=1}, .mnemonic=MNEMONIC_ADD,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER, REGISTER_EAX}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },
    {
        {1,0x05, .REX_W=1, .id=1}, .mnemonic=MNEMONIC_ADD,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER,REGISTER_RAX}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },
    {
        {1,0x01, ._r=1}, .mnemonic=MNEMONIC_ADD,
        .operand_num=2, .operand={{OPERAND_r_m32}, {OPERAND_r32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_MR,
    },

    //CMOVcc
    {
        {2, {0x0f, 0x47}, ._r=1}, .mnemonic=MNEMONIC_CMOVA,
        .operand_num=2, .operand={{OPERAND_r32}, {OPERAND_r_m32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM,
    },

    //CMP
    {
        {1,0x3c, .ib=1}, .mnemonic=MNEMONIC_CMP,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER,REGISTER_AL}, {OPERAND_imm8}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },
    {
        {1,0x3d, .iw=1}, .mnemonic=MNEMONIC_CMP,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER,REGISTER_AX}, {OPERAND_imm16}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },
    {
        {1,0x3d, .id=1}, .mnemonic=MNEMONIC_CMP,
        .operand_num=2, .operand={{OPERAND_CONSTANT_REGISTER,REGISTER_EAX}, {OPERAND_imm32}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_I,
    },

    //CLC
    {{1,0xf8},MNEMONIC_CLC, 
        0,{},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_ZO},
    //LEA
    {{1,0x8d, ._r=1}, .mnemonic = MNEMONIC_LEA,
        .operand_num=2, .operand={{OPERAND_r16}, {OPERAND_m}},
        .operand_encoding = INSTRUCTION_OPERAND_ENCODING_RM,
    },
    {
        {1,0x8d, ._r=1}, .mnemonic=MNEMONIC_LEA,
        .operand_num=2, .operand={{OPERAND_r32}, {OPERAND_m}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM,
    },
    {
        {1,0x8d, .REX_W=1, ._r=1}, .mnemonic=MNEMONIC_LEA,
        .operand_num=2, .operand={{OPERAND_r64}, {OPERAND_m}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_RM,
    },
    //MOV
    {{1,0xb8, .REX_W=1, .reg_opcode=1, .io=1}, .mnemonic=MNEMONIC_MOV,
        .operand_num=2, .operand={{OPERAND_r64}, {OPERAND_imm64}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_OI},
    //PUSH
    {
        {1,0x50, .reg_opcode=1}, .mnemonic=MNEMONIC_PUSH,
        .operand_num=1, .operand={{OPERAND_r64}},
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_O,
    },
    //RET
    {{1,0xc3}, .mnemonic=MNEMONIC_RET,
        .operand_num=0,
        .operand_encoding=INSTRUCTION_OPERAND_ENCODING_ZO},
    //SYSCALL
    {{2,{0x0f,0x05},}, .mnemonic=MNEMONIC_SYSCALL,
        .operand_num=0,
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


const instruction_item_t* next_instruction_item(instruction_item_iterator_t* iterator)
{
    for (int i = iterator->offset; i < sizeof(instruction_items)/sizeof(instruction_items[0]); i++)
    {
        instruction_item_t instruction_item = instruction_items[i];
        if (instruction_item.mnemonic == iterator->exact_instruction.mnemonic 
            && instruction_item.operand_num == iterator->exact_instruction.operand_num)
        {
            int flag = 1;
            for (int i = 0; i < iterator->exact_instruction.operand_num; i++)
            {
                if (!exact_operand_belong_operand_class(iterator->exact_instruction.operand[i], instruction_item.operand[i]))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)return &instruction_item;
        }
    }
    return NULL;
}