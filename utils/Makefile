programs = get_register_code get_immediate_code get_operand_code get_instruction_code get_instruction_symbol \
	get_encoded_instruction simple_as
all : ${programs}

get_register_code: get_register_code.c libx86_64_as.a
	gcc -I../include -o get_register_code get_register_code.c libx86_64_as.a

get_immediate_code: get_immediate_code.c libx86_64_as.a
	gcc -I../include -o get_immediate_code get_immediate_code.c libx86_64_as.a

get_operand_code: get_operand_code.c libx86_64_as.a
	gcc -I../include -o get_operand_code get_operand_code.c libx86_64_as.a

get_instruction_code: get_instruction_code.c libx86_64_as.a
	gcc -I../include -o get_instruction_code get_instruction_code.c libx86_64_as.a

get_instruction_symbol: get_instruction_symbol.c libx86_64_as.a
	gcc -I../include -o get_instruction_symbol get_instruction_symbol.c libx86_64_as.a

get_encoded_instruction: get_encoded_instruction.c libx86_64_as.a
	gcc -I../include -o get_encoded_instruction get_encoded_instruction.c libx86_64_as.a

libx86_64_as.a : ../src/encoder.c ../src/instruction.c ../src/lexer.c ../src/mnemonic.c \
			../src/operand.c ../src/immediate.c ../src/register.c ../src/address_encoding.c
	gcc -c -I../include ../src/encoder.c ../src/instruction.c ../src/lexer.c ../src/mnemonic.c \
		../src/operand.c ../src/immediate.c ../src/register.c ../src/address_encoding.c
	ar r libx86_64_as.a encoder.o instruction.o lexer.o mnemonic.o operand.o \
		immediate.o register.o address_encoding.o
	
simple_as : simple_as.c libx86_64_as.a
	gcc -I../include -o simple_as simple_as.c libx86_64_as.a

loader : loader.c
	gcc -o loader loader.c

clean:
	rm -f ${programs}
	rm -f *.o
	rm -f libx86_64_as.a
