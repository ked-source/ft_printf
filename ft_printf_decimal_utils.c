/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdiab <kdiab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:48:18 by kdiab             #+#    #+#             */
/*   Updated: 2026/02/01 21:17:02 by kdiab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base10_number(int n)
{
	int	len;

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

int	print_unsigned_number(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += print_unsigned_number(n / 10);
	len += print_char((n % 10) + '0');
	return (len);
}

int	print_hex(unsigned int n, int is_upper)
{
	char	*base;
	int		len;

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
