#include "main.h"

/* Helper function to handle flags */
static void handle_flags(const char **p, flags_t *flags)
{
    while (get_flag(**p, flags))
        (*p)++;
}

/* Helper function to process a format specifier */
static int process_specifier(const char specifier, va_list arguments, flags_t *flags)
{
    int (*pfunc)(va_list, flags_t *);
    
    pfunc = get_print(specifier);
    return (pfunc) ? pfunc(arguments, flags) : _printf("%%%c", specifier);
}

/* Main printf function */
int _printf(const char *format, ...)
{
    int count = 0;
    const char *p;
    va_list arguments;
    flags_t flags = {0, 0, 0};

    va_start(arguments, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);

    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == '%')
            {
                count += _putchar('%');
                continue;
            }

            handle_flags(&p, &flags);
            count += process_specifier(*p, arguments, &flags);
        }
        else
        {
            count += _putchar(*p);
        }
    }

    _putchar(-1);
    va_end(arguments);
    return (count);
}

