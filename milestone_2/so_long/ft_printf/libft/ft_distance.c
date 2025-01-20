/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:29:23 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 11:05:27 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_distance(int a, int middle, int b)
{
	if (ft_diff(a, middle) > ft_diff(middle, b))
		return (ft_diff(middle, b));
	else
		return (ft_diff(a, middle));
}
