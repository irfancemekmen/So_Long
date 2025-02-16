/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:51:22 by iekmen            #+#    #+#             */
/*   Updated: 2024/11/02 12:02:51 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_chrchacker(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	size_t	end;
	size_t	i;

	i = 0;
	while (s1 && ft_chrchacker(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end > 0 && s1[end - 1] && ft_chrchacker(set, s1[end - 1]))
		end--;
	ptr = (char *)malloc(sizeof(char) * (end + 1));
	if (!ptr)
		return (0);
	while (i < end)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[end] = '\0';
	return (ptr);
}
