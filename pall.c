#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * Return: no return
 */
void f_pall(stack_t **head)
{
    stack_t *temp;
    temp = *head;
    if (temp == NULL)
        return;
    while (temp)
    {
        fprintf(stdout,"%d\n", temp->n);
        temp = temp->next;
    }
}
