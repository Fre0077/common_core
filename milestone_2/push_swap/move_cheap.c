/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:16:05 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:03:45 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	move_rr(t_stack **a, t_stack **b, int j, int i)
{
	int	now;

	j = ft_lstlen((*a)) - j;
	i = ft_lstlen((*b)) - i;
	if (i > j)
		now = j;
	else
		now = i;
	while (--now >= 0)
		rrr(a, b);
	if (i > j)
	{
		while ((i - j) - (++now) > 0)
			rrb(b);
	}
	else if (i < j)
		while ((j - i) - (++now) > 0)
			rra(a);
}

void	move_r(t_stack **a, t_stack **b, int j, int i)
{
	int	now;

	if (i > j)
		now = j;
	else
		now = i;
	while (--now >= 0)
		rr(a, b);
	if (i > j)
	{
		while ((i - j) - (++now) > 0)
			rb(b);
	}
	else if (i < j)
		while ((j - i) - (++now) > 0)
			ra(a);
}

void	move_casual(t_stack **stack, int (*fun)(t_stack **stack), int i)
{
	while (--i >= 0)
		fun(stack);
}

void	move(t_stack **a, t_stack **b, t_moving tipe)
{
	if (tipe.tipe_a == tipe.tipe_b)
	{
		if (tipe.tipe_a == 1)
			move_rr(a, b, tipe.j, tipe.i);
		if (tipe.tipe_a == 0)
			move_r(a, b, tipe.j, tipe.i);
		return ;
	}
	if (tipe.tipe_a == 0 && tipe.j != 0)
		move_casual(a, &ra, tipe.j);
	if (tipe.tipe_b == 0 && tipe.i != 0)
		move_casual(b, &rb, tipe.i);
	if (tipe.tipe_a == 1 && tipe.j != 0)
		move_casual(a, &rra, ft_lstlen((*a)) - tipe.j);
	if (tipe.tipe_b == 1 && tipe.i != 0)
		move_casual(b, &rrb, ft_lstlen((*b)) - tipe.i);
}

t_moving	count_cheapest(t_stack *a, t_stack *b, long nub)
{
	t_moving	tipe;

	tipe.i = 0;
	while (b->nub != nub)
	{
		b = b->next;
		tipe.i++;
	}
	tipe.j = 0;
	while ((a->nub < nub || (a->prev)->nub > nub)
		&& !(nub < a->nub && nub < (a->prev)->nub && (a->prev)->nub > a->nub)
		&& !(nub > a->nub && nub > (a->prev)->nub && (a->prev)->nub > a->nub))
	{
		a = a->next;
		tipe.j++;
	}
	if (tipe.i > ft_lstlen(b) / 2)
		tipe.tipe_b = 1;
	else
		tipe.tipe_b = 0;
	if (tipe.j > ft_lstlen(a) / 2)
		tipe.tipe_a = 1;
	else
		tipe.tipe_a = 0;
	return (tipe);
}
