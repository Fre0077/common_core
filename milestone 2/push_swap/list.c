/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:36 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 19:44:08 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->val = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack *ft_lstlast(t_stack *lst)
{
	while (lst->next == NULL)
		lst = lst->next;
	return (lst);
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

int	ft_lstsize(t_stack *a)
{
	int	i;

	while (a != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}
