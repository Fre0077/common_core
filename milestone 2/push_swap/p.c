/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:41 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/05 14:35:47 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*b) == NULL)
		return (ft_printf("pa fail\n"), 0);
	if	((*a) == NULL)
	{
		temp = (*b);
		((*b)->next)->previus = (*b)->previus;
		((*b)->previus)->next = (*b)->next;
		(*b) = (*b)->next;
		temp->next = temp;
		temp->previus = temp;
		(*a) = temp;
		return (ft_printf("pa\n"), 0);
	}
	temp = (*b)->next;
	((*b)->next)->previus = (*b)->previus;
	((*b)->previus)->next = (*b)->next;
	(*b)->next = (*a);
	(*b)->previus = (*a)->previus;
	((*a)->previus)->next = (*b);
	(*a)->previus = (*b);
	(*a) = (*b);
	(*b) = temp;
	return (ft_printf("pa\n"), 0);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*a) == NULL)
		return (ft_printf("pb fail\n"), 0);
	if	((*b) == NULL)
	{
		temp = (*a);
		((*a)->next)->previus = (*a)->previus;
		((*a)->previus)->next = (*a)->next;
		(*a) = (*a)->next;
		temp->next = temp;
		temp->previus = temp;
		(*b) = temp;
		return (ft_printf("pb\n"), 0);
	}
	temp = (*a)->next;
	((*a)->next)->previus = (*a)->previus;
	((*a)->previus)->next = (*a)->next;
	(*a)->next = (*b);
	(*a)->previus = (*b)->previus;
	((*b)->previus)->next = (*a);
	(*b)->previus = (*a);
	(*b) = (*a);
	(*a) = temp;
	return (ft_printf("pb\n"), 0);
}
