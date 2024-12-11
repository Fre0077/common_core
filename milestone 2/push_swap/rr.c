/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:45 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 16:01:56 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	rra(t_stack **a)
{
	t_stack	*temp;

	if ((*a) == NULL || (*a)->next == NULL)
	{
		ft_printf("rra fail\n");
		return ;
	}
	temp = ft_lstlast(*a);
	(temp->next)->next = (*a);
	(*a) = temp->next;
	temp->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*temp;

	if ((*b) == NULL || (*b)->next == NULL)
	{
		ft_printf("rrb fail\n");
		return ;
	}
	temp = ft_lstlast(*b);
	(temp->next)->next = (*b);
	(*b) = temp->next;
	temp->next = NULL;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
