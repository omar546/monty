#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int line_number)
{
stack_t *temp;
int len = 0, value;

temp = *head;
while (temp)
{
temp = temp->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
fclose(file_model.file);
free(file_model.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = *head;
value = temp->n;
temp->n = temp->next->n;
temp->next->n = value;
}
