/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:34:17 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/23 09:12:18 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "time.h"
# include "stdio.h"
# include "stdlib.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "ft_printf/ft_printf.h"

typedef struct s_texture
{
	void	*mlx;
	void	*win;
	void	*frog;//player
	void	*boot;//enemy
	void	*fly;//coin
	void	*fly2;
	void	*lily;//wall
	void	*flily;
	void	*water;//backgroud
	void	*stone;//enemy
	void	*portal;//exit
	void	*portal1;
	void	*portal2;
	void	*portal3;
	void	*portal4;
}	t_texture;

typedef struct s_map
{
	char		**matrix;
	int			height;
	int			witdh;
	int			py;
	int			px;
	int			ey;
	int			ex;
	int			n_move;
	int			n_coin;
	int			score;
	int			old_score;
	int			time;
	int			portal;
	t_texture	base;
}	t_map;

void	set_image(t_texture *base);
void	delete_image(t_texture *base);
void	rand_lily(char **matrix, t_map map);
void	move(t_map *map, int new_py, int new_px);

void	*tale(t_map map, char c);
void	*animation_fly(t_map map);
void	*animation_portal(t_map map);

char	**create_matrix(char *map_file, t_map *map);

int		set_map(t_map *map);
int		animation(t_map *map);
int		close_window(t_map *map);
int		check_cpe(char **matrix, t_map *map);
int		check_wall(char **matrix, t_map *map);
int		check_path(char **matrix, t_map *map);
int		all_enemy(t_map *map, int find_e, char tale, int speed);

#endif