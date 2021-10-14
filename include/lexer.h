#ifndef LEXER_H
#define LEXER_H

#include "operand.h"
#include "mnemonic.h"
typedef struct
{
    mnemonic_t mnemonic;
    operand_set_t operand[4];
}lexed_instruction_t;


//The function lex get lexed instructions from a standalone instruction
// that do not contain information about other instruction.
//So the instruction do not contain label.
//Because a assembly instruction string may be map to multi low level binary instruction,
// returned result is a set;
lexed_instruction_t lex_instruction(const char* instruction);

#endif