#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Prints a string to stdout.
 * @str: Pointer to the string to print.
 *
 * Return: Number of characters written.
 */
int _puts(const char *str)
{
    int count = 0;

    while (str[count] != '\0')
    {
        if (_putchar(str[count]) == -1)
            return -1; // Return -1 if there's an error in writing.
        count++;
    }

    return count;
}

