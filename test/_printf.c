#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
static void flush_buffer(char buffer[], int *buff_ind);
static int process_format(const char *format, int *i, va_list list, char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
    int i = 0, printed_chars = 0;
    va_list list;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;

    if (!format)
        return (-1);

    va_start(list, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind >= BUFF_SIZE)
                flush_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            flush_buffer(buffer, &buff_ind);
            if (process_format(format, &i, list, buffer, &buff_ind) == -1)
            {
                va_end(list);
                return (-1);
            }
            printed_chars += buff_ind;
        }
        i++;
    }

    flush_buffer(buffer, &buff_ind);
    va_end(list);

    return printed_chars;
}

/**
 * flush_buffer - Flushes the buffer to the output
 * @buffer: Array of chars
 * @buff_ind: Index indicating the number of valid characters in buffer
 */
static void flush_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

/**
 * process_format - Processes the format specifiers
 * @format: Format string
 * @i: Index of the current character in format
 * @list: Argument list
 * @buffer: Output buffer
 * @buff_ind: Buffer index
 * Return: Number of characters processed, or -1 on error
 */
static int process_format(const char *format, int *i, va_list list, char buffer[], int *buff_ind)
{
    int flags, width, precision, size;
    int printed;

    flags = get_flags(format, i);
    width = get_width(format, i, list);
    precision = get_precision(format, i, list);
    size = get_size(format, i);
    (*i)++;

    printed = handle_print(format, i, list, buffer, flags, width, precision, size);

    return printed;
}

