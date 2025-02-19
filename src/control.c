/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:41 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 16:51:42 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	av_control(char *map)
{
	int	len;
	int	fd;

	len = ft_strlen(map);
	if (ft_strnstr(map, ".ber", len) == 0)
		error_message("Error\nThe map is not .ber");
	else
	{
		fd = open(map, O_RDONLY);
		if (fd == -1)
			error_message("Error\nMap not found");
		close(fd);
	}
}

int	av_counter(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	map_check_nl(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (map[i][j] && map[i + 1] && map[i + 1][0] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**delete_nl(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (map[i][j] == '\n')
			map[i][j] = '\0';
		i++;
	}
	return (map);
}

int	map_checker(char **map)
{
	unsigned int	width;
	int				i;

	i = 0;
	width = 0;
	width = ft_strlen(map[0]);
	if ((wall(map[0]) == 0))
	{
		return (0);
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		else if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		else if (map_char_check(map[i]) == 0)
			return (0);
		i++;
	}
	if (av_counter(map, 'P') != 1 || av_counter(map, 'E') != 1)
		return (0);
	if ((wall(map[i - 1]) == 0))
		return (0);
	return (1);
}
