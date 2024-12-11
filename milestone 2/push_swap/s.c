/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:28:47 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 15:37:06 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	sa(t_stack **a)
{
	long	temp;

	if ((*a) == NULL || (*a)->next == NULL)
	{
		ft_printf("sa fail\n");
		return ;
	}
	temp = ((*a)->next)->val;
	((*a)->next)->val = (*a)->val;
	(*a)->val = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	long	temp;

	if ((*b) == NULL || (*b)->next == NULL)
	{
		ft_printf("sb fail\n");
		return ;
	}
	temp = ((*b)->next)->val;
	((*b)->next)->val = (*b)->val;
	(*b)->val = temp;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
