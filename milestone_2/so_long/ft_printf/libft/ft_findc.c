/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:05:57 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/08 11:05:23 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findc(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return (1);
	return (0);
}
