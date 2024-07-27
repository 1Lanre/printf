#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format string.
 * @format: Format string containing the characters and specifiers.
 *
 * Return: Length of the formatted output string.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            count += _putchar(format[i]);
            i++;
        }
        else
        {
            i++;
            count += handle_specifier(format[i], args);
            i++;
        }
    }

    va_end(args);
    return (count);
}

/**
 * handle_specifier - Processes format specifiers and prints accordingly.
 * @specifier: The format specifier character.
 * @args: The va_list containing the arguments.
 *
 * Return: Number of characters printed.
 */
int handle_specifier(char specifier, va_list args)
{
    switch (specifier)
    {
        case 'c':
            return _putchar(va_arg(args, int));
        case 's':
            return print_string(va_arg(args, char *));
        case '%':
            return _putchar('%');
        case 'd':
        case 'i':
            return print_decimal(va_arg(args, int));
        case 'b':
            return print_binary(va_arg(args, int));
        case 'u':
            return print_unsigned(va_arg(args, unsigned int));
        default:
            return _putchar('?'); // Print '?' for unsupported specifiers
    }
}

