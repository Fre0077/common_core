/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:37 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/04 16:55:11 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table
{
	pthread_mutex_t	*mutex; //i mutex(forchetta)
	pthread_mutex_t	death_mutex; //mutex for death
	pthread_mutex_t	print_mutex;
	pthread_t		*thread; //il thead(filosofo)
	pthread_t		gurdian; //guardiano assoluto
	int				*n_eat; //numero di volte che ha mangiato
	long long		*last_eat; //ultima mangiata
	long long		start; //tempo di partenza
	int				n_filo; //numero del filosofo in funzione
	int				many_filo; //quanti filosofi
	int				die_time; //tempo per morire
	int				eat_time; //tempo per magiare
	int				sleep_time; //tempo per dormire
	int				many_eat; //quante volte devono mangiare
	int				death; //check for death
}	t_table;

int	ft_atoi(const char *str);

#endif