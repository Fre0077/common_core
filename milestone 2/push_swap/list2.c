/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:16:03 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 19:22:04 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

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