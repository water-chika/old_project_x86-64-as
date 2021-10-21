#include "assembler_frontend.h"
exact_operand_t convert_to_exact_operand(const char* operand_string);

exact_instruction_t convert_to_exact_instruction(const char* instruction_string)
{
    exact_instruction_t exact_instruction;
    char buff[128];
    strncpy(buff, instruction_string, sizeof(buff)-1);
    buff[127]='\0';
    assert(strlen(instruction_string) < sizeof(buff));
    const char* mnemonic_string = strtok(buff, " \n");
    const char* operand_string[4];

    exact_instruction.operand_num = 4;
    for (int i = 0; i < 4; i ++)
    {
        operand_string[i] = strtok(NULL, ",\n");
        if (operand_string[i] == NULL)
        {
            exact_instruction.operand_num = i;
            break;
        }
    }

    exact_instruction.mnemonic = lex_mnemonic(mnemonic_string);
    for (int i = 0; i < exact_instruction.operand_num; i++)
    {
        exact_instruction.operand[i] = convert_to_exact_operand(operand_string[i]);
    }

    return exact_instruction;
}
operand_size_t convert_to_operand_size(const char* operand_size_string)
{
    if (0 == strcmp(operand_size_string, "BYTE"))
    {
        return OPERAND_SIZE_BYTE;
    }
    else if (0 == strcmp(operand_size_string, "WORD"))
    {
        return OPERAND_SIZE_WORD;
    }
    else if (0 == strcmp(operand_size_string, "DOUBLEWORD"))
    {
        return OPERAND_SIZE_DOUBLEWORD;
    }
}

exact_operand_t convert_to_exact_operand(const char* operand_string)
{
    exact_operand_t exact_operand = {};
    if (operand_string[0]=='[')
    {
        if (operand_string[1]=='.')
        {
            exact_operand.operand_type = OPERAND_TYPE_MEMORY;
            exact_operand.memory_operand.address_type = MEMORY_ADDRESS_INSTRUCTION_RELATIVE;
            char* tail = NULL;
            exact_operand.memory_operand.instruction_relative_address = strtoll(operand_string+2, &tail, 10);
            assert(tail[0]==']');
            assert(tail[1]=='.');
            exact_operand.memory_operand.operand_size = convert_to_operand_size(tail+2);
        }
        else
        {
            assert(0);
        }
    }
    else if (operand_string[0] == '%')
    {
        assert(0);
    }
    else if (operand_string[0] == '$')
    {
        assert(0);
    }
}