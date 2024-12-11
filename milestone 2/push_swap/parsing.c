/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:23:03 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 22:33:49 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

static int	ft_isdigit_im(t_input *input)
{
	int	i;

	if (input == NULL)
		return (0);
	i = 0;
	if (((input->val)[i] < '0' || (input->val)[i] > '9') &&
		(input->val)[i] != '-' && (input->val)[i] != '+')
		return (0);
	while ((input->val)[++i])
		if ((input->val)[i] < '0' || (input->val)[i] > '9')
			return (0);
	return (1);
}

static int	check(t_input *input)
{
	t_input	*temp;

	while (ft_isdigit_im(input))
	{
		temp = input->next;
		while (ft_lstcmp(input, temp))
			temp = temp->next;
		if (temp != NULL)
			return (1);
		input = input->next;
	}
	if (input != NULL)
		return (1);
	return (0);
}

static void	numering(t_stack *a, int len)
{
	t_stack	*temp;
	t_stack	*low;
	long		max;
	int		i;

	i = -1;
	(a->previus)->next = NULL;
	while (len > ++i)
	{
		temp = a;
		max = 2147483647;
		while (temp != NULL)
		{
			if (temp->val <= max && temp->val >= (-2147483648 + i))
			{
				low = temp;
				max = low->val;
			}
			temp = temp->next;
		}
		low->val = (-2147483648 + i);
	}
	(a->previus)->next = a;
}

static void	set(t_stack *a)
{
	t_stack	*stop;

	stop = a->previus;
	while (a != stop)
	{
		a->val += 2147483649;
		a = a->next;
	}
	a->val += 2147483649;
}

t_stack	*parsing(t_input *input)
{
	t_stack	*a;
	t_stack	*save;

	if (check(input))
		return (write(2, "Error\n", 6), NULL);
	a = ft_lstnew_stack(atoi(input->val));
	save = a;
	if (a->val < -2147483648 || a->val > 2147483647)
			return (write(2, "Error\n", 6), lst_clear_stack(a), NULL);
	input = input->next;
	while (input != NULL)
	{
		ft_addnew_stack(atoi(input->val), save, a);
		if (a->val < -2147483648 || a->val > 2147483647)
			return (write(2, "Error\n", 6), lst_clear_stack(a), NULL);
		input = input->next;
		a = a->next;
	}
	a = a->next;
	numering(a, ft_lstsize(a));
	return (set(a), a);
}
