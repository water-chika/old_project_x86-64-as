#include "address_encoding.h"
#include <assert.h>



address_encoding_t encode_address(operand_t operand)
{
    address_encoding_t address_encoding = {};
    if (operand.type == OPERAND_TYPE_REGISTER)
    {
        if (belong_to_register_class(operand.reg, REGISTER_CLASS_R64))
        {
            address_encoding.exist_rex = 1;
            address_encoding.rex_w = 1;
        }
        if (belong_to_register_class(operand.reg, REGISTER_CLASS_R16))
        {
            address_encoding.exist_operand_size_prefix = 1;
        }
        address_encoding.mod = 3;//0b11 == 3;
        uint8_t r_m = 0;
        switch (operand.reg)
        {
            case REGISTER_RAX:case REGISTER_EAX:case REGISTER_AX:case REGISTER_AL:
                r_m=0;break;
            case REGISTER_RCX:case REGISTER_ECX:case REGISTER_CX:case REGISTER_CL:
                r_m=1;break;
            case REGISTER_RDX:case REGISTER_EDX:case REGISTER_DX:case REGISTER_DL:
                r_m=2;break;
            case REGISTER_RBX:case REGISTER_EBX:case REGISTER_BX:case REGISTER_BL:
                r_m=3;break;
            case REGISTER_RSP:case REGISTER_ESP:case REGISTER_SP:case REGISTER_AH:
                r_m=4;break;
            case REGISTER_RBP:case REGISTER_EBP:case REGISTER_BP:case REGISTER_CH:
                r_m=5;break;
            case REGISTER_RSI:case REGISTER_ESI:case REGISTER_SI:case REGISTER_DH:
                r_m=6;break;
            case REGISTER_RDI:case REGISTER_EDI:case REGISTER_DI:case REGISTER_BH:
                r_m=7;break;
            case REGISTER_SPL:r_m=4;address_encoding.exist_rex = 1;break;
            case REGISTER_BPL:r_m=5;address_encoding.exist_rex = 1;break;
            case REGISTER_SIL:r_m=6;address_encoding.exist_rex = 1;break;
            case REGISTER_DIL:r_m=7;address_encoding.exist_rex = 1;break;

            case REGISTER_R8B:case REGISTER_R8W:case REGISTER_R8D:case REGISTER_R8:
                r_m = 0;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R9B:case REGISTER_R9W:case REGISTER_R9D:case REGISTER_R9:
                r_m = 1;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R10B:case REGISTER_R10W:case REGISTER_R10D:case REGISTER_R10:
                r_m = 2;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R11B:case REGISTER_R11W:case REGISTER_R11D:case REGISTER_R11:
                r_m = 3;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R12B:case REGISTER_R12W:case REGISTER_R12D:case REGISTER_R12:
                r_m = 4;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R13B:case REGISTER_R13W:case REGISTER_R13D:case REGISTER_R13:
                r_m = 5;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R14B:case REGISTER_R14W:case REGISTER_R14D:case REGISTER_R14:
                r_m = 6;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            case REGISTER_R15B:case REGISTER_R15W:case REGISTER_R15D:case REGISTER_R15:
                r_m = 7;address_encoding.rex_b = 1;address_encoding.exist_rex = 1;break;
            default:assert(0);break;
        }
        address_encoding.r_m = r_m;
        address_encoding.exist_sib = 0; 
    }
    else if (operand.type == OPERAND_TYPE_MEMORY)
    {
        if (operand.mem.address_type == MEMORY_ADDRESS_INSTRUCTION_RELATIVE)
        {
            address_encoding.mod = 0;
            address_encoding.r_m=0b101;
            address_encoding.exist_disp = 1;
            address_encoding.disp.byte_num = 4;
            address_encoding.disp.disp = operand.mem.instruction_relative_address;
        }
        else
        {
            assert(0);
        }
    }
    else
    {
        assert(0);
    }

    return address_encoding;
}