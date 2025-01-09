/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:48:08 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 14:08:06 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*tale(t_texture base, char c)
{
	if (c == '0')
		return (base.water);
	else if (c == '1')
		return (base.lily);
	else if (c == 'P')
		return (base.frog);
	else if (c == 'C')
		return (base.fly);
	return (base.portal);
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
			tale(base, map.matrix[vary][varx]), (x + 10) * 32, (y + 10) * 32);
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

void	set_map(t_texture base, t_map map)
{
	int	x;
	int	y;

	set_image(&base);
	put_score(base, map);
	y = -10;
	while (y <= 10 && y + 10 < map.height)
	{
		x = -10;
		while (x <= 10 && x + 10 < map.witdh)
			place_tale(base, map, y, x++);
		y++;
	}
	delete_image(&base);
}