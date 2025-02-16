/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:37 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 18:35:10 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	check_accessible(int **vm, t_data *data, int pw, int ph)
{
	if (data->map->map[ph][pw] == 'C')
		data->temp_c--;
	if (data->map->map[ph][pw] == 'E')
		data->temp_e--;
	if (data->map->map[ph - 1][pw] != '1' && vm[ph - 1][pw] == 0)
	{
		vm[ph - 1][pw] = 1;
		check_accessible(vm, data, pw, ph - 1);
	}
	if (data->map->map[ph + 1][pw] != '1' && vm[ph + 1][pw] == 0)
	{
		vm[ph + 1][pw] = 1;
		check_accessible(vm, data, pw, ph + 1);
	}
	if (data->map->map[ph][pw - 1] != '1' && vm[ph][pw - 1] == 0)
	{
		vm[ph][pw - 1] = 1;
		check_accessible(vm, data, pw - 1, ph);
	}
	if (data->map->map[ph][pw + 1] != '1' && vm[ph][pw + 1] == 0)
	{
		vm[ph][pw + 1] = 1;
		check_accessible(vm, data, pw + 1, ph);
	}
}

void	virtual_map(t_data *data, int x, int y)
{
	int	**vm;

	vm = (int **)malloc(sizeof(int *) * (data->map->map_h + 1));
	if (!vm)
		free_exit("Malloc failed", data, 1);
	while (y < data->map->map_h)
	{
		vm[y] = (int *)malloc(sizeof(int) * (data->map->map_w + 1));
		if (!vm[y])
		{
			free_map((void **)vm);
			free_exit("Malloc failed", data, 1);
		}
		x = 0;
		while (x < data->map->map_w)
			vm[y][x++] = 0;
		y++;
	}
	vm[y] = NULL;
	check_accessible(vm, data, data->pw, data->ph);
	coin_acces(data);
	free_map((void **)vm);
}

void	coin_acces(t_data *data)
{
	if (data->temp_c != 0 && data->temp_e != 0)
		free_exit("Error\nPlayer can not move!", data, 1);
	if (data->temp_c != 0)
		free_exit("Error\nPlayer can not access the collectibles!", data, 1);
	if (data->temp_e != 0)
		free_exit("Error\nExit is not accessible!", data, 1);
}
