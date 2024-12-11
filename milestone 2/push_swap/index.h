/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:34:07 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/11 21:49:35 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEX_H
# define INDEX_H
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_input
{
	char			*val;
	struct s_input	*next;
}	t_input;

typedef struct s_stack
{
	long			val;
	struct s_stack	*next;
	struct s_stack	*previus;
}	t_stack;

void	lst_clear_input(t_input *input);
t_input	*ft_lstnew_input(char *val);

void	ft_addnew_stack(long val, t_stack *next, t_stack *a);
void	lst_clear_stack(t_stack *input);
t_stack	*ft_lstnew_stack(long val);

t_input	*create_stack(char **av, int ac);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstdel(t_stack *a);
int		ft_lstsize(t_stack *a);
int		ft_lstcmp(t_input *a, t_input *b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_stack	*parsing(t_input *input);

void	algorithm(t_stack **a);

#endif