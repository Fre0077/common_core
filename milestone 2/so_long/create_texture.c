/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:34:12 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 08:17:17 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_image(char *name, t_texture *base)
{
	int	w;
	int	h;

	return (mlx_xpm_file_to_image(base->mlx, name, &w, &h));
}

void	set_image(t_texture *base)
{
	base->water = create_image("textures/WATER.xpm", base);
	base->flily = create_image("textures/FLOWER_LILY.xpm", base);
	base->lily = create_image("textures/LILY.xpm", base);
	base->frog = create_image("textures/FROG.xpm", base);
	base->fly = create_image("textures/FLY.xpm", base);
	base->fly2 = create_image("textures/FLY_2.xpm", base);
	base->stone = create_image("textures/STONE.xpm", base);
	base->portal = create_image("textures/CLOSE_PORTAL.xpm", base);
	base->portal1 = create_image("textures/PORTAL_1.xpm", base);
	base->portal2 = create_image("textures/PORTAL_2.xpm", base);
	base->portal3 = create_image("textures/PORTAL_3.xpm", base);
	base->portal4 = create_image("textures/PORTAL_4.xpm", base);
}

void	delete_image(t_texture *base)
{
	mlx_destroy_image(base->mlx, base->water);
	mlx_destroy_image(base->mlx, base->flily);
	mlx_destroy_image(base->mlx, base->lily);
	mlx_destroy_image(base->mlx, base->frog);
	mlx_destroy_image(base->mlx, base->fly);
	mlx_destroy_image(base->mlx, base->fly2);
	mlx_destroy_image(base->mlx, base->stone);
	mlx_destroy_image(base->mlx, base->portal);
	mlx_destroy_image(base->mlx, base->portal1);
	mlx_destroy_image(base->mlx, base->portal2);
	mlx_destroy_image(base->mlx, base->portal3);
	mlx_destroy_image(base->mlx, base->portal4);
}

void	rand_lily(char **matrix, t_map map)
{
	int	casual;
	int	y;
	int	x;

	y = -1;
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.witdh)
		{
			if (matrix[y][x] == '1')
			{
				srand(time(NULL) + y + x);
				casual = rand() % 2;
				if (casual == 0)
					matrix[y][x] = '1';
				else
					matrix[y][x] = '2';
			}
		}
	}
}
