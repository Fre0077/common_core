/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:19:21 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 12:30:04 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_tale(t_texture base, t_map map, int y, int x)
{
	int	vary;
	int	varx;

	vary = map.py + y - 10;
	if (vary < 0)
		vary += 10 - ft_distance(0, map.py, map.height - 1);
	else if (vary > map.height)
		vary -= 10 - ft_distance(0, map.py, map.height - 1);
	varx = map.px + x - 10;
	if (varx < 0)
		varx += 10 - ft_distance(0, map.px, map.witdh - 1);
	else if (varx > map.witdh)
		varx -= 10 - ft_distance(0, map.py, map.witdh - 1);
	mlx_put_image_to_window(base.mlx, base.win,
			tale(base, map.matrix[vary][varx]), x * 32, y * 32);
	// ft_printf("witdh: %d  heitgh: %d\nvarx: %d   vary: %d\nx: %d       y: %d\npx: %d     py: %d\ndistx: %d  disty: %d\n", map.witdh, map.height, varx, vary, x, y, map.px, map.py, ft_distance(0, map.px, map.witdh - 1), ft_distance(0, map.py, map.height - 1));
	//exit (0);
}

void	set_map(t_texture base, t_map map)
{
	int	x;
	int	y;

	set_image(&base);
	y = -1;
		while (++y <= 20)
		{
			x = -1;
			while (++x <= 20)
			{
				place_tale(base, map, y, x);
			}
		}
}
