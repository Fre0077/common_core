/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:36 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/04 11:01:33 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	ft_lstsize(t_stack *a)
{
	t_stack *first;
	int	i;

	if (!a)
		return (0);
	i = 1;
	first = a;
	a = a->next;
	while (a != first)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while ((lst->next)->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstcmp(t_input *a, t_input *b)
{
	int		i;

	i = -1;
	if (b == NULL)
		return (0);
	while ((a->val)[++i])
		if ((a->val)[i] != (b->val)[i])
			return (1);
	if ((b->val)[i] != '\0')
		return (1);
	return (0);
}

void	ft_lstdel(t_stack *a)
{
	t_stack	*temp;

	while (a != NULL)
	{
		temp = a->next;
		free (a);
		a = temp;
	}
}

void	ft_restore(t_stack * a, int way)
{
	if (way == 1)
	{
		while ((a->previus)->next != NULL)
			a = a->previus;
		(a->previus)->next = a;
	}
	else
	{
		while ((a->next)->previus != NULL)
			a = a->next;
		(a->next)->previus = a;
	}
}