/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:51:45 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/15 15:20:15 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

t_stack	*new_node(long nub)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->nub = nub;
	return (new);
}

void	add_node(t_stack *a, long nub, t_stack *first)
{
	a->next = new_node(nub);
	first->prev = a->next;
	(a->next)->prev = a;
	a = a->next;
	a->next = first;
}

t_stack	*read_input(char **av)
{
	t_stack	*first;
	t_stack	*a;
	int		i;
	char	**splitted;

	a = malloc(sizeof(t_stack));
	a->prev = a;
	a->next = a;
	a->ind = 1;
	first = a;
	i = 0;
	splitted = ft_split(av, ' ');
	a->nub = ft_atoi(splitted[0]);
	free(splitted[0]);
	while (splitted[++i] != NULL)
	{
		add_node(a, ft_atoi(splitted[i]), first);
		free(splitted[i]);
		a = a->next;
		a->ind = i + 1;
	}
	free(splitted);
	return (first);
}
