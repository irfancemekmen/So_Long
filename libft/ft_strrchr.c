/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:45:59 by iekmen            #+#    #+#             */
/*   Updated: 2024/11/02 12:02:57 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	a;

	a = (char) c;
	last = 0;
	while (*s)
	{
		if (*s == (char)a)
			last = (char *) s;
		s++;
	}
	if (a == '\0')
		return ((char *) s);
	return (last);
}
