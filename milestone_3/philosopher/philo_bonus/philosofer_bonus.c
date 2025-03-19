/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:48:39 by fre007            #+#    #+#             */
/*   Updated: 2025/03/19 11:45:33 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer_bonus.h"

void	the_snap(void *temp)
{
	t_table	*table;
	int		i;

	table = (t_table *)temp;
	sem_wait(table->death);
	free(table);
	exit (0);
}

void	death_checker(void *temp)
{
	t_table		*table;
	long long	time;

	table = (t_table *)temp;
	while (1)
	{
		msleep (1000, table);
		time = actual_time(table);
		if (table->n_eat == table->many_eat)
			return (NULL);
		sem_wait(table->check);
		if (time - table->last_eat > table->die_time)
		{
			sem_post(table->check);
			safe_print("%lld %d died\n", table, table->n_filo);
			multi_post(table->death, table->many_filo);
			return (NULL);
		}
		sem_post(table->check);
	}
}

void	eat(t_table *table, int i)
{
	safe_print("%lld %d is thinking\n", table, i);
	msleep(1000, table);
	sem_wait(table->forks);
	sem_wait(table->check);
	table->last_eat = actual_time(table);
	table->n_eat += 1;
	sem_post(table->check);
	safe_print("%lld %d is eating\n", table, i);
	msleep(table->eat_time * 1000, table);
	sem_post(table->forks);
	safe_print("%lld %d is sleeping\n", table, i);
	msleep((table->sleep_time * 1000) + 100, table);
}

void	*table_manage(t_table *table, int i)
{
	while (1)
	{
		sem_wait(table->check);
		if (table->many_eat && table->n_eat == table->many_eat)
			return (sem_post(table->check), NULL);
		sem_post(table->check);
		eat(table, i);
	}
	return (NULL);
}

int	init_table(t_table *table, char **av, int ac)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	table->many_eat = 0;
	table->n_eat = 0;
	table->last_eat = 0;
	table->start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	table->many_filo = ft_atoi(av[1]);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		table->many_eat = ft_atoi(av[5]);
	table->forks = sem_open("/forks", O_CREAT, 0666, table->many_filo / 2);
	table->print = sem_open("/print", O_CREAT, 0666, 1);
	table->death = sem_open("/death", O_CREAT, 0666, 0);
	table->death = sem_open("/check", O_CREAT, 0666, 1);
	if (table->many_filo < 0 || table->die_time < 0
		|| table->eat_time < 0 || table->sleep_time < 0)
		return (1);
	return (0);
}

void	free_all(t_table *table)
{
	sem_unlink("/forks");
	sem_close(table->forks);
	sem_unlink("/print");
	sem_close(table->print);
	sem_unlink("/death");
	sem_close(table->death);
	sem_unlink("/check");
	sem_close(table->check);
	free(table);
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
		{
			table_manager(table, i);
			table->n_filo = i;
			pthread_create(&table->gurdian, NULL, death_checker, (void *)table);
			pthread_create(&table->stopper, NULL, the_snap, (void *)table);
		}
	}
	i = -1;
	while (table->many_filo > 1 && ++i < table->many_filo)
		waitpid(pids[i], status, 0);
	return (free_all(table), 0);
}
