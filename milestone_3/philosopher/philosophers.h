/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:37 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/27 11:11:45 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_table
{
	pthread_mutex_t	*mutex; //i mutex(forchetta)
	pthread_t		*thread; //il thead(filosofo)
	int				*n_eat; //numero di volte che ha mangiato
	int				n_filo; //numero del filosofo in funzione
	int				many_filo; //quanti filosofi
	int				die_time; //tempo per morire
	int				eat_time; //tempo per magiare
	int				sleep_time; //tempo per dormire
	int				many_eat; //quante volte devono mangiare
}	t_table;

int	ft_atoi(const char *str);

#endif