/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:40:34 by fde-sant          #+#    #+#             */
/*   Updated: 2024/11/26 10:14:33 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	test(char *input, ...)
{
	va_list	arg;
	int	i;

	va_start(arg, input);
	i = -1;
	while (input[++i])
	{
		if (input[i] == '%' && input[i + 1] == 's')
		{
			write(1, va_arg(arg, char*), 1);
			i++;
		}
		else
			write(1, &input[i], 1);
	}
	va_end(arg);
	return (0);
}

int main()
{
	int  i;
	i = test("1: %,\n2: %s,\n3: %s", "c", "o", "s");
}