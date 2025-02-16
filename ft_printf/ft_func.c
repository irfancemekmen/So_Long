/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:32:01 by iekmen            #+#    #+#             */
/*   Updated: 2024/11/29 12:33:42 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_string(char *str)
{
	int	len;

	if (str == NULL)
	{
		if (ft_string("(null)") == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		if (ft_putchar(str[len++]) == -1)
			return (-1);
	}
	return (len);
}

int	ft_int(int number)
{
	int	len;
	int	ctrl;

	len = 0;
	if (number == -2147483648)
		return (ft_string("-2147483648"));
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		number = -number;
		len++;
	}
	if (number >= 10)
	{
		ctrl = ft_int(number / 10);
		if (ctrl == -1)
			return (-1);
		len += ctrl;
	}
	if (ft_putchar((number % 10 + '0')) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int number)
{
	int	len;

	len = 0;
	if (number > 9)
	{
		len = ft_unsigned(number / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar((number % 10 + '0')) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex(unsigned long long number, int mod)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (mod == 'p')
	{
		if (number == '\0')
		{
			if (ft_string("(nil)") == -1)
				return (-1);
			return (5);
		}
		if (ft_string("0x") == -1)
			return (-1);
		mod = 0;
		len += 2;
	}
	if (number >= 16)
		len += ft_hex(number / 16, mod);
	if (mod == 'X')
		hex = "0123456789ABCDEF";
	if (ft_putchar(hex[number % 16]) == -1)
		return (-1);
	return (len + 1);
}
