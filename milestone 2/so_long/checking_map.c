/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:06:46 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 09:28:15 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cpe(char **matrix, t_map *map)
{
	int	c;
	int	p;
	int	e;
	int	i;

	c = 0;
	p = 0;
	e = 0;
	i = -1;
	while (++i < map->height)
	{
		p += ft_countc(matrix[i], 'P');
		e += ft_countc(matrix[i], 'E');
	}
	i = -1;
	while (++i < map->height)
		if (ft_findc(matrix[i], 'C'))
			c++;
	if (p == 1 && e == 1 && c > 0)
		return (1);
	else
		return (0);
}

int	check_wall(char **matrix, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if (ft_findc("0ENPC", matrix[i][0]))
			return (0);
		if (ft_findc("0ENPC", matrix[i][map->witdh - 1]))
			return (0);
	}
	i = -1;
	while (++i < map->witdh)
	{
		if (ft_findc("0ENPC", matrix[0][i]))
			return (0);
		if (ft_findc("0ENPC", matrix[map->height - 1][i]))
			return (0);
	}
	return (1);
}

char	**matrix_copy(char **matrix, t_map *map)
{
	int		x;
	int		y;
	char	**new_matrix;

	y = -1;
	new_matrix = malloc(sizeof(char *) * (map->height + 1));
	new_matrix[map->height] = NULL;
	while (++y != map->height)
	{
		x = -1;
		new_matrix[y] = ft_calloc(map->witdh + 1);
		while (++x != map->witdh)
			new_matrix[y][x] = matrix[y][x];
	}
	return (new_matrix);
}

void	path_tracking(char **matrix, int y, int x)
{
	matrix[y][x] = '1';
	if (ft_findc("0C", matrix[y][x - 1]))
		path_tracking(matrix, y, x - 1);
	if (ft_findc("0C", matrix[y + 1][x]))
		path_tracking(matrix, y + 1, x);
	if (ft_findc("0C", matrix[y][x + 1]))
		path_tracking(matrix, y, x + 1);
	if (ft_findc("0C", matrix[y - 1][x]))
		path_tracking(matrix, y - 1, x);
	if ('E' == matrix[y][x - 1])
		matrix[y][x - 1] = '1';
	if ('E' == matrix[y + 1][x])
		matrix[y + 1][x] = '1';
	if ('E' == matrix[y][x + 1])
		matrix[y][x + 1] = '1';
	if ('E' == matrix[y - 1][x])
		matrix[y - 1][x] = '1';
}

int	check_path(char **matrix, t_map *map)
{
	char	**new_matrix;
	int		i;

	new_matrix = matrix_copy(matrix, map);
	path_tracking(new_matrix, map->py, map->px);
	i = -1;
	while (++i < map->height)
		if (ft_findc(new_matrix[i], 'C')
			|| ft_findc(new_matrix[i], 'E'))
			return (ft_freematrix(new_matrix, map->height), 0);
	return (ft_freematrix(new_matrix, map->height), 1);
}
