#ifndef MNEMONIC_H
#define MNEMONIC_H

typedef enum
{
    MNEMONIC_ADC,
    MNEMONIC_CLC,
}mnemonic_t;

mnemonic_t lex_mnemonic(const char* mnemonic_string);

int print_mnemonic(mnemonic_t mnemonic);

#endif