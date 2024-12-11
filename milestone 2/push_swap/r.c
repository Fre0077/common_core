/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:43 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 16:11:46 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	ra(t_stack **a)
{
	t_stack	*temp;

	if ((*a) == NULL || (*a)->next == NULL)
	{
		ft_printf("ra fail\n");
		return ;
	}
	temp = ft_lstlast((*a));
	(temp->next)->next = (*a);
	temp = (*a)->next;
	(*a)->next = NULL;
	(*a) = temp;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*temp;

	if ((*b) == NULL || (*b)->next == NULL)
	{
		ft_printf("rb fail\n");
		return ;
	}
	temp = ft_lstlast(*b);
	(temp->next)->next = (*b);
	temp = (*b)->next;
	(*b)->next = NULL;
	(*b) = temp;
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
