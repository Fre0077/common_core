/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:19 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/12 16:31:08 by fde-sant         ###   ########.fr       */
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
	while (a->next != NULL)
	{
		len = 0;
		check = a;
		while ((a->next)->val = ((a->next)->val + 1) && a->next != NULL)
		{
			len++;
			a = a->next;
		}
		if (len >= max)
		{
			max = len;
			segment = check;
		}
	}
	return (segment);
}

//imposta i valoridi a e b, inoltre mette a 0 si il need che il direct oltre mpostare il valore massimo
int	set_s(int **s, t_stack *a)
{
	a = find_segment(a);
	if (ft_listsize(a) ==  1)
	{
		s[0] = 50;
		s[1] = 50;
	}
	else
	{
		s[0] = a->val;
		while ((a->next)->val == a->val + 1)
			a = a->next;
		s[1] = a->val;
	}
	s[2] = 1;
	s[3] = 1;
	s[4] = ft_lstsize(a);
	s[5] = 0;
	s[6] = 0;
}

// aggiorna i valori del massimo e minimo di a e b
void	upgrade_s(int **s, t_stack *a, t_stack *b)
{
	a = find_segment(a);
	if (ft_listsize(a) ==  1)
	{
		s[0] = 50;
		s[1] = 50;
	}
	else
	{
		s[0] = a->val;
		while ((a->next)->val == a->val + 1)
			a = a->next;
		s[1] = a->val;
	}
	s[2] = b->val;
	s[3] = (b->previus)->val;
}
