#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int line_number)
{
    stack_t *temp;
    (void)line_number;
    temp = *head;
    if (temp == NULL)
        return;
    while (temp)
    {
        fprintf(stdout, "%d\n", temp->n);
        temp = temp->next;
    }
}
