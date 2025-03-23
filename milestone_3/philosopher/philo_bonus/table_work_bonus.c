/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_work_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:22:42 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/21 15:54:22 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer_bonus.h"

//unlink e apre tutti i semafori necessari
void	init_sem(t_table *table)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/death_print");
	sem_unlink("/check");
	table->forks = sem_open("/forks", O_CREAT, 0666, (int)table->many_filo / 2);
	table->print = sem_open("/print", O_CREAT, 0666, 1);
	table->death = sem_open("/death", O_CREAT, 0666, 0);
	table->death_print = sem_open("/death_print", O_CREAT, 0666, 1);
	table->check = sem_open("/check", O_CREAT, 0666, 1);
}

//inizializza tutte le variabili della table
int	init_table(t_table *table, char **av, int ac)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	table->death_check = 1;
	table->many_eat = 0;
	table->n_eat = 0;
	table->last_eat = 0;
	table->start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	table->many_filo = ft_atoi(av[1]);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	init_sem(table);
	if (ac == 6)
		table->many_eat = ft_atoi(av[5]);
	if (table->many_filo < 0 || table->die_time < 0
		|| table->eat_time < 0 || table->sleep_time < 0)
		return (1);
	return (0);
}

//ripulisce table
void	free_all(t_table *table, pid_t *pids)
{
	sem_close(table->forks);
	sem_close(table->print);
	sem_close(table->death);
	sem_close(table->death_print);
	sem_close(table->check);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/death_print");
	sem_unlink("/check");
	free(pids);
	free(table);
}

//processo compiuto dai figli
void	child(t_table *table, pid_t *pids, int i)
{
	table->n_filo = i;
	pthread_create(&table->gurdian, NULL, death_checker, (void *)table);
	pthread_create(&table->stopper, NULL, the_snap, (void *)table);
	table_manager(table, i);
	pthread_join(table->stopper, NULL);
	pthread_join(table->gurdian, NULL);
	free_all(table, pids);
	exit(0);
}
