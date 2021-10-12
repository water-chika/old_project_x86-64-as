#include <stdint.h>
typedef uint8_t byte_t;
typedef struct
{
	byte_t code[15];
	int code_size; //code for a instruction is made of sevaral components.

	//some components is optional, so it's size maybe zero.
	//code_size should equal to sum of these components' size.
	int legacy_prefixes_size;
	int rex_prefix_size;
	int opcode_size;
	int mod_r_m_size;
	int sib_size;
	int displacement_size;
	int immediate_size;
} instruction_t;

#define instruction_assert(instruction)            \
	assert(instruction.code_size <= 15 &&          \
		   instruction.code_size ==                \
			   instruction.legacy_prefixes_size +  \
				   instruction.rex_prefix_size +   \
				   instruction.opcode_size +       \
				   instruction.mod_r_m_size +      \
				   instruction.sib_size +          \
				   instruction.displacement_size + \
				   instruction.immediate_size);
