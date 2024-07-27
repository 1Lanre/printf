#include "main.h"

/**
 * print_string - Prints a string to stdout.
 * @string: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(char *string)
{
    int count = 0;
    
    for (int i = 0; string[i] != '\0'; i++)
    {
        count += _putchar(string[i]);
    }
    
    return count;
}

