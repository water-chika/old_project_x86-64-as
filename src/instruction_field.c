#include "instruction_field.h"
#include <stdio.h>


reg_field_t encode_reg_field_non_64_bit_mode(x86_64_register_t reg, int exist_w, w_field_t w_field, operation_data_size_t operation_data_size)
{
    reg_field_t reg_field = 0;
    if (!exist_w)
    {
        if (operation_data_size == OPERATION_DATA_SIZE_16BIT)
        {
            switch (reg)
            {
            case REGISTER_AX:reg_field = 0;break;
            case REGISTER_CX:reg_field = 1;break;
            case REGISTER_DX:reg_field = 2;break;
            case REGISTER_BX:reg_field = 3;break;
            case REGISTER_SP:reg_field = 4;break;
            case REGISTER_BP:reg_field = 5;break;
            case REGISTER_SI:reg_field = 6;break;
            case REGISTER_DI:reg_field = 7;break;
            default:assert(0);break;
            }
        }
        else if (operation_data_size == OPERATION_DATA_SIZE_32BIT)
        {
            switch (reg)
            {
            case REGISTER_EAX:
                reg_field = 0;
                break;
            case REGISTER_ECX:
                reg_field = 1;
                break;
            case REGISTER_EDX:
                reg_field = 2;
                break;
            case REGISTER_EBX:
                reg_field = 3;
                break;
            case REGISTER_ESP:
                reg_field = 4;
                break;
            case REGISTER_EBP:
                reg_field = 5;
                break;
            case REGISTER_ESI:
                reg_field = 6;
                break;
            case REGISTER_EDI:
                reg_field = 7;
                break;
            default:
                assert(0);
                break;
            }
        }
        else
        {
            fprintf(stderr, "Error operation data size\n");
            assert(0);
        }
    }
    else
    {
        if (operation_data_size == OPERATION_DATA_SIZE_16BIT)
        {
            if (w_field == 0)
            {
                switch (reg)
                {
                case REGISTER_AL:
                    reg_field = 0;
                    break;
                case REGISTER_CL:
                    reg_field = 1;
                    break;
                case REGISTER_DL:
                    reg_field = 2;
                    break;
                case REGISTER_BL:
                    reg_field = 3;
                    break;
                case REGISTER_AH:
                    reg_field = 4;
                    break;
                case REGISTER_CH:
                    reg_field = 5;
                    break;
                case REGISTER_DH:
                    reg_field = 6;
                    break;
                case REGISTER_BH:
                    reg_field = 7;
                    break;
                default:
                    assert(0);
                    break;
                }
            }
            else
            {
                switch (reg)
                {
                case REGISTER_AX:
                    reg_field = 0;
                    break;
                case REGISTER_CX:
                    reg_field = 1;
                    break;
                case REGISTER_DX:
                    reg_field = 2;
                    break;
                case REGISTER_BX:
                    reg_field = 3;
                    break;
                case REGISTER_SP:
                    reg_field = 4;
                    break;
                case REGISTER_BP:
                    reg_field = 5;
                    break;
                case REGISTER_SI:
                    reg_field = 6;
                    break;
                case REGISTER_DI:
                    reg_field = 7;
                    break;
                default:
                    assert(0);
                    break;
                }
            }
        }
        else if (operation_data_size == OPERATION_DATA_SIZE_32BIT)
        {
            if (w_field == 0)
            {
                switch (reg)
                {
                case REGISTER_AL:
                    reg_field = 0;
                    break;
                case REGISTER_CL:
                    reg_field = 1;
                    break;
                case REGISTER_DL:
                    reg_field = 2;
                    break;
                case REGISTER_BL:
                    reg_field = 3;
                    break;
                case REGISTER_AH:
                    reg_field = 4;
                    break;
                case REGISTER_CH:
                    reg_field = 5;
                    break;
                case REGISTER_DH:
                    reg_field = 6;
                    break;
                case REGISTER_BH:
                    reg_field = 7;
                    break;
                default:
                    assert(0);
                    break;
                }
            }
            else
            {
                switch (reg)
                {
                case REGISTER_EAX:
                    reg_field = 0;
                    break;
                case REGISTER_ECX:
                    reg_field = 1;
                    break;
                case REGISTER_EDX:
                    reg_field = 2;
                    break;
                case REGISTER_EBX:
                    reg_field = 3;
                    break;
                case REGISTER_ESP:
                    reg_field = 4;
                    break;
                case REGISTER_EBP:
                    reg_field = 5;
                    break;
                case REGISTER_ESI:
                    reg_field = 6;
                    break;
                case REGISTER_EDI:
                    reg_field = 7;
                    break;
                default:
                    assert(0);
                    break;
                }
            }
        }
        else
        {
            fprintf(stderr, "Error operation data size\n");
            assert(0);
        }
    }
    return reg_field;
}

reg_field_t encode_reg_field_64_bit_mode(x86_64_register_t reg, int exist_w, w_field_t w_field, operation_data_size_t operation_data_size)
{
    reg_field_t reg_field = 0;
    if (!exist_w)
    {
        if (operation_data_size == OPERATION_DATA_SIZE_16BIT)
        {
            switch (reg)
            {
                case REGISTER_AX:reg_field=0;break;
                case REGISTER_CX:reg_field=1;break;
                case REGISTER_DX:reg_field=2;break;
                case REGISTER_BX:reg_field=3;break;
                case REGISTER_SP:reg_field=4;break;
                case REGISTER_BP:reg_field=5;break;
                case REGISTER_SI:reg_field=6;break;
                case REGISTER_DI:reg_field=7;break;
                default:assert(0);break;
            }
        }
        else if (operation_data_size == OPERATION_DATA_SIZE_32BIT)
        {
            switch (reg)
            {
                case REGISTER_EAX:reg_field=0;break;
                case REGISTER_ECX:reg_field=1;break;
                case REGISTER_EDX:reg_field=2;break;
                case REGISTER_EBX:reg_field=3;break;
                case REGISTER_ESP:reg_field=4;break;
                case REGISTER_EBP:reg_field=5;break;
                case REGISTER_ESI:reg_field=6;break;
                case REGISTER_EDI:reg_field=7;break;
                default:assert(0);break;
            }
        }
        else if (operation_data_size == OPERATION_DATA_SIZE_64BIT)
        {
            switch (reg)
            {
                case REGISTER_RAX:reg_field=0;break;
                case REGISTER_RCX:reg_field=1;break;
                case REGISTER_RDX:reg_field=2;break;
                case REGISTER_RBX:reg_field=3;break;
                case REGISTER_RSP:reg_field=4;break;
                case REGISTER_RBP:reg_field=5;break;
                case REGISTER_RSI:reg_field=6;break;
                case REGISTER_RDI:reg_field=7;break;
                default:assert(0);break;
            }
        }
        else
        {
            fprintf(stderr, "Error operation data size\n");
            assert(0);
        }
    }
    else if (exist_w)
    {
        if (operation_data_size == OPERATION_DATA_SIZE_16BIT)
        {
            if (w_field == 0)
            {
                switch (reg)
                {
                    case REGISTER_AL: reg_field = 0;break;
                    case REGISTER_CL: reg_field = 1;break;
                    case REGISTER_DL: reg_field = 2;break;
                    case REGISTER_BL: reg_field = 3;break;
                    default: assert(0);break;
                }
            }
            else if (w_field == 1)
            {
                switch (reg)
                {
                    case REGISTER_AX: reg_field = 0;break;
                    case REGISTER_CX: reg_field = 1;break;
                    case REGISTER_DX: reg_field = 2;break;
                    case REGISTER_BX: reg_field = 3;break;
                    case REGISTER_SP: reg_field = 4;break;
                    case REGISTER_BP: reg_field = 5;break;
                    case REGISTER_SI: reg_field = 6;break;
                    case REGISTER_DI: reg_field = 7;break;
                    default: assert(0);break;
                }
            }
            else
            {
                fprintf(stderr, "Error w field\n");
                assert(0);
            }
        }
        if (operation_data_size == OPERATION_DATA_SIZE_32BIT)
        {
            if (w_field == 0)
            {
                switch (reg)
                {
                    case REGISTER_AL: reg_field = 0;break;
                    case REGISTER_CL: reg_field = 1;break;
                    case REGISTER_DL: reg_field = 2;break;
                    case REGISTER_BL: reg_field = 3;break;
                    default:assert(0);break;
                }
            }
            else if (w_field == 1)
            {
                switch (reg)
                {
                    case REGISTER_EAX: reg_field = 0;break;
                    case REGISTER_ECX: reg_field = 1;break;
                    case REGISTER_EDX: reg_field = 2;break;
                    case REGISTER_EBX: reg_field = 3;break;
                    case REGISTER_ESP: reg_field = 4;break;
                    case REGISTER_EBP: reg_field = 5;break;
                    case REGISTER_ESI: reg_field = 6;break;
                    case REGISTER_EDI: reg_field = 7;break;
                    default: assert(0);break;
                }
            }
            else
            {
                fprintf(stderr, "Error w field\n");
                assert(0);
            }
        }
        else
        {
            fprint(stderr, "Error operation data size\n");
        }
    }
}

reg_field_t encode_reg_field(x86_64_register_t reg, int exist_w, w_field_t w_field, operation_data_size_t operation_data_size)
{
    return encode_reg_field_64_bit_mode(reg,exist_w,w_field,operation_data_size);
}