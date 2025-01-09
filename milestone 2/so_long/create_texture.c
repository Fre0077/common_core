/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:34:12 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 14:13:05 by fde-sant         ###   ########.fr       */
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
	base->lily = create_image("textures/FLOWER_LILY.xpm", base);
	base->frog = create_image("textures/FROG.xpm", base);
	base->fly = create_image("textures/FLY.xpm", base);
	base->portal = create_image("textures/CLOSE_PORTAL.xpm", base);
}

void	delete_image(t_texture *base)
{
	mlx_destroy_image(base->mlx, base->water);
	mlx_destroy_image(base->mlx, base->lily);
	mlx_destroy_image(base->mlx, base->frog);
	mlx_destroy_image(base->mlx, base->fly);
	mlx_destroy_image(base->mlx, base->portal);
}
