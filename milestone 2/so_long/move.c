/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:11:28 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 10:47:58 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ft_printf("py: %d  px: %d | npy: %d  npx: %d\n\n\n", map->py, map->px, new_py, new_px);
void	move(t_map *map, int new_py, int new_px)
{
	if (map->matrix[new_py][new_px] == 'C')
	{
		map->score += 1;
		map->old_score += 1;
	}
	if (map->matrix[new_py][new_px] == 'E' && map->n_coin == map->score)
		close_window(map);
	if (map->matrix[new_py][new_px] == '1'
		|| map->matrix[new_py][new_px] == 'E')
		return ;
	map->n_move += 1;
	map->matrix[map->py][map->px] = '0';
	map->py = new_py;
	map->px = new_px;
	map->matrix[map->py][map->px] = 'P';
}
