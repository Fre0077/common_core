/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:23:40 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/12 08:15:56 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*animation_portal(t_map map)
{
	int	time;

	time = 42;
	if ((map.time / time) % 4 == 0)
		return (map.base.portal1);
	else if ((map.time / time) % 4 == 1)
		return (map.base.portal2);
	else if ((map.time / time) % 4 == 2)
		return (map.base.portal3);
	else
		return (map.base.portal4);
}

void	*animation_fly(t_map map)
{
	int	time;

	time = 20;
	if ((map.time / time) % 2 == 0)
		return (map.base.fly);
	else
		return (map.base.fly2);
}
