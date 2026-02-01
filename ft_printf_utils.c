#include "ft_printf.h"

int print_string(char *s)
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

int print_char(int c)
{
    write(1, &c, 1);
    return (1);
}

int print_percent()
{
    char c = '%';
    write(1, &c, 1);
    return (1);
}


int print_base10_number(int n)
{
    int len;

    len = 0;
    if (n == INT_MIN)
        return (print_string("-2147483648"));
    if (n < 0)
    {
        len += print_char('-');
        n *= -1;
    }
    if (n > 9)
        len += print_base10_number(n / 10);
    len += print_char((n % 10) + '0');
    return (len);
}


int print_unsigned_number(unsigned int n)
{
    int len = 0;

    if (n > 9)
        len += print_unsigned_number(n / 10);

    len += print_char((n % 10) + '0');
    return len;
}

int print_hex(unsigned int n, int is_upper)
{
    char    *base;
    int     len;

    len = 0;
    if (is_upper)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if (n >= 16)
        len += print_hex(n / 16, is_upper);
    len += print_char(base[n % 16]);
    return (len);
}

int print_hex_ul(unsigned long n, int is_upper)
{
    char    *base;
    int     len;

    len = 0;
    if (is_upper)
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";
    if (n >= 16)
        len += print_hex_ul(n / 16, is_upper);
    len += print_char(base[n % 16]);
    return (len);
}

int print_pointer(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    int len = 0;

    len += write(1, "0x", 2);
    if (addr == 0)
        len += print_char('0');
    else
        len += print_hex_ul(addr);

    return len;
}