/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:11:28 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 08:15:35 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_map *map, int new_py, int new_px)
{
	if (map->matrix[new_py][new_px] == 'C')
	{
		map->score += 1;
		map->old_score += 1;
	}
	if (ft_findc("Ne", map->matrix[new_py][new_px]))
		close_window(map);
	if (ft_findc("12E", map->matrix[new_py][new_px]))
		return ;
	map->n_move += 1;
	map->matrix[map->py][map->px] = '0';
	map->py = new_py;
	map->px = new_px;
	map->matrix[map->py][map->px] = 'P';
}

void	move_enemy(t_map *map, int ey, int ex, int casual)
{
	char	tale;

	tale = map->matrix[ey][ex];
	if (casual == 0 && map->matrix[ey][ex - 1] == '0')
	{
		map->matrix[ey][ex] = '0';
		map->matrix[ey][ex - 1] = tale;
	}
	if (casual == 1 && map->matrix[ey + 1][ex] == '0')
	{
		map->matrix[ey][ex] = '0';
		map->matrix[ey + 1][ex] = tale;
	}
	if (casual == 2 && map->matrix[ey][ex + 1] == '0')
	{
		map->matrix[ey][ex] = '0';
		map->matrix[ey][ex + 1] = tale;
	}
	if (casual == 3 && map->matrix[ey - 1][ex] == '0')
	{
		map->matrix[ey][ex] = '0';
		map->matrix[ey - 1][ex] = tale;
	}
}

void	rand_enemy(t_map *map, int ey, int ex)
{
	int	casual;

	srand(time(NULL) + ex + ey);
	casual = rand() % 4;
	if (casual == 0 && map->matrix[ey][ex - 1] != '0')
		casual = 2;
	if (casual == 1 && map->matrix[ey + 1][ex] != '0')
		casual = 3;
	if (casual == 2 && map->matrix[ey][ex + 1] != '0')
		casual = 0;
	if (casual == 3 && map->matrix[ey - 1][ex] != '0')
		casual = 1;
	if (casual == 0 && map->matrix[ey][ex - 1] != '0')
		casual = 1;
	if (casual == 1 && map->matrix[ey + 1][ex] != '0')
		casual = 0;
	if (casual == 2 && map->matrix[ey][ex + 1] != '0')
		casual = 3;
	if (casual == 3 && map->matrix[ey - 1][ex] != '0')
		casual = 2;
	move_enemy(map, ey, ex, casual);
}

int	all_enemy(t_map *map, int find_e, char tale, int speed)
{
	int	x;
	int	y;
	int	count_e;

	if (map->time % speed != 0 || map->time == 0)
		return (0);
	y = -1;
	count_e = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->witdh)
		{
			if (map->matrix[y][x] == tale)
			{
				if (++count_e > find_e)
				{
					all_enemy(map, find_e + 1, tale, speed);
					return (rand_enemy(map, y, x), 0);
				}
			}
		}
	}
	return (0);
}

int	animation(t_map *map)
{
	(void)map;
	return (0);
}
