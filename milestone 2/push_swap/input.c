/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:39:14 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 21:51:16 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

static void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i + 1] != NULL)
		free (array[i]);
	free (array);
}

static void	set_node(t_input **input, char *str)
{
	char	**array;
	int		i;

	array = ft_split(str, ' ');
	i = -1;
	while (array[++i])
	{
		(*input)->next = ft_lstnew_input(array[i]);
		(*input) = (*input)->next;
	}
	free_array(array);
}

static int	check_empty(char **av)
{
	int	i;

	i = 0;
	while (av[++i] != NULL)
		if (av[i][0] == '\0')
			return (1);
	return (0);
}

t_input	*create_stack(char **av, int ac)
{
	t_input	*input;
	t_input	*save;
	char	**array;
	int		i;

	if (check_empty(av))
		return (write(2, "Error\n", 6), NULL);
	array = ft_split(av[1], ' ');
	i = 0;
	input = ft_lstnew_input(array[i]);
	save = input;
	while (array[++i] != NULL)
	{
		input->next = ft_lstnew_input(array[i]);
		input = input->next;
	}
	free_array(array);
	i = 1;
	while (++i < ac)
		set_node(&input, av[i]);
	return (save);
}
