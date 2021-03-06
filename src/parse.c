#include <stdio.h> // printf

void parse(char *line, char **argv)
{
    // While not the end of line
    while (*line != '\0')
    {
        printf("Top of while loop\n");
        
        // While there are spaces, tabs or new lines replace with null
        printf("Line before nested while loop 1: %s\n", line);
        while (*line == ' ' || *line == '\t' || *line == '\n') 
        {
            printf("Replace space, tab, or new line: %c\n", *line);
            *line++ = '\0';     
        }
        printf("Line after nested while loop 1: %s\n", line);
        
        // save the position of argument
        *argv++ = line;

        // while not null, space, tab, or new line
        while (*line != '\0' && *line != ' ' &&
                *line != '\t' && *line != '\n') 
        {
            // If backslash skip a character (allows user to have spaces in filenames)
            if (*line == '\\') 
            {
                printf("Skip backslash: %c\n", *line);
                printf("Ignoring next character: %c\n", *(line+1));
                //Rotation String Left and remove the backslash
                char *c = line;
                while (*c != '\0') 
                {
                    *c = *(c+1);
                    c++;
                }
                line++;
            }
            // Otherwise skip through until end of argument 
            else 
            {
                printf("Skip: %c\n", *line);
                line++;
            }
        }
    }
    // Null terminate the argument list
    *argv = (char *) '\0';
}