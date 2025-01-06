/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:34:12 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/06 16:28:14 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_image(char *name, t_texture *base)
{
	int w;
    int h;

	return (mlx_xpm_file_to_image(base->mlx, name, &w, &h));
}

void	set_image(t_texture *base)
{
	base->water = create_image("textures/water.xpm", base);
	base->lily = create_image("textures/lily.xpm", base);
	base->frog = create_image("textures/frog.xpm", base);
	base->fly = create_image("textures/fly.xpm", base);
	base->portal = create_image("textures/portal.xpm", base);
}

void	create_map(t_texture *base)
{
	int	x;
	int	y;

	y = 0;
	while (y < 512)
	{
		x = 0;
		while (x < 1024)
		{
			mlx_put_image_to_window(base->mlx, base->win, base->fly, x, y);
			x += 32;
		}
		y += 32;
	}
}