/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:16:03 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 22:35:18 by fde-sant         ###   ########.fr       */
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
	new_node->next = new_node;
	new_node->previus = new_node;
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

	(input->previus)->next = NULL;
	while (input != NULL)
	{
		temp = input->next;
		free (input);
		input = temp;
	}
}

void	ft_addnew_stack(long val, t_stack *next, t_stack *previus)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->val = val;
	new_node->next = next;
	new_node->previus = previus;
	next->previus = new_node;
	previus->next = new_node;
}