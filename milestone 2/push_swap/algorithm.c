/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:00 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/04 19:41:02 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"


void check_print(t_stack *a, t_stack *b, int s[7])
{
	int size;
	int size2;
	ft_printf("------------------\n");
	ft_printf("low_a:       %d\nhigh_a:      %d\nlow_b:       %d\nhigh_b:      %d\nmax_value:   %d\npush_need:   %d\ndirect:      %d\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
	size = ft_lstsize(a);
	size2 = ft_lstsize(b);
	ft_printf("A:  ");
	while (size != 0 && a != NULL)
	{
		ft_printf(" %d", a->val);
		a = a->next;
		size--;
	}
	ft_printf("\nB:  ");
	while (size2 != 0)
	{
		ft_printf(" %d", b->val);
		b = b->next;
		size2--;
	}
	ft_printf("\n------------------\n");
}

//low_b è il numero più in basso

int	push_b(t_stack **a, t_stack **b, int s[7])
{
	if ((*a)->val == s[0] || (*a)->val == s[1])
		return (1);
	if (s[2] == 0)
		return (pb(a, b), s[3] = (*b)->val, s[2] = (*b)->val, 0);
	if (((*a)->val != s[3] + 1) && ((*a)->val != s[2] - 1))
		return (1);
	if (s[5] == 1)
	{
		s[3] = (*b)->val;
		rb(b);
		s[5] = 0;
	}
	if ((*a)->val == s[2] - 1)
		s[5] = 1;
	return (pb(a, b), s[3] = (*b)->val, 0);
}

int	switch_a(t_stack **a, int s[7])
{
	if ((*a)->val == s[0] || (*a)->val == s[1]
		|| ((*a)->next)->val == s[0] || ((*a)->previus)->val == s[1])
		return (1);
	if ((*a)->val > ((*a)->next)->val)
		return (sa(a), 0);
	return (1);
}

//array [low_a 0, high_a 1, low_b 2, high_b 3, max_value 4, push_need 5 , direct 6]

void	algorithm(t_stack **a)
{
	t_stack	*b;
	int		s[7];

	b = NULL;
	if (set_s(s, *a))
		return ;
	check_print(*a, b, s);
	ft_printf("\n\n");
	while ((*a)->val != s[0] || ((*a)->previus)->val != s[1])
	{
		if (push_b(a, &b, s))
			if (switch_a(a, s))
				move(a, &b, s);
		upgrade_s(*a, s);
		check_print(*a, b, s);
	}
	
}
