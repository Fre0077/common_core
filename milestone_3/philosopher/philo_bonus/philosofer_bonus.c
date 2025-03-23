/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:48:39 by fre007            #+#    #+#             */
/*   Updated: 2025/03/22 10:06:27 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer_bonus.h"

//cambia il volore della variabile death in tutti i figli
void	*the_snap(void *temp)
{
	t_table	*table;

	table = (t_table *)temp;
	sem_wait(table->death);
	if (table->many_eat)
	{
		sem_wait(table->check);
		if (table->many_eat == table->n_eat)
			return (sem_post(table->check), NULL);
		sem_post(table->check);
	}
	sem_post(table->death);
	sem_wait(table->check);
	table->death_check = 0;
	sem_post(table->check);
	return (NULL);
}

//controlla la morte del filosofo nel figlio
void	*death_checker(void *temp)
{
	t_table		*table;
	long long	time;

	table = (t_table *)temp;
	while (1)
	{
		sem_wait(table->check);
		if (!table->death_check)
			return (sem_post(table->check), NULL);
		sem_post(table->check);
		msleep (1000);
		time = actual_time(table);
		sem_wait(table->check);
		if (table->many_eat && table->n_eat == table->many_eat)
			return (sem_post(table->check), sem_post(table->death), NULL);
		if (time - table->last_eat > table->die_time && table->death_check)
		{
			sem_post(table->death);
			sem_post(table->check);
			sem_wait(table->death_print);
			death_print("%lld %d died\n", table, table->n_filo);
			return (msleep (10000), sem_post(table->death_print), NULL);
		}
		sem_post(table->check);
	}
}

//azioni compiute per mangiare dai filosofi
void	eat(t_table *table, int i)
{
	sem_wait(table->forks);
	safe_print("%lld %d has taken a fork\n", table, i);
	safe_print("%lld %d has taken a fork\n", table, i);
	sem_wait(table->check);
	table->last_eat = actual_time(table);
	table->n_eat += 1;
	sem_post(table->check);
	safe_print("%lld %d is eating\n", table, i);
	msleep(table->eat_time * 1000);
	sem_post(table->forks);
}

//gestiosce la routine di tutti i filosofi
void	*table_manager(t_table *table, int i)
{
	while (1)
	{
		sem_wait(table->check);
		if (table->many_eat && table->n_eat == table->many_eat)
			return (sem_post(table->check), NULL);
		sem_post(table->check);
		safe_print("%lld %d is thinking\n", table, i);
		eat(table, i);
		safe_print("%lld %d is sleeping\n", table, i);
		msleep((table->sleep_time * 1000));
		sem_wait(table->check);
		if (!table->death_check)
			return (sem_post(table->check), NULL);
		sem_post(table->check);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int		i;
	int		status;
	pid_t	*pids;
	t_table	*table;

	if (ac != 5 && ac != 6)
		return (printf("E: too few arg...."), 0);
	table = malloc(sizeof(t_table));
	if (init_table(table, av, ac))
		return (printf("wrong argoment\n"), 0);
	pids = malloc(sizeof(pid_t) * table->many_filo);
	i = -1;
	while (table->many_filo > 1 && ++i < table->many_filo)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			child(table, pids, i);
		msleep(50);
	}
	i = -1;
	while (table->many_filo > 1 && ++i < table->many_filo)
		waitpid(pids[i], &status, 0);
	return (free_all(table, pids), 0);
}
