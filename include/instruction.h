#include <stdint.h>
#include "register.h"
#include "operand.h"
#include "mnemonic.h"
#include "lexer.h"

typedef struct 
{
	mnemonic_t mnemonic;
	int operand_num;
	operand_class_t operand[4];
}instruction_item_t;

instruction_item_t get_instruction_item(lexed_instruction_t lexed_instruction);

int print_instruction_item(instruction_item_t instruction_item);