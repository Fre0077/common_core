/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:13:14 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/20 16:11:53 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	check_char(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i] != NULL)
	{
		j = -1;
		while (av[i][++j])
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
				return (1);
	}
	return (0);
}

int	scroll_lst(t_stack *a, int nub)
{
	a = a->next;
	while (a != NULL)
	{
		if (nub == a->nub)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_double(t_stack *a)
{
	t_stack *first;

	first = a;
	(first->prev)->next = first;
	while (a != NULL)
	{
		if (scroll_lst(a, a->nub))
			return (1);
		a = a->next;
	}
	(first->prev)->next = first;
	return (0);
}
