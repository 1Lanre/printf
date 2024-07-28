#include "main.h"

/* Define a type for function pointers */
typedef int (*print_func_t)(va_list, flags_t *);

/* Struct to map specifiers to print functions */
typedef struct {
    char specifier;
    print_func_t function;
} print_map_t;

/* Array of function mappings */
static const print_map_t print_map[] = {
    {'i', print_int},
    {'s', print_string},
    {'c', print_char},
    {'d', print_int},
    {'u', print_unsigned},
    {'x', print_hex},
    {'X', print_hex_big},
    {'b', print_binary},
    {'o', print_octal},
    {'R', print_rot13},
    {'r', print_rev},
    {'S', print_bigS},
    {'p', print_address},
    {'%', print_percent}
};

/**
 * get_print - Selects the appropriate printing function based on the conversion specifier.
 * @specifier: The character that represents the conversion specifier.
 *
 * Return: A pointer to the corresponding print function, or NULL if not found.
 */
print_func_t get_print(char specifier)
{
    size_t num_specs = sizeof(print_map) / sizeof(print_map[0]);

    for (size_t i = 0; i < num_specs; i++)
    {
        if (print_map[i].specifier == specifier)
        {
            return print_map[i].function;
        }
    }
    return NULL;
}

