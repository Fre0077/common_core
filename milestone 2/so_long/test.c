/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:31:18 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 11:13:56 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_press(int key, t_map *map)
{
	if (key == XK_Escape)
		exit(0);
	if (key == XK_w)
		move(map, map->py - 1, map->px);
	if (key == XK_s)
		move(map, map->py + 1, map->px);
	if (key == XK_a)
		move(map, map->py, map->px - 1);
	if (key == XK_d)
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
	base.win = mlx_new_window(base.mlx, 672, 672, "So_long");
	if (base.win == NULL)
		return (1);
	set_map(base, map);
	mlx_hook(base.win, 17, 0, close_window, NULL);
	mlx_key_hook(base.win, key_press, &map);
	mlx_loop(base.mlx);
	return (0);
}

//cc test.c -g -Lmlx -lmlx -lXext -lX11 -lm -Lmlx -lmlx -lXext -lX11 -lm