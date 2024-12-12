/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:00 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/12 15:59:14 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	algorithm(t_stack **a)
{
	t_stack	*b;
	int		s[7];

	b = NULL;
	if (set_s(s, *a, b))
		return ;
	while ((s[0] - s[3]) != 1 && ((s[0] - s[3]) != 1 || s[4] != s[1]))
	{
		if (switch_a(&a, s) && push_b(&a, &b, s))
			move(&a, &b, s);
		upgrade_s(s, *a, b);
	}
	
}

			// t_stack	*temp;
			// t_stack	*temp2;
			// temp = (*a);
			// temp2 = b;
			// while (temp != NULL)
			// {
			// 	ft_printf("%d ", temp->val);
			// 	temp = temp->next;
			// }
			// ft_printf(" |a\n");
			// while (temp2 != NULL)
			// {
			// 	ft_printf("%d ", temp2->val);
			// 	temp2 = temp2->next;
			// }
			// ft_printf(" |b\n");
			// ft_printf("ssv:%d  rrrv:%d   maxb:%d\n", ssv, rrrv, maxb);
			// ft_printf("\n");