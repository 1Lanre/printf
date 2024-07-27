#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer to stdout.
 * @value: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int value)
{
    int count = 0;
    
    /* Base case: if value has more than one digit, print recursively */
    if (value / 10 > 0)
        count += print_unsigned(value / 10);
    
    /* Print the last digit */
    count += _putchar(value % 10 + '0');
    
    return count;
}

