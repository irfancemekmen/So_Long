/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:23:24 by iekmen            #+#    #+#             */
/*   Updated: 2024/10/29 23:06:13 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (n <= d_len)
		return (n + s_len);
	while (src[i] && d_len + i < n - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest [d_len + i] = '\0';
	return (d_len + s_len);
}
