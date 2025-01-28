/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:52:19 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/28 20:58:22 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase_long(void *n, char *base)
{
	unsigned long	temp;
	char			*array;
	int				i;

	if (!n)
		return (write (1, "(nil)", 5), 5);
	write(1, "0x", 2);
	temp = (unsigned long)n;
	i = -1;
	while (temp > 0 && ++i + 1)
		temp /= 16;
	array = ft_calloc(i + 1);
	temp = (unsigned long)n;
	while (temp > 0)
	{
		array[--i] = base[temp % 16];
		temp /= 16;
	}
	while (array[i])
		write (1, &array[i++], 1);
	return (free (array), i + 2);
}
