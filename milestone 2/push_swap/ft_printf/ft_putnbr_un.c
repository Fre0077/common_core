/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:08:11 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 13:30:51 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int		i;
	int		len;
	char	num[10];

	i = 0;
	len = 0;
	while (n >= 10)
	{
		num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	num[i] = (n % 10) + '0';
	len = i + 1;
	while (i >= 0)
		write(1, &num[i--], 1);
	return (len);
}
