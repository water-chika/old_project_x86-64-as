#include "encode/x_instruction_operand.h"
#include <assert.h>
#include <stdlib.h>

x_instruction_t x_instruction_opcode(uint8_t opcode)
{
    x_instruction_t x_instruction = {};
    switch (opcode)
    {
        case 0x00:
        x_instruction.care_primary_opcode = 1;
        x_instruction.exist_primary_opcode = 1;
        x_instruction.primary_opcode = opcode;
        break;
        default:
        assert(0);
    }
    
    return x_instruction;
}
x_instruction_t x_instruction_operand_Eb(amd64_operand_t operand)
{
    x_instruction_t x_instruction;

    if (operand.operand_type == AMD64_OPERAND_TYPE_REGISTER)
    {
        assert(operand.reg.amd64_register_namespace == AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER);
        assert(operand.reg.width == 8);
        assert(operand.reg.start_address.x == 0);
        assert(operand.reg.start_address.z == 0);
        assert(operand.reg.next == NULL);
        if (operand.reg.start_address.y >=4)
        {
            x_instruction.care_rex_prefix = 1;
            x_instruction.exist_rex_prefix = 1;
            if (operand.reg.start_address.y >=8)
            {
                x_instruction.rex_prefix.care_b = 1;
                x_instruction.rex_prefix.b = 1;
            }
        }
    }
    else
    {
        assert(0);
    }
}
x_instruction_t x_instruction_operand_Gb(amd64_operand_t operand)
{
    x_instruction_t x_instruction = {};

    assert(operand.operand_type == AMD64_OPERAND_TYPE_REGISTER);
    assert(operand.reg.amd64_register_namespace = AMD64_BITS_NAMESPACE_GENERAL_PURPOSE_REGISTER);
    assert(operand.reg.width == 8);
    assert(operand.reg.start_address.x == 0);
    assert(operand.reg.start_address.z == 0);
    assert(operand.reg.next == NULL);
    if (operand.reg.start_address.y >=4 )
    {
        x_instruction.care_rex_prefix = 1;
        x_instruction.exist_rex_prefix = 1;
        if (operand.reg.start_address.y >=8)
        {
            x_instruction.rex_prefix.care_r = 1;
            x_instruction.rex_prefix.r = 1;
        }
    }
    x_instruction.care_mod_rm = 1;
    x_instruction.exist_mod_rm = 1;
    x_instruction.mod_rm.care_reg = 1;
    x_instruction.mod_rm.reg = operand.reg.start_address.y & 0x7;

    return x_instruction;
}