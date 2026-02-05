/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdiab <kdiab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:48:35 by kdiab             #+#    #+#             */
/*   Updated: 2026/02/01 21:57:33 by kdiab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *output, ...);
int	handle_format_conversion(char conversion_type, va_list *args);
int	print_string(char *s);
int	print_char(int c);
int	print_percent(void);
int	print_base10_number(int n);
int	print_unsigned_number(unsigned int n);
int	print_hex(unsigned int n, int is_upper);
int	print_pointer(void *ptr);
int	print_hex_ul(unsigned long n);
#endif
