/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:48:08 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 08:16:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*tale(t_map map, char c)
{
	if (c == '0' && map.base.water != NULL)
		return (map.base.water);
	else if (c == '1' && map.base.lily != NULL)
		return (map.base.lily);
	else if (c == '2' && map.base.lily != NULL)
		return (map.base.flily);
	else if (c == 'P' && map.base.frog != NULL)
		return (map.base.frog);
	else if (c == 'C' && map.base.fly != NULL)
		return (animation_fly(map));
	else if (c == 'N' && map.base.stone != NULL)
		return (map.base.stone);
	else if (c == 'e' && map.base.portal1 != NULL && map.base.portal2 != NULL
		&& map.base.portal3 != NULL && map.base.portal4 != NULL)
		return (animation_portal(map));
	else if (c == 'E' && map.base.portal != NULL)
		return (map.base.portal);
	return (close_window(&map), NULL);
}

void	place_tale(t_texture base, t_map map, int y, int x)
{
	int	vary;
	int	varx;

	if (map.height > 21)
	{
		vary = map.py + y;
		if (map.py - 10 < 0)
			vary += 10 - ft_distance(0, map.py, map.height - 1);
		else if (map.py + 10 >= map.height)
			vary -= 10 - ft_distance(0, map.py, map.height - 1);
	}
	else
		vary = y + 10;
	if (map.witdh > 21)
	{
		varx = map.px + x;
		if (map.px - 10 < 0)
			varx += 10 - ft_distance(0, map.px, map.witdh - 1);
		else if (map.px + 10 >= map.witdh)
			varx -= 10 - ft_distance(0, map.px, map.witdh - 1);
	}
	else
		varx = x + 10;
	mlx_put_image_to_window(base.mlx, base.win,
		tale(map, map.matrix[vary][varx]), (x + 10) * 32, (y + 10) * 32);
}

void	put_score(t_texture base, t_map map)
{
	char	*score;

	mlx_string_put(base.mlx, base.win, 10, 690, 0xFFFFFF, "Score:");
	mlx_string_put(base.mlx, base.win, 80, 690, 0xFFFFFF, "/");
	mlx_string_put(base.mlx, base.win, 300, 690, 0xFFFFFF, "Move:");
	score = ft_itoa(map.old_score);
	mlx_string_put(base.mlx, base.win, 60, 690, 0x000000, score);
	free(score);
	score = ft_itoa(map.score);
	mlx_string_put(base.mlx, base.win, 60, 690, 0xFFFFFF, score);
	free(score);
	score = ft_itoa(map.n_coin);
	mlx_string_put(base.mlx, base.win, 100, 690, 0xFFFFFF, score);
	free(score);
	score = ft_itoa(map.n_move - 1);
	mlx_string_put(base.mlx, base.win, 333, 690, 0x000000, score);
	free(score);
	score = ft_itoa(map.n_move);
	mlx_string_put(base.mlx, base.win, 333, 690, 0xFFFFFF, score);
	free(score);
}

void	open_portal(t_map map)
{
	map.matrix[map.ey][map.ex] = 'e';
	map.portal = 1;
}

int	set_map(t_map *map)
{
	int	x;
	int	y;

	map->time += 1;
	all_enemy(map, 0, 'C', 77);
	all_enemy(map, 0, 'N', 120);
	if (map->score == map->n_coin && map->portal == 0)
		open_portal(*map);
	set_image(&map->base);
	put_score(map->base, *map);
	y = -10;
	while (y <= 10 && y + 10 < map->height)
	{
		x = -10;
		while (x <= 10 && x + 10 < map->witdh)
			place_tale(map->base, *map, y, x++);
		y++;
	}
	delete_image(&map->base);
	return (0);
}
