#include "encode/x_instruction.h"
#include <stdio.h>
#include <assert.h>
x_instruction_rex_prefix_t add_x_instruction_rex_prefix(x_instruction_rex_prefix_t a, x_instruction_rex_prefix_t b);
x_instruction_mod_rm_t add_x_instruction_mod_rm(x_instruction_mod_rm_t a, x_instruction_mod_rm_t b);
x_instruction_sib_t add_x_instruction_sib(x_instruction_sib_t a, x_instruction_sib_t b);
x_instruction_displacement_t add_x_instruction_disp(x_instruction_displacement_t a, x_instruction_displacement_t b);
x_instruction_immediate_t add_x_instruction_immediate(x_instruction_immediate_t a, x_instruction_immediate_t b);
x_instruction_t add_x_instruction(x_instruction_t a, x_instruction_t b)
{
    x_instruction_t result = {0};
    result.care_operand_size_override_prefix = a.care_operand_size_override_prefix | b.care_operand_size_override_prefix;
    result.exist_operand_size_override_prefix =
        a.care_operand_size_override_prefix & a.exist_operand_size_override_prefix |
        b.care_operand_size_override_prefix & b.exist_operand_size_override_prefix;
    assert(!(a.care_operand_size_override_prefix & b.care_operand_size_override_prefix & (a.exist_operand_size_override_prefix ^ b.exist_operand_size_override_prefix)));

    result.care_address_size_override_prefix = a.care_address_size_override_prefix | b.care_address_size_override_prefix;
    result.exist_address_size_override_prefix = 
        a.care_address_size_override_prefix & a.exist_address_size_override_prefix |
        b.care_address_size_override_prefix & b.exist_address_size_override_prefix;
    assert(!(a.care_address_size_override_prefix & b.care_address_size_override_prefix & (a.exist_address_size_override_prefix^b.exist_address_size_override_prefix)));

    result.care_segment_override_prefix = a.care_segment_override_prefix | b.care_segment_override_prefix;
    if (a.care_segment_override_prefix)
    {
        result.exist_segment_override_prefix = a.exist_segment_override_prefix;
        result.segemnt_override_prefix = a.segemnt_override_prefix;
        if (b.care_segment_override_prefix)
        {
            assert(a.exist_segment_override_prefix == b.exist_segment_override_prefix);
            assert(a.segemnt_override_prefix == b.segemnt_override_prefix);
        }
        else
        {
        }
    }
    else if (b.care_segment_override_prefix)
    {
        result.exist_segment_override_prefix = b.exist_segment_override_prefix;
        result.segemnt_override_prefix = b.segemnt_override_prefix;
    }

    result.care_lock_prefix = a.care_lock_prefix | b.care_lock_prefix;
    if (a.care_lock_prefix)
    {
        result.exist_lock_prefix = a.exist_lock_prefix;
        if (b.care_lock_prefix)
        {
            assert(a.exist_lock_prefix == b.exist_lock_prefix);
        }else{}
    }
    else if (b.care_lock_prefix)
    {
        result.exist_lock_prefix = b.exist_lock_prefix;
    }

    result.care_repeat_prefix = a.care_repeat_prefix | b.care_repeat_prefix;
    if (a.care_repeat_prefix)
    {
        result.exist_repeat_prefix = a.exist_repeat_prefix;
        if (b.care_repeat_prefix)
        {
            assert(a.exist_repeat_prefix == b.exist_repeat_prefix);
        }else{}
    }
    else if (b.care_repeat_prefix)
    {
        result.exist_repeat_prefix = b.exist_repeat_prefix;
    }

    result.care_rex_prefix = a.care_rex_prefix | b.care_rex_prefix;
    if (a.care_rex_prefix)
    {
        result.exist_rex_prefix = a.exist_rex_prefix;
        if (b.care_rex_prefix)
        {
            assert(a.exist_rex_prefix == b.exist_rex_prefix);
            if (a.exist_rex_prefix) result.rex_prefix = add_x_instruction_rex_prefix(a.rex_prefix, b.rex_prefix);
        }
        else
        {
            if (a.exist_rex_prefix) result.rex_prefix = a.rex_prefix;
        }
    }
    else if (b.care_rex_prefix)
    {
        result.exist_rex_prefix = b.exist_rex_prefix;
        if (b.exist_rex_prefix) result.rex_prefix = b.rex_prefix;
    }

    result.care_primary_opcode = a.care_primary_opcode | b.care_primary_opcode;
    if (a.care_primary_opcode)
    {
        result.exist_primary_opcode = a.exist_primary_opcode;
        if (b.care_primary_opcode)
        {
            assert(a.exist_primary_opcode == b.exist_primary_opcode);
            assert(a.primary_opcode == b.primary_opcode);
            if (a.exist_primary_opcode) result.primary_opcode = a.primary_opcode;
        }
        else
        {
            if (a.exist_primary_opcode) result.primary_opcode = a.primary_opcode;
        }
    }
    else if (b.care_primary_opcode)
    {
        result.exist_primary_opcode = b.exist_primary_opcode;
        if (b.exist_primary_opcode)result.primary_opcode = b.primary_opcode;
    }

    result.care_mod_rm = a.care_mod_rm | b.care_mod_rm;
    if (a.care_mod_rm)
    {
        result.exist_mod_rm = a.exist_mod_rm;
        if (b.care_mod_rm)
        {
            assert(a.exist_mod_rm == b.exist_mod_rm);
            if (a.exist_mod_rm) result.mod_rm = add_x_instruction_mod_rm(a.mod_rm, b.mod_rm);
        }
        else
        {
            if (a.exist_mod_rm) result.mod_rm = a.mod_rm;
        }
    }
    else if (b.care_mod_rm)
    {
        result.exist_mod_rm = b.exist_mod_rm;
        if (b.exist_mod_rm)result.mod_rm = b.mod_rm;
    }

    result.care_sib = a.care_sib | b.care_sib;
    if (a.care_sib)
    {
        result.exist_sib = a.exist_sib;
        if (b.care_sib)
        {
            assert(a.exist_sib == b.exist_sib);
            if (a.exist_sib) result.sib = add_x_instruction_sib(a.sib, b.sib);
        }
        else
        {
            if (a.exist_sib) result.sib = a.sib;
        }
    }

    result.care_disp = a.care_disp | b.care_disp;
    if (a.care_disp)
    {
        result.exist_disp = a.exist_disp;
        if (b.care_disp)
        {
            assert(a.exist_disp == b.exist_disp);
            if (a.exist_disp) result.disp = add_x_instruction_disp(a.disp, b.disp);
        }
        else
        {
            if (a.exist_disp)result.disp = a.disp;
        }
    }
    else if (b.care_disp)
    {
        result.exist_disp = b.exist_disp;
        if (b.exist_disp)
        {
            result.disp = b.disp;
        }
    }

    result.care_immediate = a.care_immediate | b.care_immediate;
    if (a.care_immediate)
    {
        result.exist_immediate = a.exist_immediate;
        if (b.care_immediate)
        {
            assert(a.exist_immediate == b.exist_immediate);
            if (a.exist_immediate) result.immediate = add_x_instruction_immediate(a.immediate, b.immediate);
        }
        else
        {
            if (a.exist_immediate)result.immediate = a.immediate;
        }
    }
    else if (b.care_immediate)
    {
        result.exist_immediate = b.care_immediate;
        if (a.exist_immediate)
        {
            result.immediate = b.immediate;
        }
    }

    return result;
}

x_instruction_rex_prefix_t add_x_instruction_rex_prefix(x_instruction_rex_prefix_t a, x_instruction_rex_prefix_t b)
{
    x_instruction_rex_prefix_t result = {};

    result.care_b = a.care_b | b.care_b;
    if (a.care_b)
    {
        result.b = a.b;
        if (b.care_b) assert(a.b == b.b);
    }
    else if (b.care_b)
    {
        result.b = b.b;
    }

    result.care_r = a.care_r | b.care_r;
    if (a.care_r)
    {
        result.r = a.r;
        if (b.care_r) assert(a.r == b.r);
    }
    else if (b.care_r)
    {
        result.r = b.r;
    }

    result.care_w = a.care_w | b.care_w;
    if (a.care_w)
    {
        result.w = a.w;
        if (b.care_w) assert(a.w == b.w);
    }
    else if (b.care_w)
    {
        result.w = b.w;
    }

    result.care_x = a.care_x | b.care_x;
    if (a.care_x)
    {
        result.x = a.x;
        if (b.care_x) assert(a.x == b.x);
    }
    else if (b.care_x)
    {
        result.x = b.x;
    }

    return result;
}
x_instruction_mod_rm_t add_x_instruction_mod_rm(x_instruction_mod_rm_t a, x_instruction_mod_rm_t b)
{
    x_instruction_mod_rm_t result = {};

    result.care_mod = a.care_mod | b.care_mod;
    if (a.care_mod)
    {
        result.mod = a.mod;
        if (b.care_mod) assert(a.mod == b.mod);
    }
    else if (b.care_mod)
    {
        result.mod = b.mod;
    }

    result.care_reg = a.care_reg | b.care_reg;
    if (a.care_reg)
    {
        result.reg = a.reg;
        if (b.care_reg) assert(a.reg == b.reg);
    }
    else if (b.care_reg)
    {
        result.reg = b.reg;
    }

    result.care_rm = a.care_rm | b.care_rm;
    if (a.care_rm)
    {
        result.rm = a.rm;
        if (b.care_rm) assert(a.rm == b.rm);
    }
    else if (b.care_rm)
    {
        result.rm = b.rm;
    }

    return result;
}
x_instruction_sib_t add_x_instruction_sib(x_instruction_sib_t a, x_instruction_sib_t b)
{
    x_instruction_sib_t result = {0};

    result.care_base = a.care_base | b.care_base;
    if (a.care_base)
    {
        result.base = a.base;
        if (b.care_base) assert(a.base == b.base);
    }
    else if (b.care_base)
    {
        result.base = b.base;
    }

    result.care_index = a.care_index | b.care_index;
    if (a.care_index)
    {
        result.index = a.index;
        if (b.care_index) assert(a.index == b.index);
    }
    else if (b.care_index)
    {
        result.index = b.index;
    }

    result.care_scale = a.care_scale | b.care_scale;
    if (a.care_scale)
    {
        result.scale = a.scale;
        if (b.care_scale) assert(a.scale == b.scale);
    }
    else if (b.care_scale)
    {
        result.scale = b.scale;
    }
    return result;
}
x_instruction_displacement_t add_x_instruction_disp(x_instruction_displacement_t a, x_instruction_displacement_t b)
{
    x_instruction_displacement_t result;
    result.care_width = a.care_width | b.care_width;
    if (a.care_width)
    {
        result.width = a.width;
        if (b.care_width) assert(a.width == b.width);
    }
    else if (b.care_width)
    {
        result.width = b.width;
    }

    result.displacement = a.displacement;
    assert(a.displacement == b.displacement);
    return result;
}
x_instruction_immediate_t add_x_instruction_immediate(x_instruction_immediate_t a, x_instruction_immediate_t b)
{
    x_instruction_immediate_t result;
    result.care_width = a.care_width | b.care_width;
    if (a.care_width)
    {
        result.width = a.width;
        if (b.care_width) assert(a.width == b.width);
    }
    else if (b.care_width)
    {
        result.width = b.width;
    }

    result.immediate = a.immediate;
    assert(a.immediate == b.immediate);
    return result;
}

uint8_t generate_rex_prefix_byte(x_instruction_rex_prefix_t x_instruction_rex_prefix);
uint8_t generate_mod_rm_byte(x_instruction_mod_rm_t x_instruction_mod_rm);
uint8_t generate_sib_byte(x_instruction_sib_t x_instruction_sib);
amd64_binary_instruction_t generate_binary_instruction(x_instruction_t x_instruction)
{
    amd64_binary_instruction_t binary_code = {};
    if (x_instruction.care_operand_size_override_prefix && x_instruction.exist_operand_size_override_prefix)
    {
        binary_code.code[binary_code.byte_num++] = 0x66;
    }
    if (x_instruction.care_address_size_override_prefix && x_instruction.exist_address_size_override_prefix)
    {
        binary_code.code[binary_code.byte_num++] = 0x67;
    }
    if (x_instruction.care_segment_override_prefix)
    {
        assert(0);
    }
    if (x_instruction.care_lock_prefix)
    {
        assert(0);
    }
    if (x_instruction.care_repeat_prefix)
    {
        assert(0);
    }
    if (x_instruction.care_rex_prefix && x_instruction.exist_rex_prefix)
    {
        binary_code.code[binary_code.byte_num++] = generate_rex_prefix_byte(x_instruction.rex_prefix);
    }
    if (x_instruction.care_primary_opcode && x_instruction.exist_primary_opcode)
    {
        binary_code.code[binary_code.byte_num++] = x_instruction.primary_opcode;
    }
    if (x_instruction.care_mod_rm && x_instruction.exist_mod_rm)
    {
        binary_code.code[binary_code.byte_num++] = generate_mod_rm_byte(x_instruction.mod_rm);
    }
    if (x_instruction.care_sib && x_instruction.exist_sib)
    {
        binary_code.code[binary_code.byte_num++] = generate_sib_byte(x_instruction.sib);
    }
    if (x_instruction.care_disp && x_instruction.exist_disp)
    {
        assert(x_instruction.disp.care_width);
        assert(x_instruction.disp.width%8 == 0);
        assert(x_instruction.disp.width/8 < 8);
        int len = x_instruction.disp.width/8;
        int disp = x_instruction.disp.displacement;
        for (int i = 0; i < x_instruction.disp.width/8; i++)
        {
            binary_code.code[binary_code.byte_num++] = disp;
            disp >>= 8;
        }
    }
    if (x_instruction.care_immediate && x_instruction.exist_immediate)
    {
        assert(x_instruction.immediate.care_width);
        assert(x_instruction.immediate.width%8 == 0);
        assert(x_instruction.immediate.width/8 < 8);
        int len = x_instruction.immediate.width / 8;
        int imm = x_instruction.immediate.immediate;
        for (int i = 0; i < len; i++)
        {
            binary_code.code[binary_code.byte_num++] = imm;
            imm >>= 8;
        }
    }
    return binary_code;
}
uint8_t generate_mod_rm_byte(x_instruction_mod_rm_t x_instruction_mod_rm)
{
    assert(x_instruction_mod_rm.care_mod && x_instruction_mod_rm.care_reg && x_instruction_mod_rm.care_rm);
    return (x_instruction_mod_rm.mod << 6) | (x_instruction_mod_rm.reg << 3) | (x_instruction_mod_rm.rm);
}
uint8_t generate_sib_byte(x_instruction_sib_t x_instruction_sib)
{
    assert(x_instruction_sib.care_base && x_instruction_sib.care_index && x_instruction_sib.care_scale);
    return (x_instruction_sib.scale << 6) | (x_instruction_sib.index << 3) | (x_instruction_sib.base);
    assert(0);
}

uint8_t generate_rex_prefix_byte(x_instruction_rex_prefix_t x_instruction_rex_prefix)
{
    return 0x40 | (x_instruction_rex_prefix.w << 3) | (x_instruction_rex_prefix.r << 2) | (x_instruction_rex_prefix.x << 1) | (x_instruction_rex_prefix.b);
}