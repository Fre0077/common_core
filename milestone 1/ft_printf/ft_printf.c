/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:39:15 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/27 11:25:15 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_arg(const char *input, va_list *arg, int *i)
{
	if (input[*i] != '%')
		return (1);
	if (input[*i + 1] == 'c')
		ft_putchar_fd(va_arg(*arg, int), 1);
	else if (input[*i + 1] == 's')
		ft_putstr_fd(va_arg(*arg, char *), 1);
	else if (input[*i + 1] == 'p')
		ft_putbase_long((unsigned long)va_arg(*arg, void *));
	else if (input[*i + 1] == 'd' || input[*i + 1] == 'i')
		ft_putnbr_fd(va_arg(*arg, int), 1);
	else if (input[*i + 1] == 'u')
		ft_putnbr_un(va_arg(*arg, int));
	else if (input[*i + 1] == 'x')
		ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (input[*i + 1] == 'X')
		ft_putbase(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (input[*i + 1] == '%')
		write (1, "%", 1);
	return ((*i)++, 0);
}

int	ft_printf(const char *input, ...)
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

/* int main()
{
	int i = 010;
	ft_printf("%p\n", &i);
	ft_printf("%p\n", &i);
	ft_printf("%p\n", &i);
} */