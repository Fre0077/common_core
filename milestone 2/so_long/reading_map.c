/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:56:56 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/06 18:31:31 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_calloc(int	len)
{
	char	*str;
	int		i;

	str = malloc(len);
	i = -1;
	while (++i < len)
		str[i] = '\0';
	return (str);
}

char	**copy_in_matrix(char **matrix, char *add, int size, int raw, int fd)
{
	int	x;
	int	y;

	y = -1;
	while (++y != raw)
	{
		x = -1;
		add = ft_calloc(size + 1);
		while (++x != size - 1)
			matrix[y][x] = add[x];
		read(fd, add, size);
	}
	free(add);
	return (matrix);
}

int	line_len(char *map, int *raw)
{
	char	*add;
	char	c;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (read(fd, &c, 1) <= 0)
		return (0);
	while (c != '\n')
	{
		i++;
		read(fd, &c, 1);
	}
	add = ft_calloc(i);
	while (read(fd, add, i) != 0)
	{
		if (add[i - 1] != '\n' && add[i - 1] != '\0')
			return (0);
		*raw = *raw + 1;
		free(add);
		add = ft_calloc(i);
	}
	close(fd);
	return (free(add), i);
}

char	**create_matrix(char *map)
{
	char    **matrix;
	char    *add;
	int     size;
	int		raw;
	int     fd;

	raw = 1;
	size = line_len(map, &raw);
	fd = open(map, O_RDONLY);
	add = ft_calloc(size + 1);
	read(fd, add, size);
	matrix = malloc((raw + 1) * sizeof(char *));
	matrix[raw] = NULL;
	copy_in_matrix(matrix, add, size, raw, fd);
	close(fd);
	return (matrix);
}