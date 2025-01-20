/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:28:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:22:19 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index.h"

int	ft_lstlen(t_stack *stack)
{
	int		i;
	t_stack	*first;

	if (stack == NULL)
		return (0);
	i = 1;
	first = stack;
	stack = stack->next;
	while (stack != first)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
