/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:03:19 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/14 23:56:18 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index.h"

int	rrr(t_stack **a, t_stack **b)
{
	if ((*a)->next == (*a) || (*b)->next == (*b))
		return (0);
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
	return (write(1, "rrr\n", 4), 0);
}
