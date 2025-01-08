/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:39:08 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 11:05:11 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countc(char *str, char c)
{
	int	i;
	int	val;

	val = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			val++;
	return (val);
}
