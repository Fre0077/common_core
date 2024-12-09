/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:47 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 19:44:02 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a == NULL || a->next == NULL)
	{
		ft_printf("stack a non ha abbastanza elementi\n");
		return ;
	}
	temp = (a->next)->val;
	(a->next)->val = a->val;
	a->val = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b == NULL || b->next == NULL)
	{
		ft_printf("stack b non ha abbastanza elementi\n");
		return ;
	}
	temp = (b->next)->val;
	(b->next)->val = b->val;
	b->val = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
