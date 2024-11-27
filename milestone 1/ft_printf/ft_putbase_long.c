/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:52:19 by fde-sant          #+#    #+#             */
/*   Updated: 2024/11/27 11:21:07 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putbase_long(unsigned long n)
{
	unsigned long	temp;
	char			*array;
	char			*base;
	int				i;

	write(1, "0x", 2);
	base = "0123456789abcdef";
	temp = n;
	i = 0;
	while (temp > 0)
	{
		temp /= 16;
		i++;
	}
	array = malloc(sizeof(char) * (i + 1));
	array[i] = '\0';
	while (n > 0)
	{
		array[--i] = base[n % 16];
		n = n / 16;
	}
	while (array[i])
		write (1, &array[i++], 1);
	free (array);
}
