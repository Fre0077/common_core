/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:49:24 by fre007            #+#    #+#             */
/*   Updated: 2025/03/18 20:35:44 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFER_BONUS_H
# define PHILOSOFER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h>

typedef struct s_table
{
	sem_t		*forks;
	sem_t		*print;
	sem_t		*death;
	pthread_t	stopper;
	pthread_t	gurdian;
	long long	last_eat; //ultima mangiata
	long long	start; //tempo di partenza
	int			many_filo; //quanti filosofi
	int			n_eat; //numero di volte che ha mangiato
	int			sleep_time; //tempo per dormire
	int			many_eat; //quante volte devono mangiare
	int			die_time; //tempo per morire
	int			eat_time; //tempo per magiare
}	t_table;

//ft_atoi.c
int			ft_isdigit(int a);
int			ft_iswhitespace(char c);
int			ft_atoi(const char *str);

#endif