#include "main.h"

/**
 * print_non_printable - Prints non-printable characters in the format \xXX.
 * @c: The character to print.
 *
 * Return: Number of characters printed.
 */
static int print_non_printable(char c)
{
    char *hex_str = convert(c, 16, 0);
    int count = 0;

    if (c < 16)
        count += _putchar('0');
    count += _puts(hex_str);

    return count;
}

/**
 * print_bigS - Prints a string with non-printable characters in \xXX format.
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_bigS(va_list l, flags_t *f)
{
    char *s = va_arg(l, char *);
    int count = 0;
    int i;

    (void)f;  // Unused parameter

    if (!s)
        return _puts("(null)");

    for (i = 0; s[i]; i++)
    {
        if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
        {
            _puts("\\x");
            count += 2;  // For "\x"
            count += print_non_printable(s[i]);
        }
        else
        {
            count += _putchar(s[i]);
        }
    }

    return count;
}

/**
 * print_rev - Prints a string in reverse.
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (unused in this function).
 *
 * Return: Length of the printed string.
 */
int print_rev(va_list l, flags_t *f)
{
    char *s = va_arg(l, char *);
    int length = 0;
    int i;

    (void)f;  // Unused parameter

    if (!s)
        s = "(null)";

    // Find the length of the string
    while (s[length])
        length++;

    // Print the string in reverse
    for (i = length - 1; i >= 0; i--)
        _putchar(s[i]);

    return length;
}

/**
 * print_rot13 - Prints a string encoded with ROT13.
 * @l: va_list arguments from _printf.
 * @f: Pointer to the struct flags (unused in this function).
 *
 * Return: Length of the printed string.
 */
int print_rot13(va_list l, flags_t *f)
{
    char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
    char *s = va_arg(l, char *);
    int i, j;
    int count = 0;

    (void)f;  // Unused parameter

    for (j = 0; s[j]; j++)
    {
        if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
        {
            _putchar(s[j]);
            count++;
        }
        else
        {
            for (i = 0; i < 52; i++)
            {
                if (s[j] == rot13[i])
                {
                    _putchar(ROT13[i]);
                    count++;
                    break;
                }
            }
        }
    }

    return count;
}

/**
 * print_percent - Prints a percent symbol.
 * @l: va_list arguments from _printf (unused in this function).
 * @f: Pointer to the struct flags (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_percent(va_list l, flags_t *f)
{
    (void)l;  // Unused parameter
    (void)f;  // Unused parameter

    return _putchar('%');
}

