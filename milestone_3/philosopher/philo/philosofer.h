/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:37 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/20 12:18:15 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFER_H
# define PHILOSOFER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table
{
	pthread_mutex_t	*mutex; //mutex(forchetta)
	pthread_mutex_t	death_mutex; //mutex for death
	pthread_mutex_t	death_cond_mutex; //mutex per le variabili della death
	pthread_mutex_t	death_print_mutex; //mutex per il print della death
	pthread_mutex_t	print_mutex; //mutex per il print
	pthread_mutex_t	n_filo_mutex; //mutex per n_filo
	pthread_t		*thread; //theads(filosofi)
	pthread_t		gurdian; //guardiano per la morte
	int				*n_eat; //numero di volte che ha mangiato
	long long		*last_eat; //ultima mangiata
	long long		start; //tempo di partenza
	int				n_filo; //numero del filosofo attuale
	int				many_filo; //quanti filosofi in totale
	int				die_time; //tempo per morire
	int				eat_time; //tempo per magiare
	int				sleep_time; //tempo per dormire
	int				many_eat; //quante volte devono mangiare
	int				death; //check per la morte
}	t_table;

//===============================================
//ft_atoi.c

int			ft_isdigit(int a);
int			ft_iswhitespace(char c);
int			ft_atoi(const char *str);
//===============================================
//philosofer.c

void		*death_checker(void *temp);
void		eat(t_table *table, int i);
void		*table_manage(void *temp);
//===============================================
//support_function.c

void		msleep(long long wait_time, t_table *table);
long long	actual_time(t_table *table);
void		death_print(char *str, t_table *table, int i);
void		safe_print(char *str, t_table *table, int i);
//===============================================
//table_work.c

void		init_mutex(t_table *table);
void		init_table(t_table *table, char **av, int ac);
void		free_all(t_table *table);
//===============================================

#endif