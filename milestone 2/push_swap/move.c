/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:40:20 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/05 16:22:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

//cambia il direct quando incontra i valori di limite, verso il basso 0
void	direct(t_stack *a, int s[7])
{
	if ((a->next)->val == s[0] || a->val == s[0])
		s[6] = 1;
	else if ((a->previus)->val == s[1] || a->val == s[1])
		s[6] = 0;
}

//ti fa uscire nel modo più veloce possibile dal gap dei numeri già ordinati
void	way_out(t_stack **a, int s[7])
{
	if ((*a)->val > s[0] && (*a)->val < s[1])
	{
		if ((*a)->val - s[0] > s[1] - (*a)->val)
		{
			while (((*a)->previus)->val != s[1])
				ra(a);
		}
		else if ((*a)->val - s[0] < s[1] - (*a)->val)
		{
			while (((*a)->next)->val != s[1])
				rra(a);
		}
	}
}

void	move(t_stack **a, t_stack **b, int s[7])
{
	way_out(a, s);
	direct(*a, s);
	if (s[6] == 0)
	{
		if (s[5] == 1)
		{
			s[5] = 0;
			rr(a, b);
		}
		else
			ra(a);
	}
	else
		rra(a);
}
