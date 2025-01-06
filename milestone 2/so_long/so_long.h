/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:34:17 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/06 16:58:09 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LONG
# define S_LONG
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct s_texture
{
	void	*mlx;
	void	*win;
	void	*mlx_img;
	void	*frog;   //player
	void	*boot;   //enemy
	void	*portal; //exit
	void	*fly;    //coin
	void	*lily;   //wall
	void	*water;  //backgroud
}	t_texture;

void	set_image(t_texture *base);
void	create_map(t_texture *base);
char	**create_matrix(char *map);

#endif