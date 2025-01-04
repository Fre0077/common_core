/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:43 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/04 18:58:16 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	ra(t_stack **a)
{
	if ((*a) == NULL || (*a)->next == NULL)
	{
		ft_printf("ra fail\n");
		return ;
	}
	(*a) = (*a)->next;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
	{
		ft_printf("rb fail\n");
		return ;
	}
	(*b) = (*b)->next;
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
