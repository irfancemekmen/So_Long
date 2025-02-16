/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:32:35 by iekmen            #+#    #+#             */
/*   Updated: 2024/10/29 23:01:32 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*copy;

	i = 0;
	length = ft_strlen(s);
	copy = (char *)malloc((length + 1) * sizeof(char));
	if (!copy)
		return (0);
	while (i < length)
	{
		copy[i] = s[i];
		i++;
	}
	copy[length] = '\0';
	return (copy);
}
