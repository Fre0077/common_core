/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:56:56 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 09:21:29 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finder(char **matrix, t_map *map, char c)
{
	int	x;
	int	y;

	y = -1;
	while (++y != map->height)
	{
		x = -1;
		while (++x != map->witdh)
		{
			if (matrix[y][x] == c)
			{
				if (c == 'P')
				{
					map->py = y;
					map->px = x;
				}
				if (c == 'E')
				{
					map->ey = y;
					map->ex = x;
				}
				return ;
			}
		}
	}
}

int	line_len(char *map, int *raw, char *add)
{
	int		read_ret;
	int		i;
	int		fd;
	char	c;

	i = -1;
	fd = open(map, O_RDONLY);
	read_ret = read(fd, &c, 1);
	while (++i + 1 && read_ret && c != '\n' && ft_findc("01ENPC", c) == 1)
		read_ret = read(fd, &c, 1);
	add = ft_calloc(i + 2);
	read_ret = read(fd, add, i + 1);
	while (read_ret > 0)
	{
		if (add[i] != '\n' && add[i] != '\0')
			return (ft_printf("Error\nnot rettagle, colomn\n"), free(add), 0);
		*raw = *raw + 1;
		if (read_ret != i && read_ret != i + 1)
			return (ft_printf("Error\nnot rettagle, raw\n"), free(add), 0);
		read_ret = read(fd, add, i + 1);
	}
	if (i == 0)
		return (ft_printf("Error\nbad file\n"), close(fd), free(add), i);
	return (close(fd), free(add), i);
}

int	copy_in_matrix(char **matrix, char *map_file, int size, int raw)
{
	int		x;
	int		y;
	int		fd;
	char	*add;

	add = ft_calloc(size + 2);
	fd = open(map_file, O_RDONLY);
	read(fd, add, size + 1);
	y = -1;
	while (++y != raw)
	{
		x = -1;
		matrix[y] = ft_calloc(size + 1);
		while (++x != size)
		{
			if (ft_findc("10PECN", add[x]) == 0)
				return (ft_printf("Error\ninvalid char\n"), 0);
			matrix[y][x] = add[x];
		}
		read(fd, add, size + 1);
	}
	return (free(add), close(fd), 1);
}

int	check(char **matrix, t_map *map)
{
	finder(matrix, map, 'P');
	finder(matrix, map, 'E');
	map->n_move = 0;
	map->score = 0;
	map->old_score = -1;
	if (check_wall(matrix, map) == 0)
		return (ft_printf("Error\nopen wall\n"), 0);
	if (check_cpe(matrix, map) == 0)
		return (ft_printf("Error\nCPE problem\n"), 0);
	if (check_path(matrix, map) == 0)
		return (ft_printf("Error\nno safe path\n"), 0);
	return (1);
}

char	**create_matrix(char *map_file, t_map *map)
{
	char	**matrix;
	char	*add;
	int		size;
	int		raw;

	raw = 1;
	add = NULL;
	size = line_len(map_file, &raw, add);
	map->height = raw;
	map->witdh = size;
	if (size == 0)
		return (NULL);
	matrix = malloc((raw + 1) * sizeof(char *));
	matrix[raw] = NULL;
	if (copy_in_matrix(matrix, map_file, size, raw) == 0
		|| check(matrix, map) == 0)
		return (ft_freematrix(matrix, map->height), NULL);
	rand_lily(matrix, *map);
	return (matrix);
}
