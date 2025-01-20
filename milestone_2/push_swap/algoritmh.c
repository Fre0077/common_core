/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:11:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 14:40:11 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	find_in_arr(long *best, long nub)
{
	int	i;

	i = -1;
	while (best[++i] != 777777777777777)
		if (nub == best[i])
			return (0);
	return (1);
}

int	push_need(t_stack *a, long *best)
{
	int	len;

	len = ft_lstlen(a);
	while (len-- > 0)
	{
		if (find_in_arr(best, a->nub))
			return (1);
		a = a->next;
	}
	return (0);
}

void	push_in_b(t_stack **a, t_stack **b, long *best)
{
	while (push_need(*a, best))
	{
		if (find_in_arr(best, (*a)->nub))
			pb(a, b);
		else
			ra(a);
	}
}

void	critical_hit(t_stack **a)
{
	int		i;
	t_stack	*first;

	i = 0;
	first = (*a);
	while (!((first->prev)->nub > first->nub))
	{
		first = first->next;
		i++;
	}
	if (i > ft_lstlen((*a)) / 2)
	{
		i = ft_lstlen((*a)) - i;
		while (--i >= 0)
			rra(a);
	}
	else
		while (--i >= 0)
			ra(a);
}

void	algoritmh(t_stack **a, t_stack **b, long *best)
{
	long		cheap;
	t_moving	tipe;

	push_in_b(a, b, best);
	while ((*b) != NULL)
	{
		cheap = find_cheapest((*a), (*b));
		tipe = count_cheapest((*a), (*b), cheap);
		move(a, b, tipe);
		pa(a, b);
	}
	critical_hit(a);
}
