/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:48:39 by fre007            #+#    #+#             */
/*   Updated: 2025/03/18 20:42:31 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer_bonus.h"

void	table_manage()
{
	
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
	if (table->many_filo < 0 || table->die_time < 0
		|| table->eat_time < 0 || table->sleep_time < 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	*pids;
	t_table	*table;

	if (ac != 5 && ac != 6)
		return (printf("E: too few arg...."), 0);
	if (init_table(table, av, ac))
		return (printf("wrong argoment\n"), 0);
	pids = malloc(sizeof(pid_t) * table->many_filo);
	i = -1;
	while (table->many_filo > 1 && ++i < table->many_filo)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			pthread_create(&table->gurdian, NULL, table_manage, (void *)table);
		}
	}
	msleep(50, table);
	pthread_create(&table->gurdian, NULL, death_checker, (void *)table);
	i = -1;
	while (++i < table->many_filo)
		pthread_join(table->thread[i], NULL);
	pthread_join(table->gurdian, NULL);
	return (free_all(table), 0);
}
