int ft_putstr_fd(char *s)
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
}


int handle_format_conversion(char conversion_type, va_list *args)
{
    if (*(to_print + 1) == 'c')
    {

    }
    else if (*(to_print + 1) == 's')
    {

    }
    else if (*(to_print + 1) == 'p')
    {

    }
    else if (*(to_print + 1) == 'd')
    {

    }
    else if (*(to_print + 1) == 'i')
    {

    }
    else if (*(to_print + 1) == 'u')
    {

    }
    else if (*(to_print + 1) == 'x')
    {

    }
    else if (*(to_print + 1) == 'X')
    {

    }
    else if (*(to_print + 1) == '%')
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
    va_start(args, to_print);
    while (*to_print)
    {
        if (*to_print == '%')
        {
            
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