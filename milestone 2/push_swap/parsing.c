/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:23:03 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/10 21:04:57 by fde-sant         ###   ########.fr       */
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

static int	check(t_input *input, t_stack *a)
{
	t_input	*temp;
	t_stack	*save;

	save = a;
	while (ft_isdigit_im(input))
	{
		temp = input->next;
		while (ft_lstcmp(input, temp))
			temp = temp->next;
		if (temp != NULL)
			return (ft_lstdel(save), 0);
		a->val = ft_atoi(input->val);
		if (a->val < -2147483648 || 2147483647 < a->val)
			return (ft_lstdel(save), 0);
		a->next = ft_lstnew_stack(0);
		input = input->next;
		if (input != NULL)
			a = a->next;
	}
	if (input != NULL)
		return (ft_lstdel(save), 0);
	return (free (a->next), a->next = NULL, 1);
}

static void	set(t_stack *a)
{
	while (a != NULL)
	{
		a->val += 2147483649;
		a = a->next;
	}
}

int	parsing(t_input *input, t_stack *a)
{
	t_stack	*temp;
	t_stack	*low;
	int		max;
	int		i;
	int		len;

	if (check(input, a) == 0)
		return (write(2, "Error\n", 6));
	len = ft_lstsize(a);
	i = -1;
	while (len > ++i)
	{
		temp = a;
		max = 2147483647;
		while (temp != NULL)
		{
			if (temp->val <= max && temp->val >= (-2147483648 + i))
				low = temp;
			if (temp->val <= max && temp->val >= (-2147483648 + i))
				max = low->val;
			temp = temp->next;
		}
		low->val = (-2147483648 + i);
	}
	return (set(a), 0);
}
