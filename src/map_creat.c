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

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	map_height(char *map)
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

static void	map_creat_check(char **tmp, t_data *data)
{
	if (map_check_nl(tmp))
	{
		free_map((void **)tmp);
		free_exit("Error!", data, 0);
	}
	tmp = delete_nl(tmp);
	if (map_checker(tmp) == 0)
	{
		free_map((void **)tmp);
		free_exit("Error!\nMap not okay!", data, 0);
	}
}

char	**map_build(char *map, int height, t_data *data)
{
	char	**tmp;
	char	*line;
	int		i;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = (char **)malloc(sizeof(char *) * (height + 2));
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
	map_creat_check(tmp, data);
	return (tmp);
}
