/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:41 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 12:31:24 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*b) == NULL)
	{
		ft_printf("pa fail\n");
		return ;
	}
	temp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = temp;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*a) == NULL)
	{
		ft_printf("pb fail\n");
		return ;
	}
	temp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = temp;
	ft_printf("pb\n");
}
