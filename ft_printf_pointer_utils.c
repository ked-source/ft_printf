/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdiab <kdiab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:48:18 by kdiab             #+#    #+#             */
/*   Updated: 2026/02/01 22:44:56 by kdiab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_ul(unsigned long n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += print_hex_ul(n / 16);
	len += print_char(base[n % 16]);
	return (len);
}

int	print_pointer(void *ptr)
{
	unsigned long	addr;
	int				len;

	if (!ptr)
		return (print_string("(nil)"));
	addr = (unsigned long) ptr;
	len = 0;
	len += write(1, "0x", 2);
	len += print_hex_ul(addr);
	return (len);
}
