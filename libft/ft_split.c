/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:58:01 by iekmen            #+#    #+#             */
/*   Updated: 2024/10/30 03:35:01 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_cal_wordlen(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_cal_word(const char *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_all_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_cal_word(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i] = (char *)malloc(sizeof(char) *(ft_cal_wordlen(s, c) + 1));
			if (!str[i])
				return (ft_all_free (str));
			j = 0;
			while (*s && *s != c)
				str[i][j++] = *s++;
			str[i++][j] = '\0';
		}
	}
	str[i] = NULL;
	return (str);
}
