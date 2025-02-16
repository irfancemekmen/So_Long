/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:56 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 18:30:40 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

t_data	*data_init(char *map)
{
	t_data	*data;
	int		height;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_message("Error\nMalloc error");
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data);
		error_message("Error\nMalloc error");
	}
	height = full_map(map);
	data->map->map = map_build(map, height);
	if (!data->map->map)
		free_exit("Error\nMap not created", data, 0);
	data->cc = av_counter(data->map->map, 'C');
	if (data->cc == 0)
		free_exit("Error\nNo collectibles", data, 1);
	data->temp_c = data->cc;
	data->temp_e = 1;
	map_w_h(data);
	player_w_h(data);
	data->mc = 0;
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		error_message("Error\nInvalid number of arguments");
	av_control(av[1]);
	data = data_init(av[1]);
	virtual_map(data, 0, 0);
	init_mlx(data);
	render(data);
	mlx_key_hook(data->window, keyboard, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, put_mlx, data);
	mlx_loop(data->mlx);
}
