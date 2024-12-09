/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:23:03 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 19:47:05 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

static int	ft_isdigit(char	*a)
{
	int	i;

	if (a == NULL)
		return (0);
	i = -1;
	while (a[++i])
		if (a[i] < '0' || a[i] > '9')
			return (0);
	return (1);
}

static int	check(t_input *a, t_stack **new)
{
	t_input	*temp;
	t_stack	*save;

	save = (*new);
	while (ft_isdigit(a->content))
	{
		temp = a->next;
		while (ft_strcmp(a->content, temp->content))
			temp = temp->next;
		if (temp != NULL)
			return (ft_lstdel(save), 0);
		(*new)->next = ft_lstnew(ft_atoi(a->content));
		(*new) = (*new)->next;
		a = a->next;
	}
	if (a != NULL)
		return (ft_lstdel(save), 0);
	(*new) = save->next;
	free (save);
	return (1);
}

static void	set(t_stack *a)
{
	while (a != NULL)
	{
		a->val += 2147483649;
		a = a->next;
	}
}

int	parsing(t_input *old)
{
	t_stack	*a;
	t_stack	*temp;
	t_stack	*low;
	int		i;
	int		len;

	a = ft_lstnew(0);
	if (check(old, &a) == 0)
		return (ft_printf("stack di input non valido"));
	len = ft_lstsize(a);
	low = a;
	i = -1;
	while (len > ++i)
	{
		temp = a;
		while (temp != NULL)
		{
			if (temp->val < low->val && temp->val >= (-2147483648 + i))
				low = temp;
			temp = temp->next;
		}
		low->val = (-2147483648 + i);
	}
	return (set(a), 0);
}
