/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:56:55 by iekmen            #+#    #+#             */
/*   Updated: 2024/11/02 12:21:07 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	rl;
	size_t	slen;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	rl = 0;
	while (needle[rl])
		rl++;
	slen = 0;
	while (haystack[slen])
		slen++;
	if (rl > n)
		return (0);
	while ((i <= n - rl) && (i < slen))
	{
		if ((haystack[i] == needle[0]) && (i + rl <= n)
			&& ft_strncmp(&haystack[i], needle, rl) == 0)
		{
			return ((char *) &haystack[i]);
		}
		i++;
	}
	return (0);
}
