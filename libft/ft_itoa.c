/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:07:47 by iekmen            #+#    #+#             */
/*   Updated: 2024/10/30 03:33:07 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_cal_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	long	x;

	i = ft_cal_digit(num);
	x = num;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		x = -x;
		str[0] = '-';
	}
	while (x)
	{
		str[--i] = (x % 10) + '0';
		x /= 10;
	}
	return (str);
}
