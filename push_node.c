#include "monty.h"
/**
 * push_node - add node to the head stack
 * @head: head of the stack
 * @new_number: new_value
 * Return: no return
 */
void push_node(stack_t **head, int new_number)
{

stack_t *new_node, *current;

current = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "stack memmory allocation error\n");
exit(0);
}
if (current)
current->prev = new_node;
new_node->next = *head;
new_node->prev = NULL;
new_node->n = new_number;
*head = new_node;
}
