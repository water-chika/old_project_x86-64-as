#include <stdint.h>
typedef uint8_t byte_t;
typedef struct
{

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
