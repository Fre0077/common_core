/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:34:17 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 09:38:13 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "stdio.h"
# include "stdlib.h"
# include "ft_printf/ft_printf.h"

typedef struct s_texture
{
	void	*mlx;
	void	*win;
	void	*frog;//player
	void	*boot;//enemy
	void	*portal;//exit
	void	*fly;//coin
	void	*lily;//wall
	void	*water;//backgroud
}	t_texture;

typedef struct s_map
{
	char		**matrix;
	int			height;
	int			witdh;
	int			py;
	int			px;
	int			n_move;
	int			n_coin;
	int			score;
	int			old_score;
	t_texture	base;
}	t_map;

void	ft_print_matrix(char **matrix);

char	**create_matrix(char *map_file, t_map *map);
int		check_cpe(char **matrix, t_map *map);
int		check_wall(char **matrix, t_map *map);
int		check_path(char **matrix, t_map *map);
void	set_image(t_texture *base);
void	delete_image(t_texture *base);
void	*tale(t_texture base, char c);
void	set_map(t_texture base, t_map map);
void	move(t_map *map, int new_py, int new_px);
int		close_window(t_map *map);

#endif