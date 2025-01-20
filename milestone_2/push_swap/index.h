/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:26:21 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/20 16:08:20 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEX_H
# define INDEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int				ind;
	long			nub;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

typedef struct s_moving
{
	int		i;
	int		j;
	int		tipe_b;
	int		tipe_a;
}			t_moving;

long		ft_atoi(char *str);
char		*ft_calloc(int len);
void		free_lst(t_stack *a);
long		*ft_ncalloc(int len);
int			check_char(char **av);
t_stack		*read_input(char **av);
int			check_double(t_stack *a);
int			ft_lstlen(t_stack *stack);
char		**ft_split(char **s, char c);
void		find_best(t_stack *a, long *best);
long		find_cheapest(t_stack *a, t_stack *b);
void		move(t_stack **a, t_stack **b, t_moving tipe);
void		algoritmh(t_stack **a, t_stack **b, long *best);
t_moving	count_cheapest(t_stack *a, t_stack *b, long cheap);

int			pa(t_stack **a, t_stack **b);
int			pb(t_stack **a, t_stack **b);
int			ra(t_stack **a);
int			rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
int			rra(t_stack **a);
int			rrb(t_stack **b);
int			rrr(t_stack **a, t_stack **b);

#endif