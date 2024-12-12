/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:19 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/12 16:31:08 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

t_stack	*find_segment(t_stack *a)
{
	int		len;
	int		max;
	t_stack	*check;
	t_stack	*segment;

	(a->previus)->next = NULL;
	while (a->next != NULL)
	{
		len = 0;
		check = a;
		while ((a->next)->val = ((a->next)->val + 1) && a->next != NULL)
		{
			len++;
			a = a->next;
		}
		if (len >= max)
		{
			max = len;
			segment = check;
		}
	}
	return (segment);
}

int	set_s(int **s, t_stack *a, t_stack *b)
{
	s[2] = 1;
	s[3] = 1;
	s[4] = ft_lstsize(a);
	s[6] = 0;
	a = find_segment(a);
}

void	upgrade_s(int **s, t_stack *a, t_stack *b)
{
	
}