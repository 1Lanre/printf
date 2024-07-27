#include "main.h"

/* Helper function to convert address to hexadecimal string */
static char *address_to_hex(unsigned long int address)
{
    return convert(address, 16, 1);  // Convert to hexadecimal with lowercase letters
}

/* Helper function to print the address */
static int print_address_helper(char *str)
{
    int count = 0;

    count += _puts("0x");
    count += _puts(str);

    return count;
}

/**
 * print_address - Prints the address of input in hexadecimal format.
 * @args: va_list arguments from _printf.
 * @flags: Pointer to the struct flags (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_address(va_list args, flags_t *flags)
{
    unsigned long int address = va_arg(args, unsigned long int);
    char *hex_str;
    int count = 0;

    (void)flags;  // Unused parameter

    if (!address)
    {
        return _puts("(nil)");
    }

    hex_str = address_to_hex(address);
    count += print_address_helper(hex_str);

    return count;
}

