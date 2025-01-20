/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:38 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:20:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index.h"

static void	null_case(t_stack **a, t_stack **b)
{
	((*b)->next)->prev = (*b)->prev;
	((*b)->prev)->next = (*b)->next;
	(*a) = (*b);
	(*b) = (*b)->next;
	(*a)->next = (*a);
	(*a)->prev = (*a);
	write(1, "pa\n", 3);
}

static void	empty_case(t_stack **a, t_stack **b)
{
	(*b)->next = (*a);
	((*a)->prev)->next = (*b);
	(*b)->prev = (*a)->prev;
	(*a)->prev = (*b);
	(*a) = (*b);
	(*b) = NULL;
	write(1, "pa\n", 3);
}

int	pa(t_stack **a, t_stack **b)
{
	if ((*b) == NULL)
		return (0);
	if ((*a) == NULL)
		return (null_case(a, b), 0);
	if ((*b)->next == (*b))
		return (empty_case(a, b), 0);
	((*b)->prev)->next = (*b)->next;
	((*b)->next)->prev = (*b)->prev;
	(*b)->prev = (*a)->prev;
	(*a)->prev = (*b);
	(*a) = (*b);
	(*b) = (*a)->next;
	(*a)->next = ((*a)->prev)->next;
	((*a)->prev)->next = (*a);
	return (write(1, "pa\n", 3), 0);
}
