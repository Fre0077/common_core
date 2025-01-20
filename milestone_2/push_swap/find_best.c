/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:07:00 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:19:05 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	check_best(long *current, long *best)
{
	int	i;

	i = 0;
	while (current[i] != 777777777777777)
		i++;
	if (best[i - 1] != 777777777777777)
	{
		while (--i > 0)
			current[i] = 777777777777777;
		return ;
	}
	while (--i >= 0)
	{
		best[i] = current[i];
		current[i] = 777777777777777;
	}
}

void	search_best(t_stack *a, long *best, long *current)
{
	int	i;

	i = 0;
	a = a->next;
	while (current[0] != a->nub)
	{
		if (a->nub > current[i])
		{
			if ((a->next)->nub > current[i] && (a->next)->nub < a->nub
				&& (a->next)->nub != current[0])
			{
				current[++i] = (a->next)->nub;
				a = a->next;
			}
			else
				current[++i] = a->nub;
		}
		a = a->next;
	}
	check_best(current, best);
}

void	find_best(t_stack *a, long *best)
{
	long	*current;
	int		len;
	int		i;

	current = ft_ncalloc(ft_lstlen(a) + 1);
	i = -1;
	len = ft_lstlen(a) + 1;
	while (len > ++i)
	{
		current[0] = a->nub;
		search_best(a, best, current);
		a = a->next;
	}
	free(current);
}
