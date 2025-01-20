/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:25 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 11:41:04 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index.h"

static void	null_case(t_stack **a, t_stack **b)
{
	((*a)->next)->prev = (*a)->prev;
	((*a)->prev)->next = (*a)->next;
	(*b) = (*a);
	(*a) = (*a)->next;
	(*b)->next = (*b);
	(*b)->prev = (*b);
	write(1, "pb\n", 3);
}

static void	empty_case(t_stack **a, t_stack **b)
{
	(*a)->next = (*b);
	((*b)->prev)->next = (*a);
	(*a)->prev = (*b)->prev;
	(*b)->prev = (*a);
	(*b) = (*a);
	(*a) = NULL;
	write(1, "pb\n", 3);
}

int	pb(t_stack **a, t_stack **b)
{
	if ((*a) == NULL)
		return (0);
	if ((*b) == NULL)
		return (null_case(a, b), 0);
	if ((*a)->next == (*a))
		return (empty_case(a, b), 0);
	((*a)->prev)->next = (*a)->next;
	((*a)->next)->prev = (*a)->prev;
	(*a)->prev = (*b)->prev;
	(*b)->prev = (*a);
	(*b) = (*a);
	(*a) = (*b)->next;
	(*b)->next = ((*b)->prev)->next;
	((*b)->prev)->next = (*b);
	return (write(1, "pb\n", 3), 0);
}
