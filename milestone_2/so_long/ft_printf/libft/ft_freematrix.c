/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:55:26 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 11:06:03 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freematrix(char **matrix, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(matrix[i]);
	free(matrix);
}
