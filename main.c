#include "monty.h"

file_model_t file_model = {NULL, NULL, NULL};

int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    file_model.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line >= 1)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        file_model.content = content;
        line_number++;
        if (read_line > 0)
            execute(content, &stack, line_number, file);
        free(content);
    }
    
    free_stack(stack);
    fclose(file);
    return (0);
}