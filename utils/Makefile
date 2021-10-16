all: get_register_code get_immediate_code get_operand_code get_instruction_code get_instruction_symbol \
	get_encoded_instruction
get_register_code: get_register_code.c ../src/register.c ../include/register.h
	gcc -I../include -o get_register_code get_register_code.c ../src/register.c

get_immediate_code: get_immediate_code.c ../src/immediate.c ../include/immediate.h
	gcc -I../include -o get_immediate_code get_immediate_code.c ../src/immediate.c

get_operand_code: get_operand_code.c ../src/operand.c ../src/immediate.c ../src/register.c
	gcc -I../include -o get_operand_code get_operand_code.c ../src/operand.c ../src/immediate.c ../src/register.c

get_instruction_code: get_instruction_code.c ../src/lexer.c ../src/mnemonic.c ../src/operand.c ../src/immediate.c ../src/register.c
	gcc -I../include -o get_instruction_code get_instruction_code.c ../src/lexer.c ../src/mnemonic.c ../src/operand.c ../src/immediate.c ../src/register.c

get_instruction_symbol: get_instruction_symbol.c ../src/instruction.c ../src/lexer.c ../src/mnemonic.c ../src/operand.c ../src/immediate.c ../src/register.c
	gcc -I../include -o get_instruction_symbol get_instruction_symbol.c ../src/lexer.c ../src/mnemonic.c ../src/operand.c ../src/immediate.c ../src/register.c ../src/instruction.c

get_encoded_instruction: get_encoded_instruction.c ../src/encoder.c ../src/instruction.c ../src/lexer.c ../src/mnemonic.c \
		../src/operand.c ../src/immediate.c ../src/register.c ../src/address_encoding.c
	gcc -I../include -o get_encoded_instruction get_encoded_instruction.c ../src/encoder.c ../src/instruction.c \
		../src/lexer.c ../src/mnemonic.c ../src/operand.c ../src/immediate.c ../src/register.c ../src/address_encoding.c

clean:
	rm -f get_immediate_code get_register_code get_operand_code get_instruction_code \
		get_encoded_instruction
