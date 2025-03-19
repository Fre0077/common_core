/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:26:10 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/28 14:55:43 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	free_lst(t_stack *a)
{
	t_stack	*next;

	next = a->next;
	(a->prev)->next = NULL;
	while (next != NULL)
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

	if (ac < 2 || check_char(av))
		return (write(1, "Error\n", 6), 0);
	if (ac == 2)
		return (0);
	a = read_input(av);
	if (check_double(a))
		return (write(1, "Error\n", 6), free_lst(a), 0);
	best = ft_ncalloc(ft_lstlen(a) + 1);
	find_best(a, best);
	b = NULL;
	algoritmh(&a, &b, best);
	free(best);
	free_lst(a);
	return (0);
}
