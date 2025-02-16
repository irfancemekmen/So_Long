/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:48 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 16:51:49 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	init_mlx(t_data *data)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->map->map_w * PIXEL,
			data->map->map_h * PIXEL, "so_long");
	data->player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &y,
			&x);
	data->coin = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &y, &x);
	data->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &y, &x);
	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &y, &x);
	data->bground = mlx_xpm_file_to_image(data->mlx, "textures/bground.xpm", &y,
			&x);
	if (!data->mlx || !data->window || !data->player || !data->coin
		|| !data->exit || !data->wall || !data->bground)
		mlx_exit(data, "Error\nTextures not loaded!");
}

void	render(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->map_h)
	{
		x = -1;
		while (++x < data->map->map_w)
		{
			if (data->map->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall, x
					* PIXEL, y * PIXEL);
			else
				mlx_put_image_to_window(data->mlx, data->window, data->bground,
					x * PIXEL, y * PIXEL);
			if (data->map->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit, x
					* PIXEL, y * PIXEL);
			else if (data->map->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->coin, x
					* PIXEL, y * PIXEL);
		}
	}
}

int	keyboard(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_exit(data, "Exit");
	else if (keycode == W && data->map->map[data->ph - 1][data->pw] != '1')
		data->ph--;
	else if (keycode == A && data->map->map[data->ph][data->pw - 1] != '1')
		data->pw--;
	else if (keycode == S && data->map->map[data->ph + 1][data->pw] != '1')
		data->ph++;
	else if (keycode == D && data->map->map[data->ph][data->pw + 1] != '1')
		data->pw++;
	else
		return (0);
	ft_printf("Moves: %d\n", ++data->mc);
	if (data->map->map[data->ph][data->pw] == 'C')
	{
		data->cc--;
		data->map->map[data->ph][data->pw] = '0';
	}
	if (data->map->map[data->ph][data->pw] == 'E' && data->cc == 0)
		mlx_exit(data, "Win!");
	return (0);
}

int	put_mlx(t_data *data)
{
	render(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player, data->pw
		* PIXEL, data->ph * PIXEL);
	return (0);
}
