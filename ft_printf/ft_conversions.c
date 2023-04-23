// HEADER PLS
#include "ft_printf.h"

// Maybe add errors for incorrect flags later?
//  e.g. '#' flag for char conversion.
char    *ft_conversion_char(char *sub_format, va_list specifier)
{
    size_t  len;

    len = 0;
    while (*sub_format && (*sub_format != '%'))
    {
        len++;
        sub_format++;
    }
}
