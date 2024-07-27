#include "main.h"

/**
 * print_string - Prints a string, or "(null)" if the string is NULL.
 * @args: va_list arguments from _printf.
 * @flags: Pointer to the struct flags (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args, flags_t *flags)
{
    char *str = va_arg(args, char *);
    (void)flags;  // Unused parameter

    if (!str)
    {
        str = "(null)";
    }
    
    return _puts(str);
}

/**
 * print_char - Prints a single character.
 * @args: va_list arguments from _printf.
 * @flags: Pointer to the struct flags (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args, flags_t *flags)
{
    (void)flags;  // Unused parameter
    _putchar(va_arg(args, int));
    return 1;
}

