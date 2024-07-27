#include "main.h"

/**
 * print_int - Prints an integer.
 * @l: va_list of arguments from _printf.
 * @f: Pointer to the struct flags determining if a flag is passed to _printf.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list l, flags_t *f)
{
    int n = va_arg(l, int);
    int count = count_digits(n);

    if (f->space == 1 && f->plus == 0 && n >= 0)
        count += _putchar(' ');
    if (f->plus == 1 && n >= 0)
        count += _putchar('+');
    if (n < 0 || f->space == 1 || f->plus == 1)
        count++;  // Account for sign or space/plus

    print_number(n);
    return count;
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @l: va_list of arguments from _printf.
 * @f: Pointer to the struct flags determining if a flag is passed to _printf.
 *
 * Return: Number of characters printed.
 */
int print_unsigned(va_list l, flags_t *f)
{
    unsigned int u = va_arg(l, unsigned int);
    char *str = convert(u, 10, 0);

    (void)f;  // Unused parameter
    return _puts(str);
}

/**
 * print_number - Helper function that prints an integer.
 * @n: Integer to be printed.
 */
void print_number(int n)
{
    unsigned int num = (n < 0) ? -n : n;

    if (n < 0)
        _putchar('-');

    if (num / 10)
        print_number(num / 10);

    _putchar((num % 10) + '0');
}

/**
 * count_digits - Returns the number of digits in an integer.
 * @i: Integer to evaluate.
 *
 * Return: Number of digits.
 */
int count_digits(int i)
{
    unsigned int num = (i < 0) ? -i : i;
    int count = (num == 0) ? 1 : 0;

    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

