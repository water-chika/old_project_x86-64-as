#include "mnemonic.h"
mnemonic_t get_mnemonic(const char* mnemonic_string)
{
    if (strcmp(mnemonic_string, "ADC") == 0)
    {
        return MNEMONIC_ADC;
    }
    else if (strcmp(mnemonic_string, "CLC") == 0)
    {
        return MNEMONIC_CLC;
    }
}