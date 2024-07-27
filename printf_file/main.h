#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - Contains flags to be used in formatting.
 * @plus: Flag for the '+' character.
 * @space: Flag for the ' ' character.
 * @hash: Flag for the '#' character.
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/**
 * struct printHandler - Maps format specifiers to print functions.
 * @specifier: Format specifier character.
 * @function: Pointer to the corresponding print function.
 */
typedef struct printHandler
{
    char specifier;
    int (*function)(va_list ap, flags_t *f);
} printHandler_t;

/* Print functions for various data types */
int print_int(va_list args, flags_t *flags);
int print_unsigned(va_list args, flags_t *flags);
int print_string(va_list args, flags_t *flags);
int print_char(va_list args, flags_t *flags);
int print_hex(va_list args, flags_t *flags);
int print_hex_big(va_list args, flags_t *flags);
int print_binary(va_list args, flags_t *flags);
int print_octal(va_list args, flags_t *flags);

/* Functions for custom formats */
int print_rot13(va_list args, flags_t *flags);
int print_rev(va_list args, flags_t *flags);
int print_bigS(va_list args, flags_t *flags);
int print_address(va_list args, flags_t *flags);
int print_percent(va_list args, flags_t *flags);

/* Utility functions */
int _putchar(char c);
int _puts(char *str);

/* Converter function */
char *convert(unsigned long int num, int base, int lowercase);

/* Main printf function */
int _printf(const char *format, ...);

/* Helper functions for format specifiers and flags */
int (*get_print(char specifier))(va_list, flags_t *);
int get_flag(char flag_char, flags_t *flags);

#endif /* MAIN_H */

