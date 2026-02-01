# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
# include <limits.h>

int        ft_printf(const char *output, ...);
int        handle_format_conversion(char conversion_type, va_list *args);
int        print_string(char *s);
int        print_char(int c);
int        print_percent();
int        print_base10_number(int n);
int        print_unsigned_number(unsigned int n);
int        print_hex(unsigned long n, int is_upper);
int        print_pointer(void *ptr);
int        print_hex_ul(unsigned long n, int is_upper);

# endif