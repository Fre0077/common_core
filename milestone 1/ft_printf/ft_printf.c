/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:24:52 by fde-sant          #+#    #+#             */
/*   Updated: 2024/11/26 13:40:02 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(char *input, va_list arg, int *i)
{
	if (input[*i] != '%')
		return (1);
	if (input[*i + 1] == 'c')
		ft_putchar(va_arg(arg, char));
	else if (input[*i + 1] == 's')
		ft_putstr(va_arg(arg, char*));
	else if (input[*i + 1] == 'p')
		ft_putstr(va_arg(arg, char*));
	else if (input[*i + 1] == 'd')
		ft_putstr(va_arg(arg, int));
	else if (input[*i + 1] == 'i')
		ft_putstr(va_arg(arg, int));
	else if (input[*i + 1] == 'u')
		ft_putstr(va_arg(arg, unsigned int));
	else if (input[*i + 1] == 'x')
		ft_putstr(va_arg(arg, int));
	else if (input[*i + 1] == 'X')
		ft_putstr(va_arg(arg, int));
	else if (input[*i + 1] == '%')
		write(1, '%', 1);
	return (*i++, 0);
}

int ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;

	i = -1;
	va_strat(arg, input);
	while (input[++i])
		if (ft_check_arg(input, arg, &i))
			write(1, &input[i], 1);

}

int main()
{
	
}