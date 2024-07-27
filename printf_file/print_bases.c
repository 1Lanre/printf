#include "main.h"

/**
 * print_number_in_base - Prints a number in the specified base.
 * @num: The number to print.
 * @base: The base to convert the number to.
 * @uppercase: Flag to determine if the hexadecimal letters should be uppercase.
 * @prefix: The prefix to add (e.g., "0x" or "0X"), or NULL for no prefix.
 *
 * Return: Number of characters printed.
 */
static int print_number_in_base(unsigned int num, int base, int uppercase, const char *prefix)
{
    char *str = convert(num, base, uppercase);
    int count = 0;

    if (prefix && str[0] != '0')
        count += _puts(prefix);
    count += _puts(str);

    return count;
}

/**
 * print_hex - Prints a number in hexadecimal base (lowercase).
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (used for prefix).
 *
 * Return: Number of characters printed.
 */
int print_hex(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    (void)f;  // Unused parameter

    return print_number_in_base(num, 16, 1, f->hash ? "0x" : NULL);
}

/**
 * print_hex_big - Prints a number in hexadecimal base (uppercase).
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (used for prefix).
 *
 * Return: Number of characters printed.
 */
int print_hex_big(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    (void)f;  // Unused parameter

    return print_number_in_base(num, 16, 0, f->hash ? "0X" : NULL);
}

/**
 * print_binary - Prints a number in binary base.
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_binary(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    (void)f;  // Unused parameter

    return print_number_in_base(num, 2, 0, NULL);
}

/**
 * print_octal - Prints a number in octal base.
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (used for prefix).
 *
 * Return: Number of characters printed.
 */
int print_octal(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    (void)f;  // Unused parameter

    return print_number_in_base(num, 8, 0, f->hash ? "0" : NULL);
}

