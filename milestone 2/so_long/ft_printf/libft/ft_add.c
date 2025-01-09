/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:18:21 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 10:46:23 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add(char *str, char *add)
{
	int		i;
	int		j;
	char	*ret;

	j = -1;
	ret = ft_calloc(ft_strlen(str) + ft_strlen(add) + 1);
	i = -1;
	if (str != NULL)
		while (str[++i])
			ret[++j] = str[i];
	i = -1;
	if (add != NULL)
		while (add[++i])
			ret[++j] = add[i];
	return (ret);
}
