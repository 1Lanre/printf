#include "main.h"

/**
 * convert_to_decimal - Converts a number from base 8 or 16 to base 10.
 * @number: The number to convert.
 * @base: The base of the number (either 8 or 16).
 *
 * Return: The decimal representation of the number.
 */
long long convert_to_decimal(int number, int base)
{
    long long decimal_number = 0;
    int i = 0;

    while (number != 0)
    {
        decimal_number += (number % 10) * power(base, i);
        ++i;
        number /= 10;
    }

    return decimal_number;
}

/**
 * power - Computes the power of a number.
 * @base: The base.
 * @exp: The exponent.
 *
 * Return: base raised to the power of exp.
 */
int power(int base, int exp)
{
    int result = 1;
    
    while (exp > 0)
    {
        result *= base;
        exp--;
    }
    
    return result;
}

