/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:19 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/05 17:03:01 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

//trova il segmento di numeri ordinanato decrescente in a e lo restitiusce
void	find_segment(t_stack *a, int s[7])
{
	int	max;
	int	i;

	i = -1;
	while (i < s[4])
	{
		max = 0;
		while (a->val == ((a->next)->val -1))
		{
			a = a->next;
			i++;
			max++;
		}
		if (max == 0)
		{
			a = a->next;
			i++;
		}
		if (s[1] - s[0] < max)
		{
			s[1] = a->val;
			s[0] = s[1] - max;
		}
	}
}

//imposta i valoridi a e b, inoltre mette a 0 si il need che il direct oltre mpostare il valore massimo
int	set_s(int s[7], t_stack *a)
{
	s[0] = 0;
	s[1] = 0;
	s[2] = 0;
	s[3] = 0;
	s[4] = ft_lstsize(a);
	find_segment(a, s);
	if (s[0] == 0)
	{
		s[0] = s[4]/2;
		s[1] = s[4]/2;
	}
	s[5] = 0;
	s[6] = 0;
	return (0);
}

// aggiorna i valori del massimo e minimo di a e b
void	upgrade_s(t_stack *a, int s[7])
{
	while (a->val != s[0])
		a = a->next;
	while ((a->previus)->val == s[0] - 1)
	{
		a = a->previus;
		s[0] = a->val;
	}
	while (a->val != s[1])
		a = a->next;
	while ((a->next)->val == s[1] + 1)
	{
		a = a->next;
		s[1] = a->val;
	}
}
