#ifndef ASSEMBLER_FRONTEND_H
#define ASSEMBLER_FRONTEND_H
#include "instruction.h"

exact_instruction_t convert_to_exact_instruction(const char* instruction_string);
#endif