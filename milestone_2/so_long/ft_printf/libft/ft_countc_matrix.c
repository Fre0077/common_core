/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:47:54 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 16:04:58 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countc_matrix(char **matrix, char c, int height)
{
	int	i;
	int	h;

	if (matrix == NULL)
		return (0);
	i = 0;
	h = -1;
	while (++h < height)
		i += ft_countc(matrix[h], c);
	return (i);
}
