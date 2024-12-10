/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:16:03 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/10 21:04:06 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

t_input	*ft_lstnew_input(char *val)
{
	t_input	*new_node;

	new_node = malloc(sizeof(t_input));
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstnew_stack(long val)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void	lst_clear_input(t_input *input)
{
	t_input	*temp;

	while (input != NULL)
	{
		temp = input->next;
		free (input->val);
		free (input);
		input = temp;
	}
}

void	lst_clear_stack(t_stack *input)
{
	t_stack	*temp;

	while (input != NULL)
	{
		temp = input->next;
		free (input);
		input = temp;
	}
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
