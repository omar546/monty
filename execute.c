#include "monty.h"

int execute(char *content, stack_t **stack, unsigned int line_number,
FILE *file)
{

instruction_t insts[] = {
{"push", f_push},
{"pall", f_pall},
{"pint", f_pint},
{"pop", f_pop},
{"swap", f_swap},
{"add", f_add},
{"nop", f_nop},
};
char *opcode;
unsigned int index = 0;

opcode = strtok(content, " \n\t");

if (opcode && opcode[0] == '#')
return (0);
file_model.arg = strtok(NULL, " \n\t");

while (insts[index].opcode && opcode)
{
if (strcmp(opcode, insts[index].opcode) == 0)
{
insts[index].f(stack, line_number);
return (0);
}
index++;
}
if (opcode && insts[index].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
