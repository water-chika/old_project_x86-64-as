#ifndef MNEMONIC_H
#define MNEMONIC_H

typedef enum
{
    MNEMONIC_ADC,
    MNEMONIC_ADD,
    MNEMONIC_CLC,
    MNEMONIC_RET,
    MNEMONIC_LEA,
    MNEMONIC_MOV,
    MNEMONIC_SYSCALL,
}mnemonic_t;

mnemonic_t lex_mnemonic(const char* mnemonic_string);

int print_mnemonic(mnemonic_t mnemonic);

#endif