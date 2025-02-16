/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:32:26 by iekmen            #+#    #+#             */
/*   Updated: 2024/11/29 12:33:37 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_check(char str)
{
	return (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p' || str == '\0');
}

static int	ft_format(va_list arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_string(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_hex(va_arg(arg, unsigned long long), 'p'));
	else if (format == 'd' || format == 'i')
		return (ft_int(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'X' || format == 'x')
		return (ft_hex(va_arg(arg, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == '\0')
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		value;
	va_list	arg;

	i = -1;
	len = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			value = ft_format(arg, format[++i]);
			if (value == -1)
				return (-1);
			len += value - 1;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		len++;
	}
	va_end(arg);
	return (len);
}
