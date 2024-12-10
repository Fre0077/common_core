/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:36 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/10 21:04:18 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	ft_lstsize(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst->next == NULL)
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

void	ft_lstadd_front(t_stack *lst, t_stack *new)
{
	new->next = lst;
	lst = new;
}

void	ft_lstadd_back(t_stack *lst, t_stack *new)
{
	(ft_lstlast(lst))->next = new;
}

