typedef enum
{
    MNEMONIC_ADC,
    MNEMONIC_CLC,
}mnemonic_t;

mnemonic_t lex_mnemonic(const char* mnemonic_string);