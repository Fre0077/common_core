/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:59:11 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:22:00 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index.h"

long	*ft_ncalloc(int len)
{
	long	*new;
	int		i;

	new = malloc(sizeof(long) * len);
	i = -1;
	while (++i < len)
		new[i] = 777777777777777;
	return (new);
}

char	*ft_calloc(int len)
{
	char	*new;
	int		i;

	new = malloc(sizeof(long) * len);
	i = -1;
	while (++i < len)
		new[i] = '\0';
	return (new);
}
