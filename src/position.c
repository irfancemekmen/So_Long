/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:53 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 16:51:54 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	map_w_h(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		i++;
	data->map->map_h = i;
	data->map->map_w = ft_strlen(data->map->map[0]);
}

void	player_w_h(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'P')
			{
				data->pw = j;
				data->ph = i;
				return ;
			}
			j++;
		}
		i++;
	}
	free_exit("Player not found\n", data, 1);
}

int	wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_char_check(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' && map[i] != 'E'
			&& map[i] != 'C')
			return (0);
		i++;
	}
	return (1);
}
