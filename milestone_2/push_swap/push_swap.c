/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:26:10 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:35:57 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"
//mettere apposto la lis, il cheker_input e il caos dei 3 e 5
void	free_lst(t_stack *a)
{
	int		len;
	t_stack	*next;

	len = ft_lstlen(a);
	while (--len >= 0)
	{
		next = a->next;
		free(a);
		a = next;
	}
}

int	main(int ac, char **av)
{
	long	*best;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2/*  || check_input(av) */)
		return (0);
	a = read_input(av);
	best = ft_ncalloc(ft_lstlen(a) + 1);
	find_best(a, best);
	b = NULL;
	algoritmh(&a, &b, best);
	free(best);
	free_lst(a);
	return (0);
}
