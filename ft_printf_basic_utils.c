/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdiab <kdiab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:48:18 by kdiab             #+#    #+#             */
/*   Updated: 2026/02/01 22:16:06 by kdiab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (print_string("(null)"));
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_percent(void)
{
	char	c;

	c = '%';
	write(1, &c, 1);
	return (1);
}
