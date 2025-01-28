/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_callocn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:54 by fre007            #+#    #+#             */
/*   Updated: 2025/01/28 20:53:39 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	*ft_callocn(long size)
{
	long	*arr;

	if (size == 0)
		return (0);
	arr = malloc(sizeof(long) * size);
	if (!arr)
		return (0);
	while (--size >= 0)
		arr[size] = 0;
	return (arr);
}