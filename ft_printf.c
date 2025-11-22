int printf_string(char *s)
{
    int len;

    len = 0;
    if (!s)
        return (0);
    while (s[len])
    {
        write(1, &s[len], 1);
        len++;
    }
    return (len);
}

int printf_char(int c)
{
    write(1, &c, 1);
    return (1);
}


int handle_format_conversion(char conversion_type, va_list *args)
{
    if (conversion_type == 'c')
        return (printf_char(va_arg(*args, int)));
    else if (conversion_type == 's')
        return (printf_string(va_arg(*args, char *)));
    else if (conversion_type == 'p')
    {

    }
    else if (conversion_type == 'd')
    {

    }
    else if (conversion_type == 'i')
    {

    }
    else if (conversion_type == 'u')
    {

    }
    else if (conversion_type == 'x')
    {

    }
    else if (conversion_type == 'X')
    {

    }
    else if (conversion_type == '%')
    {

    }
}

int ft_printf(const char *to_print, ...)
{
    va_list args;
    int argument_index;
    int printed_chars;

    if (!to_print)
        return (0);
    argument_index = 0;
    printed_chars = 0;
    va_start(args, to_print);
    while (*to_print)
    {
        if (*to_print == '%')
        {
            printed_chars += handle_format_conversion(*(to_print + 1), &args);
            to_print = to_print + 2;
            argument_index++;
        }
        else
        {
            write (1, to_print, 1);
            to_print++;
            printed_chars++;
        }
    }
    return (printed_chars);
}    