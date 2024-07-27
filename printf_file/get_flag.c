#include "main.h"

/**
 * set_flag - Updates the flags structure based on the given flag character.
 * @flag_char: The character representing the flag to be set.
 * @flags: Pointer to the flags structure to be updated.
 *
 * Return: 1 if a flag was set, 0 otherwise.
 */
static int set_flag(char flag_char, flags_t *flags)
{
    switch (flag_char)
    {
        case '+':
            flags->plus = 1;
            return 1;
        case ' ':
            flags->space = 1;
            return 1;
        case '#':
            flags->hash = 1;
            return 1;
        default:
            return 0;
    }
}

/**
 * get_flag - Processes a flag character and updates the flags structure.
 * @flag_char: The character that may represent a flag.
 * @flags: Pointer to the structure that holds the flag states.
 *
 * Return: 1 if a flag was set, 0 otherwise.
 */
int get_flag(char flag_char, flags_t *flags)
{
    return set_flag(flag_char, flags);
}

