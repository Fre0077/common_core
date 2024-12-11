/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:00 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 19:03:01 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

static void	switch_case(t_stack **a, t_stack **b)
{
	
}

void	algorithm(t_stack **a)
{
	t_stack	*b;
	long	reach;
	int		max;

	b = NULL;
	reach = 0;
	max = ft_lstsize(a);
	while ((max - reach) < 3)
	{
		switch_case(a, &b);
			// t_stack	*temp;
			// t_stack	*temp2;
			// temp = (*a);
			// temp2 = b;
			// while (temp != NULL)
			// {
			// 	ft_printf("%d ", temp->val);
			// 	temp = temp->next;
			// }
			// ft_printf(" |a\n");
			// while (temp2 != NULL)
			// {
			// 	ft_printf("%d ", temp2->val);
			// 	temp2 = temp2->next;
			// }
			// ft_printf(" |b\n");
			// ft_printf("ssv:%d  rrrv:%d   maxb:%d\n", ssv, rrrv, maxb);
			// ft_printf("\n");
	}
	while (b != NULL)
	{
		pa(a, &b);
	}
	t_stack	*temp;
	temp = (*a);
	while (temp != NULL)
	{
		ft_printf("%d ", temp->val);
		temp = temp->next;
	}
}
