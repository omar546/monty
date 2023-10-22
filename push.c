#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int line_number)
{

    int new_number, index = 0, is_char = 0;

    if (file_model.arg)
    {
        if (file_model.arg[0] == '-')
            index++;
        for (; file_model.arg[index] != '\0'; index++)
        {
            if (file_model.arg[index] > 57 || file_model.arg[index] < 48)
                is_char = 1;
        }
        if (is_char == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(file_model.file);
            free(file_model.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(file_model.file);
        free(file_model.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    new_number = atoi(file_model.arg);
    push_node(head, new_number);
}