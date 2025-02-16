/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:51 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 18:12:56 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	full_map(char *map)
{
	int		fd;
	int		i;
	char	c;
	int		height;

	height = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 1;
	while (i > 0)
	{
		i = read(fd, &c, 1);
		if (i <= 0)
			break ;
		if (c == '\n')
			height++;
	}
	close(fd);
	return (height);
}

static int	map_creat_check(char **tmp)
{
	if (map_check_nl(tmp))
		return (0);
	tmp = delete_nl(tmp);
	if (map_checker(tmp) == 0)
		return (0);
	return (1);
}

char	**map_build(char *map, int height)
{
	char	**tmp;
	char	*line;
	int		i;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = (char **)malloc(sizeof(char *) * (height + 1));
	if (!tmp)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmp[i++] = line;
		line = get_next_line(fd);
	}
	tmp[i] = NULL;
	close(fd);
	if (map_creat_check(tmp) == 0)
		return (NULL);
	return (tmp);
}
