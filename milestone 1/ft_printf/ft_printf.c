/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:24:52 by fde-sant          #+#    #+#             */
/*   Updated: 2024/11/26 10:30:00 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(char *input, va_list arg, int *i)
{
	return (1);
}

int ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;

	i = -1;
	while (input[++i])
		if (ft_check_arg(input, arg, &i))
			write(1, &input[i], 1);

}

int main()
{
	
}