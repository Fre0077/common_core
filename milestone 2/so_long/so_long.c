/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:31:18 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 08:50:25 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map)
{
	ft_freematrix(map->matrix, map->height);
	mlx_destroy_window(map->base.mlx, map->base.win);
	mlx_destroy_display(map->base.mlx);
	free(map->base.mlx);
	exit(0);
	return (0);
}

int	key_press(int key, t_map *map)
{
	if (key == XK_Escape)
		close_window(map);
	if (key == XK_w)
		move(map, map->py - 1, map->px);
	if (key == XK_s)
		move(map, map->py + 1, map->px);
	if (key == XK_a)
		move(map, map->py, map->px - 1);
	if (key == XK_d)
		move(map, map->py, map->px + 1);
	if (key == 65362)
		move(map, map->py - 1, map->px);
	if (key == 65364)
		move(map, map->py + 1, map->px);
	if (key == 65361)
		move(map, map->py, map->px - 1);
	if (key == 65363)
		move(map, map->py, map->px + 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_texture	base;
	t_map		map;

	if (ac != 2)
		return (0);
	map.matrix = create_matrix(av[1], &map);
	if (map.matrix == NULL)
		return (0);
	base.mlx = mlx_init();
	if (base.mlx == NULL)
		return (1);
	base.win = mlx_new_window(base.mlx, 672, 700, "So_long");
	if (base.win == NULL)
		return (1);
	map.n_coin = ft_countc_matrix(map.matrix, 'C', map.height);
	map.base = base;
	map.portal = 0;
	map.time = 0;
	animation(&map);
	mlx_loop_hook(base.mlx, set_map, &map);
	mlx_hook(base.win, 17, 0, close_window, &map);
	mlx_key_hook(base.win, key_press, &map);
	mlx_loop(base.mlx);
	return (0);
}
