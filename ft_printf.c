/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdiab <kdiab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:48:25 by kdiab             #+#    #+#             */
/*   Updated: 2026/02/01 22:51:42 by kdiab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_conversion(char conversion_type, va_list *args)
{
	if (conversion_type == 'c')
		return (print_char(va_arg(*args, int)));
	else if (conversion_type == 's')
		return (print_string(va_arg(*args, char *)));
	else if (conversion_type == 'p')
		return (print_pointer(va_arg(*args, void *)));
	else if (conversion_type == 'd')
		return (print_base10_number(va_arg(*args, int)));
	else if (conversion_type == 'i')
		return (print_base10_number(va_arg(*args, int)));
	else if (conversion_type == 'u')
		return (print_unsigned_number(va_arg(*args, unsigned int)));
	else if (conversion_type == 'x')
		return (print_hex(va_arg(*args, unsigned int), 0));
	else if (conversion_type == 'X')
		return (print_hex(va_arg(*args, unsigned int), 1));
	else if (conversion_type == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *output, ...)
{
	va_list	args;
	int		total_printed_chars;

	total_printed_chars = 0;
	if (!output)
		return (total_printed_chars);
	va_start(args, output);
	while (*output)
	{
		if (*output == '%')
		{
			output++;
			if (*output)
				total_printed_chars += handle_format_conversion(*output, &args);
			output++;
		}
		else
		{
			write (1, output, 1);
			output++;
			total_printed_chars++;
		}
	}
	va_end(args);
	return (total_printed_chars);
}
