/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:06:06 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 09:05:14 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **matrix)
{
	int	y;

	y = -1;
	while (matrix[++y] != NULL)
		ft_printf("%s\n", matrix[y]);
}
