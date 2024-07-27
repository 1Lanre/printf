#include "main.h"

/**
 * print_binary - Prints a decimal number in binary format.
 * @number: The decimal number to convert and print in binary.
 *
 * Return: The number of characters printed.
 */
int print_binary(int number)
{
    int binary[32];  // Array to store binary digits
    int i = 0, count = 0;

    if (number == 0)
    {
        count += _putchar('0');
        return count;
    }

    // Convert decimal to binary and store in array
    while (number > 0)
    {
        binary[i++] = number % 2;
        number /= 2;
    }

    // Print binary digits in reverse order
    for (i = i - 1; i >= 0; i--)
    {
        count += _putchar(binary[i] + '0');
    }

    return count;
}

