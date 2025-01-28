/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:39:15 by ecarbona          #+#    #+#             */
/*   Updated: 2025/01/28 20:57:55 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_arg(const char *input, va_list *arg, int *i, int *len)
{
	if (input[*i] != '%')
		return (0);
	if (input[*i + 1] == '\0')
		return (1);
	if (input[*i + 1] == 'c')
		*len += ft_putchar_fd(va_arg(*arg, int), 1);
	else if (input[*i + 1] == 's')
		*len += ft_putstr_fd(va_arg(*arg, char *), 1);
	else if (input[*i + 1] == 'p')
		*len += ft_putbase_long(va_arg(*arg, void *), "0123456789abcdef");
	else if (find_cinstr(input[*i + 1], "diul"))
		*len += ft_putnbr_fd(va_arg(*arg, long), 1);
	else if (input[*i + 1] == 'x')
		*len += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (input[*i + 1] == 'X')
		*len += ft_putbase(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (input[*i + 1] == '%')
		*len += ft_putchar_fd('%', 1);
	return ((*i)++, 1);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;
	int		len;

	if (!input)
		return (-1);
	i = -1;
	len = 0;
	va_start(arg, input);
	while (input[++i])
	{
		if (ft_check_arg(input, &arg, &i, &len) == 0)
		{
			write(1, &input[i], 1);
			len++;
		}
	}
	va_end(arg);
	return (len);
}
