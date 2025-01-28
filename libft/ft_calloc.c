/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:42 by fre007            #+#    #+#             */
/*   Updated: 2025/01/28 18:05:00 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc(long size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (--size >= 0)
		str[size] = '\0';
	return (str);
}