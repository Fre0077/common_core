/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:45 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 14:51:30 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	rra(t_stack *a)
{
	t_stack	*temp;

	if (a == NULL || a->next == NULL)
	{
		ft_printf("lo stack a è lungo 1 o è vuoto\n");
		return ;
	}
	temp = ft_lstlast(a);
	temp->next = a;
	temp = a->next;
	a->next = NULL;
	a = temp;
}

void	rrb(t_stack *b)
{
	t_stack	*temp;

	if (b == NULL || b->next == NULL)
	{
		ft_printf("lo stack b è lungo 1 o è vuoto\n");
		return ;
	}
	temp = ft_lstlast(b);
	temp->next = b;
	temp = b->next;
	b->next = NULL;
	b = temp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
