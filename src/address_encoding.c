#include "address_encoding.h"
#include <assert.h>



address_encoding_t encode_address(operand_t operand)
{
    address_encoding_t address_encoding = {};
    if (operand.type == OPERAND_REGISTER)
    {
        address_encoding.mod = 3;//0b11 == 3;
        uint8_t r_m = 0;
        switch (operand.reg)
        {
            case REGISTER_EAX:case REGISTER_AX:case REGISTER_AL:
                r_m=0;break;
            case REGISTER_ECX:case REGISTER_CX:case REGISTER_CL:
                r_m=1;break;
            case REGISTER_EDX:case REGISTER_DX:case REGISTER_DL:
                r_m=2;break;
            case REGISTER_EBX:case REGISTER_BX:case REGISTER_BL:
                r_m=3;break;
            case REGISTER_ESP:case REGISTER_SP:case REGISTER_AH:
                r_m=4;break;
            case REGISTER_EBP:case REGISTER_BP:case REGISTER_CH:
                r_m=5;break;
            case REGISTER_ESI:case REGISTER_SI:case REGISTER_DH:
                r_m=6;break;
            case REGISTER_EDI:case REGISTER_DI:case REGISTER_BH:
                r_m=7;break;
            case REGISTER_SPL:r_m=4;address_encoding.exist_rex = 1;break;
            case REGISTER_BPL:r_m=5;address_encoding.exist_rex = 1;break;
            case REGISTER_SIL:r_m=6;address_encoding.exist_rex = 1;break;
            case REGISTER_DIL:r_m=7;address_encoding.exist_rex = 1;break;
            default:assert(0);break;
        }
        address_encoding.r_m = r_m;
        address_encoding.exist_sib = 0; 
    }
    else
    {
        assert(0);
    }

    return address_encoding;
}