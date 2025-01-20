/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:09:36 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:18:54 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	check_rr(int len, int i)
{
	if (i > len / 2)
		return (len - i);
	else
		return (i);
}

int	confront_cost(int *cost, int new_cost)
{
	if (*cost > new_cost || *cost == -1)
	{
		*cost = new_cost;
		return (1);
	}
	else
		return (0);
}

int	new_cost(t_stack *a, int i, int len_b, long nub)
{
	int		j;
	int		len_a;

	j = 0;
	len_a = ft_lstlen(a);
	while ((a->nub < nub || (a->prev)->nub > nub)
		&& !(nub < a->nub && nub < (a->prev)->nub && (a->prev)->nub > a->nub)
		&& !(nub > a->nub && nub > (a->prev)->nub && (a->prev)->nub > a->nub))
	{
		j++;
		a = a->next;
	}
	if ((j > len_a / 2 && i > len_b / 2) || (j < len_a / 2 && i < len_b / 2))
	{
		if (check_rr(len_a, j) > check_rr(len_b, i))
			return (check_rr(len_a, j));
		else
			return (check_rr(len_b, i));
	}
	return (check_rr(len_a, j) + check_rr(len_b, i));
}

long	find_cheapest(t_stack *a, t_stack *b)
{
	int		len_b;
	int		i;
	int		cost;
	long	cheap;

	i = -1;
	cost = -1;
	len_b = ft_lstlen(b);
	while (++i < len_b && cost != 0)
	{
		if (confront_cost(&cost, new_cost(a, i, len_b, b->nub)))
			cheap = b->nub;
		b = b->next;
	}
	return (cheap);
}
