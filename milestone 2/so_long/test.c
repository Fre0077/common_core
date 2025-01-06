/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:31:18 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/06 18:29:19 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
	(void)param;  // Parametro che non usiamo
	exit(0);      // Termina il programma
	return 0;
}



int main(int ac, char **av)
{
	char	**matrix;
	matrix = create_matrix(av[1]);
	int		y = -1;
	int		x;
	while (matrix[++y] != NULL)
	{
		x = -1;
		while (matrix[y][++x] != '\0')
			write(1, &matrix[y][x], 1);
		write(1, "\n", 1);
	}
	exit(0);
	t_texture   base;
	

	if (ac != 2)
		return (0);
	base.mlx = mlx_init();
	if (base.mlx == NULL)
		return 1;
	base.win = mlx_new_window(base.mlx, 1024, 512, "MiniLibX Example");
	if (base.win == NULL)
		return 1;
	set_image(&base);
	create_map(&base);
	mlx_hook(base.win, 17, 0, close_window, NULL);
	mlx_loop(base.mlx);

	return 0;
}

//cc test.c -g -Lmlx -lmlx -lXext -lX11 -lm -Lmlx -lmlx -lXext -lX11 -lm