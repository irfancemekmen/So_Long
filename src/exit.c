/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:43 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 18:31:07 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

int	mlx_exit(t_data *data, char *str)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->bground)
		mlx_destroy_image(data->mlx, data->bground);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (free_exit(str, data, 1), 1);
}

void	error_message(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	free_exit(char *str, t_data *data, int flag)
{
	if (flag == 1)
		free_map((void **)data->map->map);
	free(data->map);
	free(data);
	ft_printf("%s\n", str);
	exit(0);
}

void	free_map(void **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	close_window(t_data *data)
{
	mlx_exit(data, "Exit");
	return (0);
}
