/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:45:26 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/20 12:10:59 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer.h"

//verifica che il carattere passato sia una lettera
int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

//verifica che il carattere passato sia un whitespace
int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\r')
	{
		return (1);
	}
	return (0);
}

//converte una stringa in un intero(lievemente modificata per philosofer)
int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	if (str[i])
		return (-1);
	num = num * sign;
	return (num);
}
