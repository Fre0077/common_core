/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:02:38 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/28 20:58:11 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	char	*num;
	int		i;

	num = ft_itoa(n);
	i = -1;
	while (num[++i])
		write(fd, &num[i], 1);
	return (i + 1);
}
