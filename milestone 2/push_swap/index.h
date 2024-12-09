/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:34:07 by fde-sant          #+#    #+#             */
/*   Updated: 2024/12/09 19:47:26 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEX_H
# define INDEX_H
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_input
{
	char			*content;
	struct s_input	*next;
}	t_input;

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack *lst, t_stack *new);
void	ft_lstadd_front(t_stack *lst, t_stack *new);
void	ft_lstdel(t_stack *a);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		parsing(t_input *old);

#endif