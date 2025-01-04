/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:45 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/04 18:58:06 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	rra(t_stack **a)
{
	if ((*a) == NULL || (*a)->next == NULL)
	{
		ft_printf("rra fail\n");
		return ;
	}
	(*a) = (*a)->previus;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
	{
		ft_printf("rrb fail\n");
		return ;
	}
	(*b) = (*b)->previus;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
