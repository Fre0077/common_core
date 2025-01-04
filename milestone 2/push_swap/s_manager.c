/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:19 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/04 18:42:10 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

//trova il segmento di numeri ordinanato decrescente in a e lo restitiusce
t_stack	*find_segment(t_stack *a)
{
	int		len;
	int		max;
	t_stack	*check;
	t_stack	*segment;

	(a->previus)->next = NULL;
	max = 0;
	while (a->next != NULL)
	{
		len = -1;
		check = a;
		while (a->next != NULL && a->val == ((a->next)->val -1) && ++len >= 0)
			a = a->next;
		if (len >= max)
		{
			max = len;
			segment = check;
		}
		if (a->next != NULL)
			a = a->next;
	}
	ft_restore (a, 1);
	return (segment);
}

//imposta i valoridi a e b, inoltre mette a 0 si il need che il direct oltre mpostare il valore massimo
int	set_s(int s[7], t_stack *a)
{
	ft_printf("papere: %d\n", a->val);
	a = find_segment(a);
	s[4] = ft_lstsize(a);
	if (s[4] ==  1)
	{
		s[0] = 50;
		s[1] = 50;
	}
	else
	{
		s[0] = a->val;
		while (a->val == ((a->next)->val -1))
			a = a->next;
		s[1] = a->val;
	}
	s[2] = 0;
	s[3] = 0;
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
