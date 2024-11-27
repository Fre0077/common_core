/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:39:15 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 09:56:45 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_arg(const char *input, va_list *arg, int *i)
{
	if (input[*i] != '%')
		return (1);
	if (input[*i + 1] == 'c')
		return (ft_putchar_fd(va_arg(*arg, int), 1), (*i)++, 0);
	else if (input[*i + 1] == 's')
		return(ft_putstr_fd(va_arg(*arg, char*), 1), (*i)++, 0);
	else if (input[*i + 1] == 'p')
		return(write(1, "0x", 2),
		ft_putbase_long((unsigned long)va_arg(*arg, void *)), (*i)++, 0);
	else if (input[*i + 1] == 'd' || input[*i + 1] == 'i')
		return(ft_putnbr_fd(va_arg(*arg, int), 1), (*i)++, 0);
	else if (input[*i + 1] == 'u')
		return(ft_putnbr_un(va_arg(*arg, int)), (*i)++, 0);
	else if (input[*i + 1] == 'x')
		return(ft_putbase(va_arg(*arg, unsigned int),
		"0123456789abcdef"), (*i)++, 0);
	else if (input[*i + 1] == 'X')
		return(ft_putbase(va_arg(*arg, unsigned int),
		"0123456789ABCDEF"), (*i)++, 0);
	else if (input[*i + 1] == '%')
		write(1, "%", 1);
	return ((*i)++ , 0);
}

int ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;

	i = -1;
	va_start(arg, input);
	while (input[++i])
		if (ft_check_arg(input, &arg, &i))
			write(1, &input[i], 1);
	va_end(arg);
	return (0);
}

int main()
{
	int x = -42;
    int *p = &x;
    
	printf("%p\n", p);
	ft_printf("%p\n", p);
    return 0;
}