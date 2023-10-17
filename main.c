/* Define the _POSIX_C_SOURCE macro to enable POSIX features*/
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Include other necessary headers and declarations*/

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    /* Check for the correct number of command-line arguments*/
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty bytecode file*/
    
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }


    while ((read = getline(&line, &len, file) != -1))
    {
        if (read > 0)
        {
            /* Check if the line is a comment*/
            if (line[0] == '#')
            {
                /* This line is a comment; skip it.*/
                continue;
            }

            /* Parse and execute the non-comment line as Monty bytecode*/
            /* Implement the Monty opcode execution logic here.*/
        }
    }

    /* Close the file and free allocated memory*/
    fclose(file);
    free(line);

    /* Continue with the rest of your Monty interpreter logic*/

    return (0);
}
