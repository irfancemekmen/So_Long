/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iekmen <iekmen@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:51:59 by iekmen            #+#    #+#             */
/*   Updated: 2025/02/16 17:04:42 by iekmen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 48

typedef struct s_map
{
	char	**map;
	int		map_w;
	int		map_h;
}			t_map;

typedef struct s_data
{
	int		pw;
	int		ph;
	int		cc;
	int		mc;
	int		temp_c;
	int		temp_e;
	void	*mlx;
	void	*window;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*bground;
	t_map	*map;
}			t_data;

void		check_accessible(int **vm, t_data *data, int pw, int ph);
void		virtual_map(t_data *data, int x, int y);
void		coin_acces(t_data *data);

void		av_control(char *map);
int			av_counter(char **map, char c);
int			map_check_nl(char **map);
char		**delete_nl(char **map);
int			map_checker(char **map);

int			mlx_exit(t_data *data, char *str);
void		error_message(char *str);
void		free_exit(char *str, t_data *data, int flag);
void		free_map(void **map);
int			close_window(t_data *data);

char		*get_next_line(int fd);

void		init_mlx(t_data *data);
void		render(t_data *data);
int			keyboard(int keycode, t_data *data);
int			put_mlx(t_data *data);

int			map_height(char *map);
char		**map_build(char *map, int height, t_data *data);

void		map_w_h(t_data *data);
void		player_w_h(t_data *data);
int			wall(char *line);
int			map_char_check(char *map);

t_data		*data_init(char *map);

#endif
