#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int line_number)
{
    stack_t *temp;
    int len = 0, added_value;

    temp = *head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(file_model.file);
        free(file_model.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    temp = *head;
    added_value = temp->n + temp->next->n;
    temp->next->n = added_value;
    *head = temp->next;
    free(temp);
}