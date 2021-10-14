all: get_register_code get_immediate_code
get_register_code: get_register_code.c ../register.c ../include/register.h
	gcc -I../include -o get_register_code get_register_code.c ../register.c

get_immediate_code: get_immediate_code.c ../src/immediate.c ../include/immediate.h
	gcc -I../include -o get_immediate_code get_immediate_code.c ../src/immediate.c
