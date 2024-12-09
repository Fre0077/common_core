/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:43 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 14:51:38 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	ra(t_stack *a)
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

void	rb(t_stack *b)
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

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
