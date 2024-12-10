/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:38:33 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/10 21:08:31 by fde-sant         ###   ########.fr       */
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
	a = ft_lstnew_stack(0);
	if (parsing(input, a) != 0)
		return (0);
	lst_clear_input(input);

	// Buona fortuna...
	
	lst_clear_stack(a);
	return (0);
}

	// t_stack	*temp;
	// temp = a;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d\n", temp->val);
	// 	temp = temp->next;
	// }