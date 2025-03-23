/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:49:24 by fre007            #+#    #+#             */
/*   Updated: 2025/03/21 12:29:36 by fde-sant         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_table
{
	sem_t		*forks;
	sem_t		*print;
	sem_t		*death;
	sem_t		*death_print;
	sem_t		*check;
	pthread_t	stopper;
	pthread_t	gurdian;
	long long	last_eat; //ultima mangiata
	long long	start; //tempo di partenza
	int			many_filo; //quanti filosofi
	int			n_filo; //numero del filosofo
	int			n_eat; //numero di volte che ha mangiato
	int			sleep_time; //tempo per dormire
	int			many_eat; //quante volte devono mangiare
	int			die_time; //tempo per morire
	int			eat_time; //tempo per magiare
	int			death_check;
}	t_table;

//=======================================================
//ft_atoi.c

int			ft_isdigit(int a);
int			ft_iswhitespace(char c);
int			ft_atoi(const char *str);
//=======================================================
//philosofer_bonus.c

void		*the_snap(void *temp);
void		*death_checker(void *temp);
void		eat(t_table *table, int i);
void		*table_manager(t_table *table, int i);
//=======================================================
//support_function_bonus.c

void		msleep(long long wait_time);
long long	actual_time(t_table *table);
void		death_print(char *str, t_table *table, int i);
void		safe_print(char *str, t_table *table, int i);
//=======================================================
//table_work_bonus.c

void		init_sem(t_table *table);
int			init_table(t_table *table, char **av, int ac);
void		free_all(t_table *table, pid_t *pids);
void		child(t_table *table, pid_t *pids, int i);
//=======================================================

#endif