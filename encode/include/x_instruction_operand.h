#ifndef AMD64_X_INSTRUCTION_OPERAND_H
#define AMD64_X_INSTRUCTION_OPERAND_H
#include "encode/x_instruction.h"
x_instruction_t x_instruction_opcode(uint8_t opcode);
x_instruction_t x_instruction_operand_Eb(amd64_operand_t operand);
x_instruction_t x_instruction_operand_Gb(amd64_operand_t operand);
#endif