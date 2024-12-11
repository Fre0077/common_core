/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:38:33 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 22:38:46 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

int	main(int ac, char **av)
{
	t_input	*input;
	t_stack	*a;

	if (ac < 2)
		return (0);
	input = create_stack(av, ac);
	if (input == NULL)
		return (0);
	a = parsing(input);
	if (a == NULL)
		return (0);
	lst_clear_input(input);


	
	t_stack	*temp;
	temp = a;
	(a->previus)->next = NULL;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->val);
		temp = temp->next;
	}
	(a->previus)->next = a;
	ft_printf("\n-----------\n");


	
	// Vecchio ho fatto il possibile oggi, buona fortuna per domani...


	
	lst_clear_stack(a);
	return (0);
}
