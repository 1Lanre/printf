#include "main.h"
#include <stdlib.h>  // for malloc and free

/**
 * convert - Converts a number to a string representation in a given base.
 * @num: The input number to convert.
 * @base: The base to use for conversion (e.g., 10 for decimal, 16 for hexadecimal).
 * @lowercase: Flag to determine if hexadecimal characters should be lowercase.
 *
 * Return: A dynamically allocated string representing the number in the specified base.
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    char *rep;
    char buffer[50];
    char *ptr;
    char *result;
    int length = 0;
    
    rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";

    // Initialize the end of the buffer
    ptr = &buffer[49];
    *ptr = '\0';

    // Convert the number to the specified base
    do {
        *--ptr = rep[num % base];
        num /= base;
        length++;
    } while (num != 0);

    // Allocate memory for the result
    result = (char *)malloc(length + 1);
    if (result == NULL)
    {
        return NULL;  // Allocation failed
    }

    // Copy the result from the buffer to the allocated memory
    for (int i = 0; i < length; i++)
    {
        result[i] = ptr[i];
    }
    result[length] = '\0';

    return result;
}

